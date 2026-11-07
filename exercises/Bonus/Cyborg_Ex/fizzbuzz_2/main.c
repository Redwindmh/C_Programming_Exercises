#include <stdio.h>

void fizzbuzz(int *num);

int main() {
  int num = 99;
  int *num_pointer = &num;
  int **num_pp = &num_pointer;

  fizzbuzz(*num_pp);

  return 0;
}

void fizzbuzz(int *num) {
  for (int i = 0; i <= *num; i++) {
    if (i % 3 == 0) {
      printf("fizz\n");
    } else if (i % 5 == 0) {
      printf("buzz\n");
    } else if (i % 15 == 0) {
      printf("fizzbuzz\n");
    } else {
      printf("%d\n", i);
    }
  }
}
