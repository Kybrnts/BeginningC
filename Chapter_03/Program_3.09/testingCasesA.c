/* Program 3.9A testing cases with "toupper" */
#include <stdio.h>
#include <ctype.h>

int main(void) {
  char answer = 0; /* Stores an input character */

  printf("Enter Y or N: ");
  scanf("%c", &answer);
  
  switch(toupper(answer)) {
  case 'Y':
    printf("\nYou responded in the affirmative.");
    break;

  case 'N':
    printf("\nYou responded in the negative.");
    break;

  default:
    printf("\nYou did not respond correctly...");
    break;
  }
  return 0;
}
