/* Program 9.3 Passing a pointer to a fucntion */
#include <stdio.h>

/* Function prototypes */
int sum(int, int);
int product(int, int);
int difference(int, int);
int anyFunction(int (*)(int, int), int x, int y); /* As variable parameters, function ones do not require to be named */
/*
 * The function named anyFunction() has three parameters. The first parameter type is a pointer to a function that
 * accepts two integer arguments and returns an integer. The last two parameters are integers that will be used in the
 * call of the function specified by the first parameter. The function anyFunction() itself returns an integer value
 * that will be the value obtained by calling the function indicated by the first argument.
 */

int main(void) {
  int a = 10,                /* Initial value for a            */
    b = 5,                   /* Initial value for b            */
    result = 0;              /* Storage for results            */

  int (*pF)(int, int) = sum; /* Pointer to function            */

  /* Passing a pointer to a function   */
  result = anyFunction(pF, a, b);
  printf("\nresult = %d", result);

  /* Passing the address of a function */
  result = anyFunction(product, a, b);
  printf("\nresult = %d", result);

  printf("\nresult = %d\n", anyFunction(difference, a, b));

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
int anyFunction(int (*pF)(int, int), int x, int y) {

  return pF(x, y);
}
/*
 * Within the definition of anyFunction(), the function specified by the pointer argument is called in the return
 * statement.
 * The name of the pointer pF is used, followed by the other two parameters as arguments to the function to be called.
 * The value of pfun and the values of the other two parameters x and y all originate in main().
 * 
 */
