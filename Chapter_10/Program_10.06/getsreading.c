/* Program 10.6 Reading a string with gets() */
#include <stdio.h>

int main(void) {
  char initial[2] = {0};
  char name[80] = {0};
  
  printf("Enter your first initial: ");
  gets(initial);
  printf("Enter your name: ");
  gets(name);
  if(initial[0] != name[0])
    printf("\n%s, you got your initial wrong.\n", name);
  else
    printf("\nHi, %s. Your initial is correct. Well done!\n", name);
    
  return 0;
}
