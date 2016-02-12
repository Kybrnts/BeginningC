/* Program 2.3 Using more variables */
#include <stdio.h>

int main(void) {
  int brothers; /* Declare a variable called brothers */
  int brides;   /* and a variable called brides */

  brothers = 7; /* Store de value "7" in the variable brothers */
  brides = 7;   /* Store the same value in the value brides */

  /* The statements that declared the variables precede these statements. Otherwise the progrm won't compile. */

  /* The control string of the first argument will display a line of thext 
   * The %d conversio nspecifier within this control string well be replaced by the values currently stored in the
   * variables that appears as the following arguments.
   */
  printf("%d brides for %d brothers\n", brides, brothers);
  return 0;
}
