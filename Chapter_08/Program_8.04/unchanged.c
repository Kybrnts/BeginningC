/* Program 8.4 The change that doesn't */
#include <stdio.h>

int change(int number); /* Function prototype */
                        /* Variable names are not required but recommended */

int main(void) {
  int number = 10,      /* Starting value                  */
    result = 0;         /* Place to put the returned value */
  
  result = change(number);
  printf("In main, result = %d\tnumber = %d\n", result, number);
  return 0;
}

/* Definition of the function change() */
int change(int number) {
  number = 2 * number;
  printf("In function chcange, number = %d\n", number);
  return number;
}
