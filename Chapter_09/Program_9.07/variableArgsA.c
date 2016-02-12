/* Program 9.7A Calculation the average using variable argument list */
/* In this version we redefine the function so that the number of    */
/* values to be averaged is to be passed to the function.            */
#include <stdio.h>
#include <stdarg.h>

/* Function prototype */
double average(int nargs, double arg1, ...);

int main(void) {

  double val1 = 10.5, val2 = 2.5;
  int num1 = 6, num2 = 5;
  long num3 = 12L, num4 = 20L;

  average(2, 1.0, 1.0);

  return 0;
}

double average(int n, double v1, ...) {
  va_list parg;
  double sum = 0.0;
  int i = 0;
  for(va_start(parg, v1); i < n; i++)
    /* sum += va_arg(parg, double); */
    printf("%f ", va_arg(parg, double));
  va_end(parg);
  return i ? sum/n : 0.0;
}
