/* Program 4.8 While programming and summing integers */
#include <stdio.h>

int main(void) {
  unsigned long sum = 0UL ; /* The sum of integers                */
  unsigned i = 1U,          /* Indexes through integers           */
    count = 0U;             /* The count of integers to be summed */

  /* Get the count of the number of integers to sum */
  printf("Enter the number of integers you want to sum: ");
  scanf("%u", &count);

  /* Sum the integers from 1 to count */
  while(i <= count)
    sum += i++;

  /* Output the result */
  printf("Total of the first %u numbers is %lu\n", count, sum);

  return 0;
}
