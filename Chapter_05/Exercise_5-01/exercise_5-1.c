/* Exercise 5-1 */
/*
 * Write a program that will read five values of type double from the keyboard and store them in an array. Calculate
 * the reciprocal of each value (the reciprocal of a value x is 1.0/x) and store it in a separate array. Output the
 * values of the reciprocals, and calculate and output the sum of the reciprocals.
 */
#include <stdio.h>

int main(void) {
  double numbers[5],
    sum = 0;
  int i;
  char none_zero = 1;
  
  /* Prompt user to enter five non-zero numbers and store them all */
  printf("\nEnter five non-zero decimal numbers:\n");

  /* Read 5 values or stop if the last readed is zero */
  for(i = 0; i < 5 && none_zero; i++) {
    /* Store a double value */
    printf("#%d> ", i+1);
    scanf("%lf", &numbers[i]);
    if(numbers[i] == 0)
      none_zero = 0;
  }
  
  /* Prevent from unnecessary execution */
  if(!none_zero) {
    printf("\nError! You entered a zero");
    return 0;
  }
  
  /* Output the list of the reciprocals and calculate their sum */
  printf("\nList of reciprocals:");
  for(i = 0; i < 5; i++) {
    printf("\n#%d> %f", i+1, 1/numbers[i]);
    sum += 1/numbers[i];
  }
  
  /* Output the sum of the reciprocals */
  printf("\n\nThey add up: %f", sum);

  return 0;
}
