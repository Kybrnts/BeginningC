/* Program 2.14 Choosing the correct type for the job II */
/*This is an improved version of Program 2.13 */
#include <stdio.h>

int main(void) {
  const float Revenue_Per_150 = 4.5f;
  short JanSold = 23500,              /* Stock sold in January */
    FebSold = 19300,                  /* Stock sold in Februrary */
    MarSold = 21600;                  /* Stock sold in March */
  float RevQuarter = 0.0f;            /* Sales for the quarter */

  /* Improvement: change the type of "QuarterSold" so that supports the expected decimal representation. */  
  long QuarterSold = JanSold + FebSold + MarSold; /* Calculate quarterly total */

  /* Output monthly sales an total for the quarter */
  printf("\nStock sold in\n Jan: %d\n Feb: %d\n Mar: %d", JanSold, FebSold, MarSold);
  /* The previous improvement requires the usage of %ld instead of %d */
  printf("\nTotal stock sold in first quarter: %ld", QuarterSold);

  /* Calculate the total revenue for the quarter and output it */
  RevQuarter = QuarterSold/150*Revenue_Per_150;
  /*
   * Now the value of the stock sold in the quarter is ok, though the value of reveneue is not.
   * Here is how RevQuarter value is calculated:
   * The result of QuarterSold/150 is then multiplied by the constant.
   * Since QuarterSold and 150 are both of integer type, the desired result of 429.333 will be truncated to 429. Here
   * is where the error is produced.
   * Then 429 will be multiplied by 4.5, and because of the way arithmetic with mixed operand types work, the result
   * will be of the type float, but wrong.
   *
   * To get the rid of that error, we can rewrite the expression in this way:
   * RevQuarter = Revenue_Per_150*QuarterSold/150
   */

  printf("\nSales revenue this quarter is:$%.2f\n",RevQuarter);

  return 0;
}
