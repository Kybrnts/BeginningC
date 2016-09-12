/* Exercise 5-2 */
/* Define an array, data, with 100 elements of type double. Write a loop that will store the following sequence of
 * values in corresponding elements of the array:
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
#define DATASIZE 100U

int main(void) {
  double data[DATASIZE];
  unsigned n;
  double sum = 0.0;

  /* Initialize the array using provided formula */
  for(n = 1U; n <= DATASIZE; n++)
    data[n - 1U] = 1.0/((2*n)*(2*n+1)*(2*n + 2));
  /* Calculate the requested sum                 */
  for(n = 1U; n <= DATASIZE; n++)
    sum += ((n - 1U)%2U == 0U ? data[n - 1U] : -data[n - 1U]);
  /* Display the result                          */
  printf("Result: %.10f\n", 4.0*sum + 3.0);
  return 0;
}
