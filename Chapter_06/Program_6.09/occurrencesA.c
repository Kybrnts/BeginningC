/* Program 6.9 Finding occurrences of one string in another */
#include <stdio.h>
#include <wchar.h>
#define TEXTSIZE 100
#define SUBSSIZE 40

int main(void) {

  wchar_t text[TEXTSIZE],  /* Input buffer for string to be searched */
    substring[SUBSSIZE];   /* Input buffer for string sought */
  int i;                   /* Loop control variable */

  printf("\nEnter the string to be searched (less than 100 characters): \n");
  if(fgetws(text, sizeof(text)/2, stdin) == NULL) {
    printf("\nError reading text!");
    return 1;
  }
  printf("\nEnter the string sought (less than 40 characters): \n");
  if(fgetws(substring, sizeof(substring)/2, stdin) == NULL) {
    printf("\nError reading sought!");
    return 1;
  }
  
  /* Overwrite the newline character in each string */
  text[wcslen(text) - 1] = L'\0';
  substring[wcslen(substring) - 1] = L'\0';

  /* Convert both strings to uppercase */
  printf("\nFirst string entered: \n%S\n", text);
  printf("\nSecond string entered: \n%S\n", substring);

  /* Convert both strings to uppercase */
  for(i = 0; text[i] = towupper(text[i]); i++);
  for(i = 0; substring[i] = towupper(substring[i]); i++);

  printf("\nThe second string %s found in the first.",
	 wcsstr(text, substring) == NULL ? "was not" : "was");

  return 0;
}
