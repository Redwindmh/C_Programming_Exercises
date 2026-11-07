#include <stdio.h>

typedef struct {
  int num_one;
  int num_two;
} Nums;

int num_sum_ref(Nums *n);

int main() {
  Nums num = {3, 6};

  printf("%d", num_sum_ref(&num));
  return 0;
}

int num_sum_ref(Nums *n) { return (n->num_one + n->num_two); }
