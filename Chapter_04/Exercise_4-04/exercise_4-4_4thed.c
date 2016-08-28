/* Exercise 4-4 4th Edition */
/* This exercise was included in the previous version of the book but not in the current one.
 * Use nested loops to output a box bounded by asterisks as in Program 4.2, but with a width and height that's entered
 * by the user.
 */
#include <stdio.h>

int main(void) {
  unsigned width = 0U, /* Stores the width of the box  */
    height = 0U;       /* Stores the height of the box */
  unsigned i,j;        /* Loop control variables       */
  
  /* Prompt the user to enter the dimensions of the box */
  printf("Enter the width and the height of the box separated by spaces: ");
  scanf("%u %u", &width, &height);
  /* Display the box (using nested loops)*/
  for(i = 1U; i <= width; i++) {
    for(j = 1U; j <= height; j++)
      printf("%c", i % width < 2U ?  /* Each time i values 1 or width, place an *; */
	     '*' : j % height < 2U ? /* Else when j values 1 or height place an *; */
	     '*' : ' ');             /* Otherwise, just place a blank.             */
    printf("\n");                    /* At the end of each "j" loop, place an EOL  */
  }
  printf("\n");
  return 0;
}
