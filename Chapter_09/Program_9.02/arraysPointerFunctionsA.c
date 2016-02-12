/* Program 9.2A Arrays of pointers of functions */
#include <stdio.h>

/* Function prototypes */
int sum(int, int);
int product(int, int);
int difference(int, int);

int main(void) {
  int a = 10,                    /* Initial value for a                  */
    b = 5,                       /* Initial value for b                  */
    result = 0,                  /* Storage for results                  */
    i;                           /* Index                                */
 
  /* Function pointers array declaration and initialization   */
  int (*pFun[])(int, int) = {sum, product, difference};  

  printf("Pasa\n");

  /* Execute each pointed function */
  for(i = 0; i < 3; i++) {
    result = pFun[i](a, b);
    printf("\ntresult = %d", result);
  }

  /* Call all the three functions through pointers in an expression */
  result = pFun[1](pFun[0](a, b), pFun[2](a, b));
  printf("\n\nThe product of the sum and the difference = %d\n", result);

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
