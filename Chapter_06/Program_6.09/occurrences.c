/* Program 6.9 Finding occurrences of one string in another */
#include <stdio.h>
#include <ctype.h>  /* For character convert functions */
#include <string.h> /* For string handling functions */

int main(void) {
  char text[100],   /* Input buffer for string to be searched */
    substring[40];  /* Input buffer for string sought */
  int i;            /* Loop control variable */

  printf("\nEnter the string to be searched (less than 100 characters): \n");
  if(fgets(text, sizeof(text), stdin) == NULL) {
    printf("\nError reading text!");
    return 1;
  }
  printf("\nEnter the string sought (less than 40 characters): \n");
  if(fgets(substring, sizeof(substring), stdin) == NULL) {
    printf("\nError reading sought!");
    return 1;
  }
  /*
   * You use the fgets() function here because it will read in any string from the keyboard, including spaces, the input
   * being terminated when the Enter key is pressed. The input process will only allow 99 characters to be entered for
   * the first string, text, and 39 characters for the second string, substring. If more characters are entered they
   * will be ignored so the operation of the program is safe.
   */

  /* Overwrite the newline character in each string */
  text[strlen(text) - 1] = '\0';
  substring[strlen(substring) - 1] = '\0';
  /*
   * You'll recall that fgets() stores the newline character that ends the input process. This doesn't matter
   * particularly for the first string but it matters a lot for the second string you are searching for. For example, if
   * the string you want to find is "dogs", the fgets() function will actually store "dogs\n", which is not the same at
   * all. You therefore remove the newline from each string by overwriting it with a '\0' character.
   */

  printf("\nFirst string entered:\n%s\n", text);
  printf("\nSecond string entered:\n%s\n", substring);
  
  /* Convert both strings to uppercase */
  for(i = 0; text[i] = toupper(text[i]); i++)
    /* Uncomment this to show each asigned value */
    /* printf("0x%3x -> %c\n", text[i], text[i]) */
    ;
  for(i = 0; substring[i] = toupper(substring[i]); i++)
    /* Uncomment this to show each asigned value */
    /* printf("0x%3x -> %c\n", substring[i], substring[i]) */
    ;
  /*
   * You use for loops to do the conversion and the work is done entirely within the control expressions for the loops.
   * The first for loop initializes i to 0, and then converts the ith character of text to uppercase in the loop
   * condition and stores that result back in the same position in text. The loop continues as long as the character code
   * stored in text[i] in the second loop control expression is nonzero, which will be for any character except NULL
   */

  printf("\nThe second string %s found in the first.",
	 strstr(text, substring) == NULL ? "was not" : "was");
  /*
   * strstr() function returns NULL when the string specified by the second argument isn't found in the first.
   * Otherwise, it returns the address where the string was found.
   */

  return 0;
}
