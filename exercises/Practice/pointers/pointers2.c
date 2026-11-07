#include <stdio.h>

int main() {
  int num = 30;
  int *Pnum = &num;

  printf("%d\n", num);
  printf("%p\n", &num);
  printf("%p\n", Pnum);
  printf("%d\n", *Pnum);

  *Pnum = 35;

  printf("%d\n", *Pnum);

  return 0;
}
