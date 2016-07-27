/* Program 2.16 Using the type char */
#include <stdio.h>

int main(void) {
  char first = 'A',
    second = 'B',
    last = 'Z';

  char number = 40;      /* Initializing a char with an integer value */
  /* 
   * The value must be within the range of values that a 1-byte variables can store, hence being of the signed type its
   * value must be between -128 and 127.
   */

  char ex1 = first + 2,  /* Add 2 to 'A' */
    ex2 = second - 1,    /* Substract 1 from B */
    ex3 = last + 2;      /* Add 2 to 'Z' */

  /* This statement interprets the stored values as characters that should be output left-aligned with a width of 5. */
  printf("Character values %-5c%-5c%-5c\n", ex1, ex2, ex3);
  printf("Numerical equivalents %-5d%-5d%-5d\n", ex1, ex2, ex3);
  printf("The number %d is the code for the character %c\n", number, number);
  
  return 0;
}
