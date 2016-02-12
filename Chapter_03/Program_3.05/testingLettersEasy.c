/* Program 3.5 Testing Letters the easy way */
#include <stdio.h>

int main(void) {
  char letter = 0;                                    /* Stores an input character */
  
  printf("Enter an uppercase letter: ");              /* Prompt for input */
  scanf("%c", &letter);                               /* Read the input character */
  
  if((letter >= 'A') && (letter <= 'Z')) {            /* Verify the uppercase letter */
    letter += 'a' - 'A';                              /* Convert to lowercase */
    printf("You entered an uppercase %c.\n", letter);
  }else
    printf("You did not enter an uppercase letter.");

  return 0;
}
