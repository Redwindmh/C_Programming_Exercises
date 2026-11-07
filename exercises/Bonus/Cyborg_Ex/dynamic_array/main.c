/*
        write a function that takes in int "length" and returns an
        array of ints the size of length.  The ints in the array should
        match their index

        example: createArray(5) -> {0,1,2,3,4}
*/

/*
        Inputs:
                -int length:

        Throughput:
                -function create_arr:
                        -check for 0 length
                        -create new array
                        -dynamically allocate memory equal to the length int
                        -initiate the first value in the array as 0, then
   increment +1 until number of array values == length -account for array
   terminator -free memory

        Output:
                -arr created_arr:
                        -an array whose length is the same as the length integer
   and whose values match their index
*/

#include <stdio.h>
#include <stdlib.h>

int create_arr(int length);

int main(void) {
  create_arr(8);
  return 0;
}

int create_arr(int length) {
  if (length == 0) {
    return 1;
  }

  int *arr = malloc(length * sizeof(int)); // allocate memory

  for (int i = 0; i < length; i++) { // create values in array
    arr[i] = i;
    printf("%d\n", arr[i]);
  }

  return *arr;
}
