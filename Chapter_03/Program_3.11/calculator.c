/* Program 3.14 A calculator */
#include <stdio.h>

int main(void) {
  double number1 = 0.0, /* First operand value a decimal number */
    number2 = 0.0;      /* Second operand value a decimal number */
  char operation = 0;   /* Operation - must be +, -, *, /, or % */

  /* Get data from user */
  printf("\nEnter the calculation\n");
  scanf("%lf %c %lf", &number1, &operation, &number2);  
  /*
   * Using the scanf function to read the data in this way, the user don't need to enter each input data in
   * a separate lane. All that's required is one or more whitespace (i.e. space, tab or end of line) characters
   * between each input item.
   */
  
  /* Processing input data */
  switch(operation) {
  case '+': /* No checks necessary for addition */
    printf("= %lf\n", number1 + number2);
    break;

  case '-': /* No checks necessary for substraction */
    printf("= %lf\n", number1 - number2);
    break;

  case '*': /* No checks necessary for multiplication */
    printf("= %lf\n", number1 * number2);
    break;

  case '/': /* Check second non-zero second operand */
    if(number2 == 0)
      printf("\n\n\aDivision by zero error!\n");
    else
      printf("= %lf\n", number1 / number2);
    break;

  case '%': /* Check second non-zero second operand */
    if((long)number2 == 0)
      printf("\n\n\aDivision by zero error!\n");
    else
      printf("= %ld\n", (long)number1 % (long)number2);
    break;

  default : /* Operation is illegal if we get to this point */
    printf("\n\n\aIllegal operation!\n");
    break;
  }
  
  return 0;
}
