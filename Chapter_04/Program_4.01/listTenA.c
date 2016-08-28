/* Program 4.1A List ten integers */
#include <stdio.h>

int main(void) {
  /* You can also declare the loop variable within the first loop control expression.
   * If so, the variable is local to the loop and does not exist once the loop has finished.
   * Note: This is ANSI C99 complaint but not C89 complaint.
   */
  for(int count = 1; count <= 10; ++count)
    printf("%d ", count);
  /* Due to below line, this code won't compile */
  printf("\nAfter the loop count has the value %d.\n", count);
  return 0;
}
