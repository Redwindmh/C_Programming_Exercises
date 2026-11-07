#include <stdio.h>

int main() {
  int num_arry[5] = {1, 34, 6, 2, 99};
  int num_arry_len = sizeof(num_arry) / sizeof(num_arry[0]);

  printf("Array address: %p\n", &num_arry);
  printf("Array size: %d\n", num_arry_len);

  // for (int i = 0; int < len(num_arry); ++i) {
  //  pass
  //}
  return 0;
}
