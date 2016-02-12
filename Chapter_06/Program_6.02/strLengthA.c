/* Program 6.2A Lengths of strings */
#include <stdio.h>

int main(void) {
  char str1[] = "To be or not to be",
  str2[] = ", that is the question";
  int count = 0;              /* Stores the string length */

  while (str1[count])         /* Increment count till we reach the string */
    count++;                  /* terminating character. */
  printf("\nThe length of the string \"%s\" is %d characters.", str1, count);

  count = 0;                  /* Reset to zero for next string */
  while (str2[count])         /* Count characters in second string */
    count++;
  /*
   * The ASCII code value for the '\0' character is zero which corresponds to the Boolean value false. All other ASCII
   * code values are nonzero and therefore correspond to the Boolean value true. Thus the loop will continue as long as
   * str1[count] is not '\0', which is precisely what you want.
   */

  printf("\nThe length of the string \"%s\" is %d characters.\n", str2, count);

  return 0;
}
