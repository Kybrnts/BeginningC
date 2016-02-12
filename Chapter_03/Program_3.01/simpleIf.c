/* Program 3.1 A simple example of if statement */
#include <stdio.h>

int main(void) {
  int number = 0; /* Creating a variable for the input */
  
  /* Read an integer form input after prompting the user for the data */
  printf("\nEnter an integer between 1 and 10: ");
  scanf("%d", &number);
  
  /* If the number si greater than 5, execute the next tatement, otherwise skip it. */
  if(number > 5)
    printf("You entered %d which is greater than 5\n", number);
  
  if(number < 6)
    printf("You entered %d which is less than 6\n", number);
  
  return 0;
}
