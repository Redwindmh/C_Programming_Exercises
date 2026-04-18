/**
 * Write a program to count blanks, tabs, and newlines.
 */
#include <stdio.h>

int main(void) {
  int gc, cc, lc, tc, sc = 0;

  while ((gc = getchar()) != EOF) {
    if (gc == '\n') {
      ++lc;
    }
    if (gc == '\t') {
      ++tc;
    }
    if (gc == ' ') {
      ++sc;
    }
    ++cc;
  }
  printf(
      "Character count: %d\nLine count: %d\nTab count: %d\nSpace count: %d\n",
      cc, lc, tc, sc);
}
