/* Program 4.03 Sum the integers from 1 to a user-specified number */
#include <stdio.h>

int main(void) {
  unsigned long sum = 0UL; /* Stores the sum of the integers      */
  unsigned count = 0U,     /* The number of integers to be summed */
    i;                     /* Loop variable                       */
  /* Read the number of integers to be summed */
  printf("Enter the number of integers you want to sum: ");
  scanf("%u", &count);  
  /* Sum integers from 1 to count */
  for(i = 1U; i <= count; i++)
    sum += i;
  /* Output the result */
  printf("Total of first %d numbers is %ld\n", count, sum);
  return 0;
}
