/* Exercise 9-2 */
#include <stdio.h>
/*
 * Implement functions with the following prototypes:
 */
double add(double a, double b);      /* Returns a+b */
double subtract(double a, double b); /* Returns a-b */
double multiply(double a, double b); /* Returns a*b */
double array_op(double array[], int size, double (*pfun)(double,double));

/*
 * The parameters for the array_op() function are the array to be operated on, the number of elements in the array, and
 * a pointer to a function defining the operation to be applied between successive elements. The array_op() function
 * should be implemented so that when the subtract() function is passed as the third argument, the function combines the
 * elements with alternating signs. So for an array with four elements, x1, x2, x3, and x4, it computes the value of
 * x1 - x2 + x3 - x4.
 * Demonstrate the operation of these functions with a suitable version of main().
 */

double array_sum(double [], int);   /* This one was used for help */

int main(int argc, char *argv[]) {

  double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};

  printf("Add: %5.3f\n", array_op(values, 5, add));
  printf("Multiply: %5.3f\n", array_op(values, 5, multiply));
  printf("Subtract: %5.3f\n", array_op(values, 5, subtract));

  return 0;
}

double add(double a, double b) {
  return a + b;
}
double subtract(double a, double b) {
  return a - b;
}
double multiply(double a, double b) {
  return a*b;
}
double array_op(double array[], int size, double (*pf)(double, double)) {
  if(size < 2)
    return array[0];
  return pf(array[0], array_op(&array[1], size - 1, pf));
}

double array_sum(double array[], int size) {
  if(size < 2)
    return array[0];
  return array[0] + array_sum(&array[1], size - 1);
}
