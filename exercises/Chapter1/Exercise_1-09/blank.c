/**
 * Copy input to output, replacing each string of one or more blanks with a
 * single blank.
 */
#include <stdio.h>

int main(void) {
  int gc = 0;
  int sc = 0;

  while ((gc = getchar()) != EOF) {
    if (gc != ' ') {
      sc = 0;
      putchar(gc);
    }
    if (gc == ' ' && sc < 1) {
      ++sc;
      putchar(gc);
    } else if (gc == ' ' && sc > 1) {
      gc = 0;
    }
  };
  printf("\nEnd of text\n");
};
