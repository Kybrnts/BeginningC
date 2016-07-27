/* Program 2.3 Using more variables */
#include <stdio.h>

int main(void) {
  int brothers, /* Declare a variable called brothers */
    brides;     /* and a variable called brides       */
  /* By spreading the statement out over two lines, we can put the comments back in. Comments are ignored by the
   * compiler so it’s the exact equivalent of the original statement without the comments. We can spread C statements
   * over as many lines as we want. The semicolon determines the end of the statement, not the end of the line.
   * We might write the preceding statement as two statements, and in general it is a better practice to define each
   * variable in a separate statement. Variable declarations often appear at the beginning of the executable code for a
   * function, but it is not mandatory. We typically put declarations for variables that we intend to use in a block of
   * code that is between a pair of braces immediately following the opening brace
   */

  brothers = 7; /* Store de value "7" in the variable brothers */
  brides = 7;   /* Store the same value in the value brides    */
  /* The statements that declared the variables precede these statements. Otherwise the progrm won't compile. */

  printf("%d brides for %d brothers\n", brides, brothers);
  /* The control string of the first argument will display a line of thext 
   * The %d conversion specifier within this control string well be replaced by the values currently stored in the
   * variables that appears as the following arguments.
   */
  return 0;
}
