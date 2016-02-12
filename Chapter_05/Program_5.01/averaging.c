/* Program 5.1 Averaging ten numbers without storing the numbers */
#include <stdio.h>

int main(void) {
  int number = 0,         /* Stores a number */
    count = 10,           /* Number of values to be read */
    i;                    /* The uninitialized control variable */
  long sum = 0L;          /* Sum of the numbers */
  float average = 0.0f;   /* Average of the numbers */

  /* Read the ten numbers to be averaged */
  for(i = 0; i < count; i++) {
    printf("Enter grade: ");  /* Read a number */
    scanf("%d", &number);     
    sum += number;            /* Add it to sum */
  }

  average = (float)sum/count; /* Calculate the average */
  
  printf("\nAverage of the ten numbers entered is: %f\n", average);
  
  return 0;
}
