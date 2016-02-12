/* Program 4.4. Summing integers - compact version */
#include <stdio.h>

int main(void) {
  long sum = 0L; /* Stores the sum of integers */
  int count = 0; /* The number of integers to be summed */

  /* Read the number of integers to be summed */
  printf("\nEnter the number of integers you whant to sum: ");
  scanf(" %d", &count);
  
  /* Sum integers from 1 to count */
  for(int i = 1; i <= count; sum += i++);
  /*
   * The loop statement is empty: it's just the semicolon after the closing parenthesis. This expression adds the value
   * of i to sum and then increments i ready for the next iteration. It works this way because you've used the postfix
   * form of the increment operator. If you use the prefix form here, you'll get the wrong answer, because the total in
   * sum will include the number count+1 from the first iteration of the loop, instead of just count.
   */
  
  printf("\nTotal of the first %d numbers is %ld\n", count, sum);

  return 0;
}
