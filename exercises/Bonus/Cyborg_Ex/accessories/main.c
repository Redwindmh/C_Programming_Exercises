/*
***Jewelry Trading:***
Consider the following structs:
```c
Person {
    name: String
    accessory: Jewel
}

Jewel {
    name: String
    owner: Person
}
```
Implement the following functions:
```c
- acquire (Person, Jewel): A person obtains a jewel

- lend (Person, Person): A person allows another to borrow their jewel

- discard (Person): A person gets rid of their jewel

- personInfo (Person): Log a persons name and their jewel if they have one. If
the jewel is borrowed specify who the jewel was borrowed from
```
*/

/*
        Input:
                - struct Person
                - struct Jewel

        Throughput:
                - function acquire:
                        - A Jewel struct is assigned to a Person struct
                - function lend:
                        - A Jewel struct is passed from one Person struct to
   another while retaining its owner
                - function discard:
                        - A Jewel struct belonging to a Person struct is removed
   (rendered NULL)
                - function person_info:
                        - prints the name and accessory of a given Person struct

        Output:
                - struct Person is either updated after each function or printed
   out to terminal
*/

#include <stdio.h>

typedef struct Jewel {
  char name[20];
  struct Person *owner;
} Jewel;

typedef struct Person {
  char name[20];
  struct Jewel *accessory;
} Person;

#define PERSON_HAS_ACCESSORY person->accessory != NULL
#define PERSON_DOES_NOT_HAVE_ACCESSORY person->accessory == NULL
#define JEWEL_HAS_OWNER jewel->owner != NULL
#define JEWEL_DOES_NOT_HAVE_OWNER jewel->owner == NULL

void acquire(Person *person, Jewel *jewel);
void discard(Person *person);
void lend(Person *person_one, Person *person_two);
void person_info(Person *person);
void jewel_info(Jewel *jewel);

int main() {
  Person Kain = {"Kain", NULL};
  Person Raziel = {"Raziel", NULL};
  Jewel SoulReaver = {"Soul Reaver", NULL};

  person_info(&Raziel);
  person_info(&Kain);
  jewel_info(&SoulReaver);
  acquire(&Raziel, &SoulReaver);
  person_info(&Raziel);
  lend(&Raziel, &Kain);
  person_info(&Raziel);
  person_info(&Kain);
  jewel_info(&SoulReaver);
  discard(&Kain);
  person_info(&Kain);
  jewel_info(&SoulReaver);

  return 0;
}

void acquire(Person *person, Jewel *jewel) {
  if (PERSON_DOES_NOT_HAVE_ACCESSORY) {
    if (JEWEL_HAS_OWNER) {
      jewel->owner->accessory = NULL;
    }
    person->accessory = jewel;
    jewel->owner = person;
    printf("%s has acquired %s.\n", person->name, jewel->name);
  } else {
    printf("%s already has %s.\n", person->name, person->accessory->name);
  }
}

void discard(Person *person) {
  if (PERSON_HAS_ACCESSORY) {
    person->accessory->owner = NULL;
    person->accessory = NULL;
  } else {
    printf("%s does not have an accessory.\n", person->name);
  }
}

void lend(Person *person_one, Person *person_two) {
  printf("%s lends %s to %s.\n", person_one->name, person_one->accessory->name,
         person_two->name);
  acquire(person_two, person_one->accessory);
}

void person_info(Person *person) {
  printf("**Person information**\nName: %s\n", person->name);

  if (PERSON_DOES_NOT_HAVE_ACCESSORY) {
    printf("%s has no accessory.\n", person->name);
  } else {
    printf("Accessory: %s, which belongs to %s.\n", person->accessory->name,
           person->accessory->owner->name);
  }
}

void jewel_info(Jewel *jewel) {
  printf("**Jewel information**\nName: %s\n", jewel->name);

  if (JEWEL_DOES_NOT_HAVE_OWNER) {
    printf("%s has no owner.\n", jewel->name);
  } else {
    printf("%s is owned by %s.\n", jewel->name, jewel->owner->name);
  }
}

/*
**Person information**
Name: Raziel
Raziel has no accessory.
**Person information**
Name: Kain
Kain has no accessory.
**Jewel information**
Name: Soul Reaver
Soul Reaver has no owner.
Raziel has acquired Soul Reaver.
**Person information**
Name: Raziel
Accessory: Soul Reaver, which belongs to Raziel.
Raziel lends Soul Reaver to Kain.
Kain has acquired Soul Reaver.
**Person information**
Name: Raziel
Raziel has no accessory.
**Person information**
Name: Kain
Accessory: Soul Reaver, which belongs to Kain.
**Jewel information**
Name: Soul Reaver
Soul Reaver is owned by Kain.
**Person information**
Name: Kain
Kain has no accessory.
**Jewel information**
Name: Soul Reaver
Soul Reaver has no owner.
 */
