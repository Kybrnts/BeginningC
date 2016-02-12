/* 
 * A function with the prototype 
 *  
 * double power(double x, int n);
 * 
 * Should calculate and return the value of x^n. That is the expression power(5.0, 4) will evaluate
 * 5.0 * 5.0 * 5.0 * 5.0, which will result in the value 625.0
 * 
 * Implement the power() function as a recursive one (so it should call itself) and demonstrate its operation with a
 * suitable version of main();
 */
#include <stdio.h>

/* Function prototype */
double power(double, int);

int main(int argc, char *argv[]) {

  printf("\n2.0 to the power of 2 is %5.3f\n", power(2.0, 2));  
  printf("\n5.0 to the power of 4 is %5.3f\n", power(5.0, 4));

  printf("\n2.0 to the power of -1 is %5.3f\n", power(2.0, -1));
  printf("\n3.0 to the power of -1 is %5.3f\n", power(3.0, -1));
  printf("\n4.0 to the power of -1 is %5.3f\n", power(4.0, -1));
  printf("\n8.0 to the power of -1 is %5.3f\n", power(8.0, -1));

  printf("\n2.0 to the power of -2 is %5.3f\n", power(2.0, -2));
  printf("\n2.0 to the power of -3 is %5.3f\n", power(2.0, -3));

  return 0;
}

double power(double x, int n) {
  if(n < 0)
    return 1/(power(x, -1*n));
  if(n < 1)
    return 1;
  return power(x, n - 1)*x;
}
