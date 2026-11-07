/*
  Given an array of numbers, return the number that occurs the
  most in the array.
  - If there are no numbers that occur the most,
  return -1

        let numbers: int[] = [1,2,3,4,5,1];
        mostOccurred(numbers); //1
*/

/*
        Input:
                -integer array of potentially signed numbers where 0 or more
   numbers may occur multiple times

        Throughput:
                -In order to keep track of the most occuring number, I will use
   an occurance counter and the index of the number that occurs most -I will
   loop through the array once for each number to check its number of occurances
                -I need to figure out how to, if needed, to differentiate
   between a -1 returned when no number is reoccuring and when the reoccuring
   number is -1 -Could store the no reoccuring `-1` as an ASCII value

        Output:
                -if numbers are reoccurring:
                        return the number that occurs the most
                -if numbers are not reoccuring:
                        return -1
*/

#include <stdbool.h>
#include <stdio.h>

int check_most_occured(int *num_arr, int arr_len);

int main(void) {
  int num_arr[] = {1, 2, 3, 4, 5, 2};
  check_most_occured(num_arr, 6);
  return 0;
}

int check_most_occured(int *num_arr, int arr_len) {
  int max_count = 0;
  int most_occured = 0;

  for (int i = 0; i < arr_len; i++) {
    int current_int = num_arr[i];
    int current_count = 0;
    for (int n = 0; n < arr_len; n++) {
      if (current_int == num_arr[n]) {
        current_count++;
        if (current_count > max_count) {
          max_count = current_count;
          most_occured = num_arr[n];
        }
      }
    }
  }
  printf("The most occuring number is: %d\n", most_occured);
  return most_occured;
}
