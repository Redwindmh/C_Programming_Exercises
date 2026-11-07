/**
 * Write a program to print a histogram of word lengths (horizontal bars easy,
 * vertical more challenging).
 */
#include <stdio.h>

int main(void) {
  int gc = 0;

  while ((gc = getchar()) != EOF) {
    if (gc != ' ') {
      gc = 'x';
      putchar(gc);
      printf("\n");
    } else if (gc == ' ') {
      putchar(gc);
    }
  }
}
