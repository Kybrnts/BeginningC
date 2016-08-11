/* Program 3.1 A simple example of if statement */
#include <stdio.h>

int main(void) {
  /* Creating a variable for the input */
  int number = 0;
  
  /* Read an integer form input after prompting the user for the data */
  printf("Enter an integer between 1 and 10: ");
  scanf("%d", &number);
  
  /* If the number si greater than 5, execute the next tatement, otherwise skip it. */
  if(number > 5)
    printf("You entered %d which is greater than 5\n", number);
  /* We compare the value in number with the value 5. If number is greater than 5, the next statement is executed, which
   * displays a message, and the next part of the program continues. If number isn’t greater than 5, the printf() is
   * skipped.
   */
  if(number < 6)
    printf("You entered %d which is less than 6\n", number);
  
  return 0;
}
