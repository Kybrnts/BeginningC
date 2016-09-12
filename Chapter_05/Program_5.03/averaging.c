/* Program 5.3 Averaging ten grades - storing numbers the easy way */
#include <stdio.h>

int main(void) {
  int grades[10U];         /* Array storing 10 values     */
  /* Remember:
   * * An array is a fixed number of data items that are all of the same type;
   * * The data items in an array are referred to as elements;
   * * The elements in an array are all of the SAME choosen type;
   * * The number between square brackets defines how many elements the array contains and is called "array dimension";
   * * An array has a type, which is a combination of the element type and the number of elements in the array. Thus
   *   two arrays are of the same type if they have the same number of elements of the same type;
   * * Each of the data items stored in an array is accessed by the same name. We select a particular element by using
   * * an index value between square brackets following the array name;
   * * Index values are sequential integers STARTING FROM ZERO, So 0 is the index value for the first array element;
   * * We can specify an index for an array element by an expression in square brackets following the array name.
   */
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
  printf("Average of the ten grades entered is: %.2f\n", average);
  /* Tell the compiler to convert sum (which is declared as type long) into type float to ensure that the division is
   * done using floating-point values, so we don't discard any fractional part of the result.
   */
  return 0;
}
