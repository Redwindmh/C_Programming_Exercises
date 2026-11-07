/*
  Write a fizzbuzz program, however you're only allowed a single printF usage in
  the entire program and strings aren't allowed.  Chars are allowed.
*/

/*
- Create a function to print a range of numbers starting from 0 to the input
number
- Using a single printf statement, it should print fizzbuzz for numbers
divisible by 15, fizz for numbers divisible by 5 and buzz for numbers divisible
by 3
*/
#include <stdio.h>

void fizzbuzz(int num);

char fizzbuzz[8] = "fizzbuzz";
char fizz[4] = "fizz";
char buzz[4] = "buzz";

int main() {
  fizzbuzz(100);
  return 0;
}

void fizzbuzz(int num) {
  for (int i = 0; i <= num; i++) {
    if (i % 15) {
      // fizzbuzz
      i = 'F';
    } else if (i % 5) {
      // fizz
      i = 'f';
    } else if (i % 3) {
      // buzz
      i = 'b';
    }
    printf("%d\n", i);
  }
}
