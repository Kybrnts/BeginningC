/* Program 10.6A Reading a string with fgets() */
#include <stdio.h>
#include <string.h>

int main(void) {
  char initial[2] = {0};
  char name[80] = {0};
  size_t length = strlen(name);

  printf("Enter your first initial: ");
  fgets(initial, sizeof(initial), stdin); /* Read one character max */
  while(getchar() != '\n');               /* Flush the newline      */
  
  printf("Enter your name: ");
  fgets(name, sizeof(name), stdin);       /* Read max name-1 chars */
  length = strlen(name);
  name[length - 1] = name[length];        /* Overwrite the newline */
  
  if(initial[0] != name[0])
    printf("\n%s, you got your initial wrong.\n", name);
  else
    printf("\nHi, %s. Your initial is correct. Well done!\n", name);

  return 0;
}
