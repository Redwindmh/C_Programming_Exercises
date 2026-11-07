#include <stdio.h>
 
extern void bar();

void foo()
{
   printf("This is function %s\n", __FUNCTION__);
}

int main()
{
  printf("Rename example.\n");
//  printf("Calling function foo()\n");
//  foo();
  printf("Calling funciton bar()\n");
  bar();
  printf("End of run\n");
  return 0;
}
