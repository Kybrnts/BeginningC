/* Program 4.2 */
#include <stdio.h>

int main(void) {
  int count;                           /* The loop control variable               */

  printf("**************\n");          /* Draw the top of the box                 */
  for(count = 1; count <= 8; ++count)  /* Draw the sides of the box               */
    printf("*            *\n");        /* Draw a single pair of "*" for the sides */
  printf("**************\n");          /* Draw the bottom of the box              */
  return 0;
  /* The loop is controlled by the following:
   * 1. int i = 1; that initializes the control variable (counter). Is possible to use different types for this;
   * 2. Count <= 8; this is the continuation condition. Checked BEFORE each cycle. If it's evaluated to true the next
   *    cycle starts. Else, it skips to the next statement;
   * 3. ++count; which increments the counter in 1, at the end of each cycle.
   */
}
