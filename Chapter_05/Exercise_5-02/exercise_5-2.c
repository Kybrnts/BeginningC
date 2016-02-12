/* Exercise 5-2 */
/*
 * Exercise 5-2. Define an array, data, with 100 elements of type double. Write a loop that will store the following
 * sequence of values in corresponding elements of the array:
 * 
 *    1/(2*3*4), 1/(4*5*6), 1/(6*7*8) up to 1/(200*201*202)
 * 
 * Write another loop that will calculate the following:
 *
 *    data[0] - data[1] + data[2] - data[3] +..  -data[99]
 *  
 * Multiply the result of this by 4.0, add 3.0, and output the final result. Do you recognize the value that you get?
 */
#include <stdio.h>

int main(void) {
  double data[100];
  unsigned short n;
  double sum = 0.0;

  for(n = 1; n < 101; n++)
    data[n - 1] = 1.0/((2*n + 2)*(2*n + 1)*(2*n));

  for(n = 1; n < 101; n++)
    sum += ((n - 1)%2 == 0 ? data[n - 1] : -1.0*data[n - 1]);

  printf("Result: %.10le", 4.0*sum + 3.0);
  
  return 0;
}
