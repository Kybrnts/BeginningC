/* Program 5.1 Averaging ten grades without storing them */
#include <stdio.h>

int main(void) {
  int grade = 0;          /* Stores a grade              */
  unsigned count = 10U,   /* Number of values to be read */
    i;                    /* Loop control variable       */
  long sum = 0L;          /* Sum of the grades           */
  float average = 0.0f;   /* Average of the grades       */

  /* Read the ten numbers to be averaged */
  for(i = 0U; i < count; i++) {
    printf("Enter grade: ");  /* Read a number         */
    scanf("%d", &grade);     
    sum += grade;             /* Add it to sum         */
  }
  average = (float)sum/count; /* Calculate the average */
  /* Remember to cast sum to a float BEFORE doing the division. Otherwise its value will be truncated before being
   * stored in average.
   */
  printf("Average of the ten numbers entered is: %f\n", average);
  
  return 0;
}
