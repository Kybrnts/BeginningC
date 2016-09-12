/* Exercise 5-1 */
/* Write a program that will read five values of type double from the keyboard and store them in an array. Calculate
 * the reciprocal of each value (the reciprocal of a value x is 1.0/x) and store it in a separate array. Output the
 * values of the reciprocals, and calculate and output the sum of the reciprocals.
 */
#include <stdio.h>
#define MAXNUMS 5U
enum TBool { false = 0, true = 1 };

int main(void) {
  double numbers[MAXNUMS];
  long double sum = 0;
  unsigned i;
  enum TBool none_zero = true;
  
  /* Prompt user to enter five non-zero numbers and store them all */
  printf("Enter %d non-zero decimal numbers:\n", MAXNUMS);
  /* Read 5 values or stop if the last readed is zero              */
  for(i = 0U; i < MAXNUMS && none_zero; i++) {
    /* Store a double value */
    printf(" #%u> ", i + 1U);
    scanf("%lf", &numbers[i]);
    if(numbers[i] == 0.0)
      none_zero = false;
  }
  /* Prevent from unnecessary execution                            */
  if(!none_zero) {
    printf("Error! You entered a zero\n");
    return 0;
  }
  /* Output the list of the reciprocals and calculate their sum    */
  printf("List of reciprocals:\n");
  for(i = 0U; i < MAXNUMS; i++) {
    printf(" #%u> %f\n", i + 1U, 1/numbers[i]);
    sum += 1/numbers[i];
  }
  /* Output the sum of the reciprocals                             */
  printf("They add up: %Lf\n", sum);
  return 0;
}
