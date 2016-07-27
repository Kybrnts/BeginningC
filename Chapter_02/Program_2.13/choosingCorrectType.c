/* Program 2.13 Choosing the correct type for the job I */
/* This is an example of how things could go horribly wrong if someone chooses an unsuitable type for the variables */
#include <stdio.h>

int main(void) {
  const float Revenue_Per_150 = 4.5f;
  short JanSold = 23500,              /* Stock sold in January */
    FebSold = 19300,                  /* Stock sold in Februrary */
    MarSold = 21600;                  /* Stock sold in March */
  float RevQuarter = 0.0f;            /* Sales for the quarter */
  
  short QuarterSold = JanSold + FebSold + MarSold; /* Calculate quarterly total */
  /* 
   * Initializing a variable with the result of an expression is only possible because the assigned value is known by
   * the compiler (i.e. a constant expression). If any of the values in the expression were determined during execution
   * of the program -from a calculation involving a value that was read in, for instance- this woludn't compile. The
   * compiler can only use initial values that are explicit or are produced by an expression that can be evaluated
   * during the compilation.
   *
   * The mathematical result of the previous sum will be represented as a negative number because we are using a
   * variable of the type short. This type will support the same representation for decimal numbers up to 32767.
   *
   */

  /* Output monthly sales an total for the quarter */
  printf("Stock sold in\n Jan: %d\n Feb: %d\n Mar: %d\n", JanSold, FebSold, MarSold);
  printf("Total stock sold in first quarter: %d\n", QuarterSold);

  /* Calculate the total revenue for the quarter and output it */
  RevQuarter = QuarterSold/150*Revenue_Per_150;
  printf("Sales revenue this quarter is: $%.2f\n",RevQuarter);

  return 0;
}
