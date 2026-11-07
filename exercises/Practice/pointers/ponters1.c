#include <stdio.h>

void powerUp(int *powerLevel);

int main() {
  int myPowerLevel = 9000;
  int *pMyPowerLevel = &myPowerLevel;
  printf("Your current power level is %d.\n", myPowerLevel);

  powerUp(pMyPowerLevel);

  return 0;
}

void powerUp(int *powerLevel) {
  int newPowerLevel = (*powerLevel) * 2;
  printf("You powered up to %d!\n", newPowerLevel);
}
