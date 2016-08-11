/* Program 3.5C Testing Letters easier, using wide characters */
#include <stdio.h>
#include <stddef.h> /* Provides wchar_t type                      */
#include <wctype.h> /* Provides iswalpha(), iswupper(), towlower()*/

int main(void) {
  wchar_t letter = 0;

  printf("Enter an uppercase letter: ");
  scanf("%lc", &letter);

  if(iswalpha(letter) && iswupper(letter)) {
    printf("You entered an uppercase %lc.\n", towlower(letter));
  }else
    printf("You did not enter an uppercase letter.\n");
  return 0;
}
