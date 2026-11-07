/**
 * Write a program to print input one word per line.
 */
#include <stdio.h>

int main(void) {
  int gc = 0;

  while ((gc = getchar()) != EOF) {
    if (gc == ' ') {
      putchar('\n');
    }
    putchar(gc);
  }
}
