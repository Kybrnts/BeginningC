/* Program 9.8 List the command line arguments */
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  
  printf("Program name is %s\n", argv[0]);

  for(i = 1; i < argc; i++)
    printf("\nArgument %d: %s", i, argv[i]);
  printf("\n");
  
  return 0;
}
