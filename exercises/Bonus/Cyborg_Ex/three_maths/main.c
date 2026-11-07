#include <stdio.h>
/*
   create 3 functions: addByFive, subtractByFive, multiplyByFive

   implement the logic that their abstractions imply, use pass by
   reference but no direct pointers
*/

/*
        I will create the three functions, each containing their corresponding
   mathematic function with their values being passed to them by reference in
   the main function.
*/

int addByFive(int *ref);
int subtractByFive(int *ref);
int multiplyByFive(int *ref);

int main() {
  int num = 42;
  int *pnum = &num;
  int **ppnum = &pnum;

  printf("%p\n", pnum);
  printf("%p\n", ppnum);
  printf("%p\n", &ppnum);
  printf("%d\n", **ppnum);

  addByFive(pnum);
  subtractByFive(pnum);
  multiplyByFive(pnum);

  return 0;
}

int addByFive(int *ref) {
  printf("%d\n", *ref + 5);
  return *ref + 5;
}

int subtractByFive(int *ref) {
  printf("%d\n", *ref - 5);
  return *ref - 5;
}

int multiplyByFive(int *ref) {
  printf("%d\n", *ref * 5);
  return *ref * 5;
}
