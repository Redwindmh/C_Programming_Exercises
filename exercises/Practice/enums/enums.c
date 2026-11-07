#include <stdio.h>

enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

int main() {
  enum Day today = WEDNESDAY;
  printf("It is day %d\n", today);

  return 0;
}
