#include <stdio.h>

void largest(int array[], int array_size, int *current_largest);

int main() {
  int arry[] = {1, 2, 3, 4, 5};
  int clv = 0;
  int *pclv = &clv;
  largest(arry, 5, pclv);
  return 0;
}

void largest(int array[], int array_size, int *current_largest) {
  /*
   Loop through the array, compare the current value in the loop to the current
   largest value (CLV) if the CLV is greater than the current value in the loop,
   do nothing, but if the CLV is less than the current value, the CLV is
   replaced with the current value.

   Could there be any negative integers in the array?
   - All numbers will be positive integers.
   Could there be float values in the array?
   - No.
   */
  int largest_value = *current_largest;

  for (int i = 0; i <= array_size - 1; i++) {
    if (array[i] > largest_value) {
      largest_value = i;
    }
    printf("%d", i);
  }
  printf("The largest integer value in the array is : %d", largest_value);
}
