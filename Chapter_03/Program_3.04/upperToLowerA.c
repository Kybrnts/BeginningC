/* Program 3.4A Converting uppercase to lowercase using wide characters                  */
#include <stdio.h>
#include <stddef.h>

int main(void) {
  wchar_t letter = 0;                       /* Stores a character   */
  /* The type of the variable is now wchar_t.
   * Constants require L prefix.
   * Format specifier for input and output will require a %lc.
   */  
  printf("Enter an uppercase letter: "); /* Prompt for the input    */
  scanf("%lc", &letter);
  /* NOTE: scanf("%lc", &letter), can be used in ISO C99 (gcc option -std=c99) but not in ISO C90 (gcc option -std=c89),
   *       since it doesn't support the ‘%lc’. Hence we needed -std=c99 for compiling this source.
   */  
  /*Check whether the input is already an uppercase  */
  if(letter >= L'A')                      /* Is it A or greater?    */
    if(letter  <= L'Z' ) {                /* And is it Z or lower ? */
      /* Now we know it is uppercase */
      letter = letter - L'A' + L'a';
      /* This will get the "distance" between A and the entered uppercase letter.
       * Then it will add it to a. The outcome will be the matching lowercase letter, because the distance is the same.
       */      
      printf("You entered an uppercase %lc\n", letter);
      /* NONTE: As w/scanf, printf("%lc",..), could be used in ISO C99 but not in ISO C90.
       */
    }else
      printf("Try using the shift key, Bud! I want a capital letter.\n");
  /* In case the entered character was less than 'A' */
  else 
    printf("You didn't enter an uppercase letter.\n");

  return 0;
}
