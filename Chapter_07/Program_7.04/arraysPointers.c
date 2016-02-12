/* Program 7.4 Arrays and pointers - A simple program */
#include <stdio.h>

int main(void) {
  char multiple[] = "My string";

  char *p = &multiple[0];
  printf("\nThe address of the first array element: %p", p);
  
  p = multiple;
  printf("\nThe address obtained from the array name: %p\n", p);
  
  return 0;
}
/*
 * You can conclude from the output of this program that the expression &multiple[0] produces the same value as the
 * expression multiple. This is what you might expect because multiple evaluates to the address of the first byte of the
 * array, and &multiple[0] evaluates to the first byte of the first element of the array, and it would be surprising if
 * these were not the same.
 */
