/*
   Compile elf_mod.c like this;

        gcc -g -O2 -o elf_mod elf_mod.c -lelf

    (You should have libelf, but might have to install it.)

    Then compile the program t1.c:

        gcc -g -O2 -c t1.c

    This produces t1.o. Look at t1.c -- it shouldn't run because bar() isn't
defined.

    Try to link it:

        gcc -o t1 t1.o

    It should fail.

    Now lets rename foo() to bar().

        ./elf_mod -v -e foo bar t1.o t2.o

    You should now have both t1.o and t2.o.

    Lets link t2:

        gcc -o t2 t2.o

    It should link successfully. (The rename worked!)

    Now run it:

$ ./t2
Rename example.
Calling function bar()
This is function foo
End of run

    The format of the command is ./elf_mod -d old new -e old new old.o new.o

    It doesn't modify the old .o file, but it makes a new one. This only works
on .o not .so, .a, etc.

    -e renames references to externals.

    -d rename references to symbols defined within the .o

    You may use -e and -d many times on the command line for a single pass.

*/

#include <fcntl.h>
#include <gelf.h>
#include <libelf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Rename {
  char *old_name;
  char *new_name;
  struct Rename *next;
} Rename;

Rename *def_list = NULL, *ext_list = NULL;
int verbose = 0;

void add_rename(Rename **list, char *old_n, char *new_n) {
  Rename *node = malloc(sizeof(Rename));
  node->old_name = old_n;
  node->new_name = new_n;
  node->next = *list;
  *list = node;
}

const char *get_replacement(Rename *list, const char *name) {
  for (; list; list = list->next)
    if (strcmp(list->old_name, name) == 0)
      return list->new_name;
  return NULL;
}

void process_elf(const char *in_path, const char *out_path) {
  int in_fd = open(in_path, O_RDONLY);
  if (in_fd < 0) {
    perror("open input");
    exit(1);
  }

  elf_version(EV_CURRENT);
  Elf *elf_in = elf_begin(in_fd, ELF_C_READ, NULL);

  // Create output file as a copy of input first to preserve all offsets
  int out_fd = open(out_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
  char buf[8192];
  ssize_t n;
  lseek(in_fd, 0, SEEK_SET);
  while ((n = read(in_fd, buf, sizeof(buf))) > 0)
    write(out_fd, buf, n);

  Elf *elf_out = elf_begin(out_fd, ELF_C_RDWR, NULL);
  Elf_Scn *scn = NULL;

  while ((scn = elf_nextscn(elf_out, scn)) != NULL) {
    GElf_Shdr shdr;
    gelf_getshdr(scn, &shdr);

    if (shdr.sh_type == SHT_SYMTAB) {
      Elf_Data *data = elf_getdata(scn, NULL);
      int str_idx = shdr.sh_link;
      Elf_Scn *str_scn = elf_getscn(elf_out, str_idx);
      Elf_Data *str_data = elf_getdata(str_scn, NULL);

      // Create a new string table buffer
      size_t new_str_size = str_data->d_size + 16384;
      char *new_strs = malloc(new_str_size);
      memcpy(new_strs, str_data->d_buf, str_data->d_size);
      size_t str_ptr = str_data->d_size;

      int count = shdr.sh_size / shdr.sh_entsize;
      for (int i = 0; i < count; i++) {
        GElf_Sym sym;
        gelf_getsym(data, i, &sym);

        if (sym.st_name != 0) {
          char *name = (char *)str_data->d_buf + sym.st_name;
          const char *rep = NULL;

          if (sym.st_shndx == SHN_UNDEF)
            rep = get_replacement(ext_list, name);
          else if (GELF_ST_BIND(sym.st_info) == STB_GLOBAL ||
                   GELF_ST_BIND(sym.st_info) == STB_WEAK)
            rep = get_replacement(def_list, name);

          if (rep) {
            if (verbose)
              printf("Renaming: %s -> %s\n", name, rep);
            sym.st_name = (uint32_t)str_ptr;
            strcpy(new_strs + str_ptr, rep);
            str_ptr += strlen(rep) + 1;
            gelf_update_sym(data, i, &sym);
          }
        }
      }

      // Assign the rebuilt string table
      str_data->d_buf = new_strs;
      str_data->d_size = str_ptr;

      GElf_Shdr str_shdr;
      gelf_getshdr(str_scn, &str_shdr);
      str_shdr.sh_size = str_ptr;
      gelf_update_shdr(str_scn, &str_shdr);
    }
  }

  elf_flagelf(elf_out, ELF_C_SET, ELF_F_DIRTY);
  elf_update(elf_out, ELF_C_WRITE);

  elf_end(elf_in);
  elf_end(elf_out);
  close(in_fd);
  close(out_fd);
}

int main(int argc, char **argv) {
  int opt;
  while ((opt = getopt(argc, argv, "e:d:v")) != -1) {
    if (opt == 'v')
      verbose = 1;
    else if (opt == 'e') {
      if (optind < argc)
        add_rename(&ext_list, optarg, argv[optind++]);
    } else if (opt == 'd') {
      if (optind < argc)
        add_rename(&def_list, optarg, argv[optind++]);
    }
  }

  if (argc - optind < 2) {
    fprintf(stderr, "Usage: %s [-v] [-e old new] [-d old new] in.o out.o\n",
            argv[0]);
    return 1;
  }

  process_elf(argv[optind], argv[optind + 1]);
  return 0;
}
