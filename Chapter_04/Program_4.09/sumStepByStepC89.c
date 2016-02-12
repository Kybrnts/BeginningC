/* Program 4.9C89 Sums of integers step-by-step */
/* For greater compatibility */

#include <stdio.h>

int main(void) {
  long sum = 0L; /* Stores the sum of integers */
  int count = 0; /* Number of sums to be calculated */
  int i, j;      /* The control variables */

  /* Prompt for, and read the input count */
  printf("\nEnter the number of integers you want to sum: ");
  scanf(" %d", &count);

  /*
   * The program calculates the sum from 1 to each integer value, for all values from 1 up to the value of count that
   * you enter. The important thing to grasp about this nested loop is that the inner loop completes all its iterations
   * for each iteration of the outer loop. Thus, the outer loop sets up the value of i that determines how many times
   * the inner loop will repeat.
   */

  for(i = 1; i <= count; i++) {

    /*
     * The outer loop starts off by initializing i to 1, and the loop is repeated for successive values of i up to
     * count.
     * For each iteration of the outer loop, and therefore for each value of i, sum is initialized to 0, the inner
     * loop is executed, and the result displayed by the printf() statement. The inner loop accumulates the sum of
     * all the integers from 1 to the current value of i.
     */

    sum = 0L; /* Initialize the variable for inner loop */
    
    /*Calculate the sum of integers from 1 to i */
    for(j = 1; j <= i; j++)
      sum += j;
    
    /*
     * Each time the inner loop finishes, the printf() to output the value of sum is executed. Control then goes back to
     * to the beginning of the outer loop for the next iteration
     */

    printf("\n%d\t%ld", i, sum); /* Output the sum of 1 to i */
    
  }

  return 0;
}
