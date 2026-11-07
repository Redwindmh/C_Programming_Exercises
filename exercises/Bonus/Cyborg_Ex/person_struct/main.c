/*
    - Create a struct "person", this struct has 2 attributes:
        name - string
                bestFriend - person

    - write a function "createPerson" that takes in a name parameter
    and generates a person struct

    - write a function "makeBestFriends" that takes
    2 best persons as parameters and assigns them as each others
    best friend attributes
*/

/*
        Data structures:
                - Struct person
                        - string name
                        - struct best_friend

        Tools:
                - memory management
                - recursion

        Processing:
                - create_person: create a person instance from its struct
                - make_best_friend: create best_friend instances from the person
   struct as well

        Output:
                - main person struct
                - best_struct structs

*/

#include <stdio.h>
#include <string.h>

typedef struct Person {
  char name[20];
  struct Person *best_friend;
} Person;

Person create_person(char *p_name);
void make_best_friends(Person *bestie_one, Person *bestie_two);

int main() {
  char person_name[20] = "Frank White";

  Person p_one = {"Jim", NULL};

  Person p_two = {"Pam", NULL};

  create_person(person_name);
  make_best_friends(&p_one, &p_two);

  return 0;
}

Person create_person(char *p_name) {
  Person frank = {};
  printf("create_person has created %s.\n", p_name);
  strcpy(frank.name, p_name);

  return frank;
}

void make_best_friends(Person *bestie_one, Person *bestie_two) {
  bestie_one->best_friend = bestie_two;
  bestie_two->best_friend = bestie_one;
  printf("%s's best friend is %s.\n", bestie_one->name,
         bestie_one->best_friend->name);
  printf("%s's best friend is %s.\n", bestie_two->name,
         bestie_two->best_friend->name);
}
