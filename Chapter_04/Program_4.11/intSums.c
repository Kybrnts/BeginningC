/* Program 4.11 Sums of integers with a while loop nested in a for loop */
#include <stdio.h>

int main(void) {
  unsigned long sum = 1UL; /* Stores the sum of integers      */
  unsigned i, j = 1U,      /* Loop control variables          */
    count = 0U;            /* Number of sums to be calculated */
  
  /* Prompt for, and read the input count    */
  printf("Enter the number of integers you want to sum: ");
  scanf("%u", &count);
  
  /* Calculate and display each sum          */
  for(i = 1U; i <= count; i++) {
    sum = 1UL; /* Initialize sum for the inner loop        */
    j = 1U;
    printf("1");
    /* Calculate sum of integers from 1 to i */
    while(j < i) {
      sum += ++j;
      printf(" + %u", j);  /* Output +j - on the same line */
    }
    printf(" = %lu\n", sum); /* Output = sum               */
  }
  return 0;
}
