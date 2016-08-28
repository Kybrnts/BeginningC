/* Exercise 4-1 */
/* Write a program that will generate a multiplication table of a size entered by the user. A table of size 4, for
 * instance, would have four rows and four columns. The rows and columns would be labeled from 1 to 4. Each cell in the
 * table will contain the product of the corresponding row and column numbers, so the value in the position
 * corresponding to the third row and the fourth column would contain 12.
 */
#include <stdio.h>

int main(void) {
  unsigned size = 0U;
  unsigned i, j;
  /* Prompt the user to enter the size of the squared table */
  printf("Enter the size of the table: ");
  scanf("%u", &size);
  /* Generate the table in STDOUT                           */
  for(i = 1U; i <= size; i++)
    for(j = 1U; j <= size; j++)
      printf(j == size ?        
	     "\t%lu\n" : j > 1 ? /* If this is the last row element use a leading tab and a trailing EOL;       */
	     "\t%lu" : "%lu",    /* Else if this is not the first element use only a leading tab;               */
	     (long)i*j);         /* Otherwise (this is the first element) use the number only.                  */
  return 0;
}
