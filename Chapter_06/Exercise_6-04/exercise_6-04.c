/* Exercise 6.04 */
/*
 * A palindrome is a phrase that reads the same backward as forward, ignoring whitespace and punctuation. For example:
 * Madam, I'm Adam" and "Are we not drawn onward, we few? Drawn onward to new era?" are palindromes. Write a program
 * that will determine whether a string entered from the keyboard is a palindrome.
 */

#include <stdio.h>
#include <wchar.h> /* Using wide character strings */

#define SIZE 500

#define NULLCHAR L'\0'


int main(void) {
  /* Defining suitable variables */
  wchar_t input[SIZE] = L"",
    phrase[SIZE] = L"";
  unsigned short half,
    i, j;

  /* Read big string from stdin */
  printf("\nEnter a phrase to palindrome-test for:\n");
  if(fgetws(input, SIZE, stdin) == NULL) {
    printf("Error! Failed while reading from stdin. Finishing program.");
    return 1;
  }

  /* Ignore everything except alphanumeric characters, and store them in "phrase" */
  for(i = 0, j = 0; input[i]; i++) {
    if(iswalnum(input[i]))
      phrase[j++] = tolower(input[i]); /* Case insensitive */
  }
  phrase[j] = NULLCHAR; /* Add string terminator */
  j--;                  /* Now j stores the position of the last non null character */

  /* Check for palindrome */
  /* Example: 
   * Guiven the string "a_0 a_1 a_2 a_3_ a_4", we have to compare "a_0 a_1" with "a_3 a_4"
   */
  half = j/2;                                               /* Ignore reminder in case phrase lenght is odd */
  for(i = 0; i <= half && phrase[i] == phrase[j - i]; i++); /* i <= half should be checked first (short circuit and) */
  if(i > half) {
    printf("The phrase you entered IS palindrome.");
  }else {
    printf("You entered is NOT palindrome.");
  }  
  return 0;
}
