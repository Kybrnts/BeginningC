/* Program 3.4 Converting uppercase to lowercase */
#include <stdio.h>

int main(void) {
  char letter = 0;                       /* Stores a character     */
  
  printf("Enter an uppercase letter: "); /* Prompt for the input   */
  scanf("%c", &letter);                  /* Read a character       */
  
  /*Check whether the input is already an uppercase  */
  if(letter >= 'A')                      /* Is it A or greater?    */
    if(letter  <= 'Z' ) {                /* And is it Z or lower ? */
      /* Now we know it is uppercase                 */
      letter = letter - 'A' + 'a';
      /* This will get the "distance" between A and the entered uppercase letter.
       * Then it will add it to a. The outcome will be the matching lowercase letter, because the distance is the same.
       */      
      printf("You entered an uppercase %c\n", letter);
    }else
      printf("Try using the shift key, Bud! I want a capital letter.\n");
  /* In case the entered character was less than 'A' */
  else 
    printf("You didn't enter an uppercase letter.\n");

  return 0;
}
