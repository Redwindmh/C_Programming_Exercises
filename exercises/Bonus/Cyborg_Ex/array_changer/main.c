#include <stdio.h>
#include

void array_adjust(int index, int arry[], int val);

int main() {
  array_adjust(3, [ 1, 2, 3, 4, 5 ], 6);
  return 0;
}

void array_adjust(int index, int arry[], int val) {
  int array_len = sizeof(*arry) - 1;
  arry[index] = val;
  for (int i = 0; i < array_len; ++i) {
    printf("d", i);
  }
}
