/* Program 5.4 Reusing the numbers stored */
#include <stdio.h>

int main(void) {
  int grades[10U];      /* Array storing 10 values     */
  unsigned count = 10U, /* Number of values to be read */
    i;                  /* Array index                 */
  long sum = 0L;        /* Sum of the numbers          */
  float average = 0.0f; /* Average of the numbers      */

  printf("Enter the 10 grades:\n");
  /* Read ten numbers to be averaged, one by one                      */
  for(i = 0U; i < count; i++) {
    printf("%2u> ", i + 1U);  /* Print the prompt for current element */
    scanf("%d", &grades[i]);  /* Read a grade                         */
    sum += grades[i];         /* Accumulate it in sum                 */
  }
  average = (float)sum/count; /* Calculate the average                */
  /* Tell the compiler to convert sum (which is declared as type long) into type float to ensure that the division is
   * done using floating-point values, so we don't discard any fractional part of the result.
   */
  /* List all the grades                                              */
  for(i = 0U; i < count; i++)
    printf("Grade number %2u is %3d\n", i + 1U, grades[i]);
  printf("Average of the ten grades entered is: %.2f\n", average);
  return 0;
}
