/* Program 3.5 Testing Letters, an easier way */
#include <stdio.h>

int main(void) {
  char letter = 0;                         /* Stores a character      */
  
  printf("Enter an uppercase letter: ");   /* Prompt for the input    */
  scanf("%c", &letter);                    /* Read a character        */
  
  if((letter >= 'A') && (letter <= 'Z')) { /* Verify uppercase letter */
    letter += 'a' - 'A';                   /* Convert to lowercase    */
    printf("You entered an uppercase %c.\n", letter);
  }else
    printf("You did not enter an uppercase letter.\n");
  return 0;
}
