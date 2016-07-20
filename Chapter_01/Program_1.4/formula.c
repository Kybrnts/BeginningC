/* Program 1.4 Another Simple C Program - Displaying a quotation */
#include <stdio.h>

int main(void) {
  printf ("\nMy formula tu success?\nRise early, work late, strike oil.\n");
  /* * The combination \n is an ESCAPE SEQUENCE that represents a newline character. This causes the output cursor to
   *   move to the next line, so subsequent output will start on a new line.
   * * The backslash is used to indica the start of such sequences. It's following character indicates what sequence
   *   represents (in this case NEWLINE). There are plenty possibilities. 
   * * Because a backslash itself is special, we need a way to specify a backslash in a text string. To do this, we use
   *   two backslashes.
   */
  return 0;
}
