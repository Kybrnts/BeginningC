/* Program 4.03C89 Sum the integers from 1 to a user-specified number */
/*
 * Since some compilers don't support variable declaration inside loops
 * we provide this other version for greater compatibility.
 */
#include <stdio.h>

int main(void) {
  long sum = 0L; /* Stores the sum of the integers */
  int count = 0; /* The number of integers to be summed */
  int i = 0;     /* The control variable */


  /* Read the number of integers to be summed */
  printf("\nEnter the number of integers you want to sum:");
  scanf(" %d", &count);
  
  /* Sum integers from 1 to count */
  for(i = 1; i <= count; i++)
    sum += i;

  /* Output the result */
  printf("\nTotal of first %d numbers is %ld\n", count, sum);

  return 0;
}
