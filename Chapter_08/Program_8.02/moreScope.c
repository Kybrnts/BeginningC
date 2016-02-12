/* Program 8.2 More scope in this one */
#include <stdio.h>

int main(void) {
  int count = 0;         /* Declared in the outer block  */
  
  do{
    int count = 0; /* This is another variable also called count */
    ++count;       /* This applies to the inner count            */
    printf("\ncount = %d", count);
    
  } while(++count <= 8); /* This works w/the outer count */

  /* Inner count is dead, this is outer */
  printf("\ncount = %d\n", count);

  return 0;
}
