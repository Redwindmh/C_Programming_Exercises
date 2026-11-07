// Fizzbuzz 3 = fizz 5 = buzz 15 = fizzbuzz

#include <stdio.h>

void fizzbuzz(int in);

int main() {
  fizzbuzz(100);
  return 0;
}

void fizzbuzz(int in) {
  int input = in;
  for (int i = 0; i <= input; ++i)
    if (i % 15 == 0)
      printf("fizzbuzz\n");
    else if (i % 5 == 0)
      printf("buzz\n");
    else if (i % 3 == 0)
      printf("fizz\n");
    else
      printf("%d\n", i);
}
