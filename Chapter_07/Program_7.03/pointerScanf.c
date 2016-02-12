/* Program 7.3 Pointer argument to scanf */
#include <stdio.h>

int main(void) {
  int value = 0;
  int *pvalue = NULL;
  
  pvalue = &value;                     /* Set pointer to refer the value */

  printf("Input an integer: ");
  scanf(" %d", pvalue);                /* Read it via the pointer        */
  
  printf("\nYou entered %d\n", value); /* Output the value entered       */
  return 0;
}
