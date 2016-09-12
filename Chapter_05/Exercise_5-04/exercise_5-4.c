/* Exercise 5-4 */
/*
 * Define a two-dimensional array, data[11][5], of type double. Initialize the elements in the first column with values
 * from 2.0 to 3.0 inclusive in steps of 0.1. If the first element in a row has the value x, populate the remaining
 * elements in each row with the values 1/x, x^2, x^3, and x^4. Output the values in the array with each row on a separate
 * line and with a heading for each column.
 */
#include <stdio.h>
#define ROWS 11U
#define COLS 5U
#define STEP 0.10

int main(void) {
  unsigned i, j;                      /* Loop control variables                    */
  double data[ROWS][COLS] = {{2.0}};  /* Two dim array w/first element initialized */

  /* Initialize the elements of the first column (in steps of 0.1)*/
  for(i = 1U; i < ROWS; i++)
    data[i][0U] = data[i - 1U][0U] + STEP;
  /* Populate the remaining element in each row */
  for(i = 0U; i < ROWS; i++) {
    for(j = 1U; j < COLS; j++) {                                            /* For the current row, if this is the    */
      data[i][j] = (j == 1U ?                                               /* 1st element use 1/x value where x is   */
		    1/data[i][0U] : j == 2U ?                               /* the 1st row's value. For the 2nd, use  */
		    data[i][0U] * data[i][0U] : data[i][j - 1U] * data[i][0U]); /* x^2. For the rest multiply what we */
    }                                                                       /* have int previous element by x.        */
  }  
  /* Display the two dimensional array */
  printf("Here is the %ux%u array:\n+", ROWS, COLS);
  for(j = 0U; j < COLS; j++)
    printf("-----------+");
  printf("\n|");
  for(j = 0U; j < COLS; j++)
    printf(" Col. %3u  |", j + 1);
  for(i = 0U; i < ROWS; i++) {
    printf("\n+");
    for(j = 0U; j < COLS; j++)
      printf("-----------+");    
    printf("\n|");
    for(j = 0U; j < COLS; j++)
      printf(" %9.5f |", data[i][j]);
  }
  printf("\n+");
  for(j = 0U; j < COLS; j++)
    printf("-----------+");
  printf("\n");
  return 0;
}
