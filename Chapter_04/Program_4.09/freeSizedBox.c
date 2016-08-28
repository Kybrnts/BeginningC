/* Program 4.9 Output a box w/given width and height */
#include <stdio.h>
#define MIN_SIZE_DFLT 3U


int main(void) {
  const unsigned MIN_SIZE = MIN_SIZE_DFLT; /* Maximum width and height values */
  unsigned width = 0U,                     /* User slected width size         */
    height = 0U,                           /* User selected height size       */
    i, j;                                  /* Loop control variables          */

  /* Read in required width and height */
  printf("Enter values for the width and heigth (minumum of %u): ", MIN_SIZE);
  scanf("%u%u", &width, &height);
  /* Validate entered width and height values */
  if(width < MIN_SIZE) {
    printf("Width value of %u is too small. Setting it to %u.\n", width, MIN_SIZE);
    width = MIN_SIZE;
  }
  if(height < MIN_SIZE) {
    printf("Heigth value of %u is too small. Setting it to %u.\n", height, MIN_SIZE);
    height = MIN_SIZE;
  }
  /* Output the top of the box w/width asterisks */
  for(i = 0; i < width; i++)
    printf("*");
  printf("\n");
  /* Output height - 2 rows of width characters with * at each end and spaces inside  */
  for(j = 0; j < height - 2U; j++) {
    printf("*");                   /* First asterisk        */
    for(i = 0; i < width - 2U; i++) /* Next, draw the spaces */
      printf(" ");
    printf("*\n");                 /* Last asterisk         */
  }
  /* Output the bottom of the box w/width asterisks */
  for(i = 0; i < width; i++)
    printf("*"); 
  printf("\n");                    /* Newline at the end    */
  return 0;
}
