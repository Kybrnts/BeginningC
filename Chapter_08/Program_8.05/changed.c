/* Program 8.5 The change that does */
#include <stdio.h>

int change(int *pnumber);

int main(void) {
  int number = 10,
    *pnumber = &number,
    result = 0;
  
  result = change(pnumber); /* We*/
  printf("In main, result = %d\tnumber = %d\n", result, number);
  return 0;
}

/* Definition of the function change() */
int change(int *pnumber) {
  *pnumber *= 2;
  printf("In function change, *pnumber = %d\n", *pnumber);
  return *pnumber;
}
