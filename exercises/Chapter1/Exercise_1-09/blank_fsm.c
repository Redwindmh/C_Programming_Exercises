/* blank reducer to reduce multiple spaces to one space using a finite state
 * machine to determine whether the current character is in a word or not, and
 * if not, to then initiate a space counter.
 */

#include <stdio.h>

typedef enum { IN, OUT } State;

int main() {
  int gc = 0;
  int wc = 0; // word counter
  int cc = 0; // character counter
  int sc = 0; // space counter

  State state = OUT;

  while ((gc = getchar()) != EOF) {
    if (gc != ' ')
  }
}
