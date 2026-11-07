/*
        Homing Missile:

    We're building a game and are planning
    to implement a homing missle mechanic.  We need a missle that's
    smart and efficient, it needs to avoid all slain targers and
    allies.  It should prioritize slaying an enemy target if it can,
    or damaging an enemy if it can't.

    Build a function "find_best_target" that takes in an array of target
   structs, and an integer that represents how much damage the missle can do.
    Return the index of the target array that would make the best
    target.  If there are no ideal targets return -1.

    Target {
        hp: integer
        isAlly: bool
    }
*/

/*
        Input:
                -Array of Target Structs
                        -Values:
                                -hp: int
                                -isAlly; bool
                -Int for max damage

        Throughput:
                -Objective:
                        -Find best target where best = target that:
                                -0 hp == -1
                                -isAlly is true == -1
                                -Int Damage >= hp

        Output:
                -Int index of best target || -1 if there is none
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Target {
  int hp;
  bool is_ally;
} Target;

int find_best_target(Target *targets, int arr_len, int max_damage);
void target_finder_test(void);

int main(void) {
  // Target tar_zero = {};
  // Target tar_one = {20, true};
  // Target tar_two = {30, false};
  // Target tar_three = {0, false};
  // Target tar_four = {10, false};

  // Target target_arr[5] = {tar_zero, tar_one, tar_two, tar_three, tar_four};

  // find_best_target(target_arr, 5, 15);
  target_finder_test();

  return 0;
}

int find_best_target(Target *targets, int arr_len, int max_damage) {
  int target_index = -1;

  if (max_damage <= 0) {
    /* Logic for healing missle
     I feel like in order to do find the best target to heal correctly,
     we would need more information about the targets' max health, and
     I would prerfer to make that into a separate function entire that
     only gets called given the above condition.
    */
    return -1;
  }

  if (!targets || arr_len == 0) {
    return -1;
  }

  for (int i = 0; i < arr_len; i++) {
    bool is_enemy = !targets[i].is_ally;
    bool is_living = targets[i].hp > 0;
    bool is_valid_target = is_enemy && is_living;
    bool is_slayable = is_valid_target && targets[i].hp <= max_damage;
    bool best_is_slayable = targets[target_index].hp <= max_damage;

    printf("Currently checking target %d\n", i);

    if (!is_valid_target) {
      continue;
    } else if (is_slayable && !best_is_slayable) {
      target_index = i;
    } else if (is_slayable == best_is_slayable) {
      if (targets[i].hp > targets[target_index].hp) {
        target_index = i;
      } else {
        if (targets[i].hp < targets[target_index].hp) {
          target_index = i;
        }
      }
      printf("Current best target is %d\n", target_index);
    }
  }
  printf("Missle target index = %d\n", target_index);
  return target_index;
}

void target_finder_test(void) {
  Target targets1[] = {{15, true}, {15, false}, {0, false},
                       {3, false}, {25, true},  {10, false}};
  int result1 = find_best_target(targets1, 6, 10);
  assert(result1 == 5);
  printf("Test one has passed!\n");

  int result2 = find_best_target(targets1, 6, 0);
  assert(result2 == -1);
  printf("Test two has passed!\n");

  Target targets3[] = {{15, true}, {15, true}, {0, true}};
  int result3 = find_best_target(targets3, 3, 100);
  assert(result3 == -1);
  printf("Test three has passed!\n");

  Target targets4[] = {{3, false},   {25, true},   {1000, false},
                       {400, false}, {300, false}, {600, false}};
  int result4 = find_best_target(targets4, 6, 200);
  assert(result4 == 4);
  printf("Test four has passed!\n");
}

// void target_finder_test(void) {
//   int missile = 10;
//
//   find_best_target(
//     [
//       {hp: 15, isAlly: true },
//       {hp: 15, isAlly: false },
//       {hp: 0,  isAlly: false },
//       {hp: 3,  isAlly: false },
//       {hp: 25, isAlly: true },
//       {hp: 10, isAlly: false },
//     ],
//     missile,
//   ) //5
//
//   find_best_target(
//     0,
//     [
//       {hp: 15, isAlly: true },
//       {hp: 15, isAlly: false },
//       {hp: 0,  isAlly: false },
//       {hp: 3,  isAlly: false },
//       {hp: 25, isAlly: true },
//       {hp: 10, isAlly: false },
//     ]
//   ) //-1
//
//   Target arry_2 = (
//     [
//       {hp: 15, isAlly: true },
//       {hp: 15, isAlly: true },
//       {hp: 0,  isAlly: true },
//     ],
//     3,
//     100,
//   ) //-1
// }
//
/*
  Sample Tests:
  let missile = 10;
  find_best_target(
    missile,
    [
      {hp: 15, isAlly: true },
      {hp: 15, isAlly: false },
      {hp: 0,  isAlly: false },
      {hp: 3,  isAlly: false },
      {hp: 25, isAlly: true },
      {hp: 10, isAlly: false },
    ]
  ) //5

  find_best_target(
    0,
    [
      {hp: 15, isAlly: true },
      {hp: 15, isAlly: false },
      {hp: 0,  isAlly: false },
      {hp: 3,  isAlly: false },
      {hp: 25, isAlly: true },
      {hp: 10, isAlly: false },
    ]
  ) //-1

  find_best_target(
    100,
    [
      {hp: 15, isAlly: true },
      {hp: 15, isAlly: true },
      {hp: 0,  isAlly: true },
    ]
  ) //-1
*/
