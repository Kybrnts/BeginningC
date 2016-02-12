/* Program 9.1 Pointing to functions */
#include <stdio.h>

/* Function prototypes */
int sum(int, int);
int product(int, int);
int difference(int, int);

int main(void) {
  
  int a = 10,             /* Initial value for a            */
    b = 5,                /* Initial value for b            */
    result = 0;           /* Storage for results            */

  int (*pFun)(int, int);  /* Function pointer declaration   */

  pFun = sum;             /* Now points to function sum()   */
  result = pFun(a, b);    /* Call sum through pointer       */
  printf("\npFun = sum\tresult = %d", result);

  pFun = product;         /* Now points to product()        */
  result = pFun(a, b);    /* Call product through pointer   */
  printf("\npFun = product\tresult = %d", result);

  pFun = difference;      /* Finally points to difference() */
  result = pFun(a, b);    /* And call difference()          */
  printf("\npFun = difference\tresult = %d\n", result);
  
  return 0;
}

/* Function declarations */
int sum(int x, int y) {

  return x + y;
}
int product(int x, int y) {

  return x*y;
}
int difference(int x, int y) {

  return x - y;
}
