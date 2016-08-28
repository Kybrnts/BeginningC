/* Program 4.1 List ten integers */
#include <stdio.h>

int main(void) {
  int count = 1;
  for ( ; count <= 10; ++count)  /* The first expression executes once, when the loop starts     */
                                 /* The second is evaluated at the beginning of each loop cycle  */
                                 /* The third is executed at the end of each loop cycle          */
    printf("%d ", count);        /* This statement is executed inmediately after each evaluation */
  /* This is executed after the last cycle */
  printf("\nAfter the loop count has the value %d.\n", count);
  return 0;
}
