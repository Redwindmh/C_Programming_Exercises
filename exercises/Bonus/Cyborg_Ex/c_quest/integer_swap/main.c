// #include <stdio.h>
//
// int main() {
//   int v1 = 24;
//   int v2 = 42;
//   printf("Initial v1 value is: %d\n", v1);
//   printf("Initial v2 value is: %d\n", v2);
//
//   int swap_r = v1;
//
//   *v1 = *v2;
//   *v2 = *swap_r;
//
//   printf("Swapped v1 value is: %d\n", *pv1);
//   printf("Swapped v2 value is: %d\n", v2);
//
//   return 0;
// }
#include <stdio.h>

void swap(int *v1, int *v2);

int main() {
  int v1 = 24;
  int v2 = 42;
  printf("Initial v1 value is: %d\n", v1);
  printf("Initial v2 value is: %d\n", v2);

  swap(v1, v2);

  printf("Swapped v1 value is: %d\n", v1);
  printf("Swapped v2 value is: %d\n", v2);

  return 0;
}

void swap(int *v1, int *v2) {
  int swap_r = *v1 *v1 = *v2;
  *v2 = swap_r;
}
