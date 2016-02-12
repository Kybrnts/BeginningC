/* Program 9.7 Calculation the average using variable argument list */
#include <stdio.h>
#include <stdarg.h>

/* Function prototype */
double average(double, double, ...);

int main(void) {

  double val1 = 10.5, val2 = 2.5;
  int num1 = 6, num2 = 5;
  long num3 = 12L, num4 = 20L;

  printf("\n Average = %f", average(val1, 3.5, val2, 4.5, 0.0));
  printf("\n Average = %f", average(1.0, 2.0, 0.0));
  printf("\n Average = %f\n", average((double)num2, val2, (double)num1, (double)num4, (double)num3, 0.0));

  return 0;
}

/* Function declaration to calculate the average of a variable number of arguments */
double average(double v1, double v2, ...) {

  va_list parg;         /* Pointer for variable argument list         */
  double sum = v1 + v2, /* Accumulate sum of the arguments            */
    value = 0.0;        /* Current argument value                     */
  int count = 2;        /* Count of number of arguments               */
  
  va_start(parg, v2);   /* Initialize the pointer to current argument */
  
  while((value = va_arg(parg, double)) != 0.0) {
    sum += value;
    count++;
  }

  va_end(parg);        /* End variable argument process               */
  return sum/count;
}
