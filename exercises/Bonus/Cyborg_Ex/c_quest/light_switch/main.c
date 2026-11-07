// Write a function "light_switch" that toggles a boolean input.
/*
   var light = false;
   light_switch(light);
   light_switch(light);
   light_switch(light);
   print(light); //true
*/

// #include <boolean.h>
//
// #include <stdio.h>
//
// #define LIGHT_OFF = 0
// #define LIGHT_ON = 1
//
// #define LIGHT_STATE = 0
// const int light = 1;
//
// void light_switch(int light);
//
// int main() {
//   light_switch(light);
//   return 0;
// }
//
// void light_switch(int light) {
//   if (light == 1 && LIGHT_STATE == LIGHT_OFF) {
//     LIGHT_STATE = LIGHT_ON;
//   } else if (light == 1 && LIGHT_STATE == 1) {
//     LIGHT_STATE = LIGHT_OFF;
//   }
// }

#include <stdio.h>
void light_switch(int *light_in) { *light_in = !*light_in; }

int light_switch_by_value(int light_in) { return !light_in; }

int main() {
  int light = 0;
  // light_switch(&light);
  // light_switch(&light);
  // light_switch(&light);
  // light_switch(&light);
  // printf("%d", light);                  // true
  light = light_switch_by_value(light); // false
  printf("%d", light);
}
