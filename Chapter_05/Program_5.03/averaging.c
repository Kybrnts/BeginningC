/* Program 5.3 Averaging ten numbers - storing numbers the easy way */
#include <stdio.h>

int main(void) {
  int numbers[10],       /* Array storing 10 values */
    count = 10,          /* Number of values to be read */
    i;
  long sum = 0L;         /* Sum of the numbers */
  float average = 0.0f;  /* Average of the numbers */

  printf("\nEnter the ten numbers to be averaged:\n"); /* Prompt for the input */

  /* Read the ten numbers to be averaged */
  for(i = 0; i < count; i++) {
    printf("%2d> ", i+1);
    scanf("%d", &numbers[i]); /* Read a number */
    sum += numbers[i];        /* Add it to the sum */
  }
  average = (float)sum/count; /* Calculate the average */
  /*
   * Tell the compiler to convert sum (which is declared as type long) into type float to ensure that the division is
   * done using floating-point values, so you don't discard any fractional part of the result.
   */
  
  printf("\nAverage of the ten numbers entered is: %f\n", average);
  
  return 0;
}
