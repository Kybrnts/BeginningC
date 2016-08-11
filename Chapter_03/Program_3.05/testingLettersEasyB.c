/* Program 3.5B Testing Letters the easy way, easier still */
#include <stdio.h>
#include <ctype.h> /* Provides isalpha(), isupper() and tolower() */

int main(void) {
  char letter = 0;                                    /* Stores an input character */
  printf("Enter an uppercase letter: ");              /* Prompt for input */
  scanf("%c", &letter);                               /* Read the input character */
  if(isalpha(letter) && isupper(letter)) {            /* Verify the uppercase letter */    
    printf("You entered an uppercase %c.\n", tolower(letter)); 
  }else
    printf("You did not enter an uppercase letter.\n");
  return 0;
}
