/* Exercise 4-2. */
/* Write a program that will output the printable characters for character code values from 0 to 127. Output each 
 * character code along with its symbol with two characters to a line. Make sure the columns are aligned. (Hint:
 * You can use the isgraph() function that's declared in ctype.h to determine when a character is printable.)
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
  unsigned char c; /* Stores the current character to be printed */

  /* Print the table header */
  printf("\nASCII character code values\n"
	 "---------------------------\n\n"
	 "+---------+-------------+-----------+\n"
         "| Decimal | Hexadecimal | Character |\n"
         "+---------+-------------+-----------+\n");
  for(c = 0U; c < 128U; c++) {
    /* Print decimal code */
    printf("| %s%u |",  c < 10 ?
	   "    00" : c < 100 ? 
	   "    0" :
	   "    ",
	   c);
    /* Print hexadecimal code */
    printf(" %s%x |", c < 16 ?
	   "        0x" : 
	   "       0x",
	   c);
    /* Print character (if possible)*/
    if(isgraph(c))
      printf("         %c |\n", c);
    else
      printf("       N/A |\n");
  }
  /* Print the foot of the table */
  printf("+---------+-------------+-----------+\n\n");
  return 0;
}
