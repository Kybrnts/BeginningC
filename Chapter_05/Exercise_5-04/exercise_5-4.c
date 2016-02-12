/* Exercise 5-4 */
/*
 * Define a two-dimensional array, data[12][5], of type double. Initialize the elements in the first column with values
 * from 2.0 to 3.0 inclusive in steps of 0.1. If the first element in a row has the value x, populate the remaining
 * elements in each row with the values 1/x, x^2, x^3, and x^4. Output the values in the array with each row on a separate
 * line and with a heading for each column.
 */
#include <stdio.h>
#define ROWS 5
#define COLS 5
#define STEP 0.10f

int main(void) {
  int i,
    j;
  double data[ROWS][COLS];
  
  /* Initialize the elements of the first column (in steps of 0.1)*/
  data[0][0] = STEP;
  for(i = 1; i < ROWS; i++)
    data[i][0] = data[i - 1][0] + STEP;

  /* Populate the remaining element in each row */
  for(i = 0; i < ROWS; i++) {
    for(j = 1; j < COLS; j++) {
      data[i][j] = (j == 1 ?
		    1/data[i][0] : j == 2 ? 
		    data[i][0] * data[i][0] : data[i][j - 1] * data[i][0]);
    }
  }
  
  /* Display the two dimensional array */
  printf("\nHere is the %dx%d array:"
	 "\n+", ROWS, COLS);
  for(j = 0; j < COLS; j++) {
    printf("-----------+");
  }
  printf("\n|");
  for(j = 0; j < COLS; j++) {
    printf(" Col. %3d  |", j + 1);
  }  
  
  for(i = 0; i < ROWS; i++) {
    printf("\n+");
    for(j = 0; j < COLS; j++) {
      printf("-----------+");
    }
    printf("\n|");
    for(j = 0; j < COLS; j++) {
      printf(" %9.5lf |", data[i][j]);
    }
  }
  printf("\n+");
  for(j = 0; j < COLS; j++) {
    printf("-----------+");
  }
  printf("\n");
  return 0;
}
