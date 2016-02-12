/* Program 4.5 Summing integers backward */
#include <stdio.h>
int main(void) {
  
  long sum = 0L; /* Stores the sum of integers */
  int count = 0, /* The number of integers to be summed */
    i;           /* The for loop control variable */

  /* Read the number of integers to be summed */
  printf("\nEnter the number of integers you whant to sum: ");
  scanf(" %d", &count);  

  /* Sum integers from count down to 1 */
  for(i = count; i >= 1; sum += i--);
  /*
   * The only change is in the loop control expressions. The loop counter is initialized to count, rather than to 1, and
   * it's decremented on each iteration. The effect is to add the values count, count-1, count-2, and so on, down to 1.
   * Again, if you used the prefix form, the answer would be wrong, because you would start with adding count-1 instead
   * of just count.
   */

  /* Output the result */
  printf("\nTotal of the first %d numbers is %ld\n", count, sum);

  return 0;
}

/*
 * Just to keep any mathematically inclined readers happy, I should mention that it's quite unnecessary to use a loop to
 * sum the first n integers. The following tidy little formula for the sum of the integers from 1 to n will do the trick
 * much more efficiently:
 *                       n*(n+1)/2
 * However, it wouldn't teach you much about loops, would it?
 */
