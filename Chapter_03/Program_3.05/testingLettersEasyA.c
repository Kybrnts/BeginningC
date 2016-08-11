/* Program 3.5 Testing Letters, an easier way using wide characters */
#include <stdio.h>
#include <stddef.h>

int main(void) {
  wchar_t letter = 0;
  
  printf("Enter an uppercase letter: ");
  scanf("%lc", &letter);
  
  if((letter >= L'A') && (letter <= L'Z')) {
    letter += 'a' - 'A';
    printf("You entered an uppercase %lc.\n", letter);
  }else
    printf("You did not enter an uppercase letter.\n");
  return 0;
}
