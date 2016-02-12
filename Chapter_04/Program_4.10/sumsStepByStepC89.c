/* Program 4.10C89 Sums of integers with a while loop nested in a for loop */
#include <stdio.h>

int main(void) {
  long sum = 1L; /* Stores the sum of integers */
  int count = 0; /* Number of sums to be calculated */
  int i, j;      /* Loops control variables */

  /* Prompt for, and read the input count */
  printf("\nEnter the number of integers you want to sum: ");
  scanf(" %d", &count);

  for(i = 1; i <= count; i++) {
    sum = 1L;      /* Initialize sum for the inner loop */
    j = 1;         /* Initialize integer to be added */
    printf("\n1");

    /* Calculate the sums of integers from 1 to i */
    
    while (j < i) {
      sum += ++j;
      printf("+%d", j);      /* Output +j - on the same line */
    }
    printf(" = %ld\n", sum); /* Output = sum */
  }
  return 0;
}
