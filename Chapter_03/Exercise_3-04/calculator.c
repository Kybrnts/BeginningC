/* Exercise 3-4 */
/*
 * Modify the last example in the chapter that implemented a calculator so that the user is given
 * the option to enter y or Y to carry out another calculation, and n or N to end the program.
 * (Note: You'll have to use a goto statement for this at this time, but you'll learn a better way 
 * of doing this in the next chapter).
 */
#include <stdio.h>

int main(void) {
  double number1 = 0.0, /* First operand value a decimal number */
    number2 = 0.0;      /* Second operand value a decimal number */
  char operation = 0,   /* Operation - must be +, -, *, /, or % */
    retry = 0;          /* Stores yes or no for retry questin's answer */

  /* Get data from user */
 entercalc: /* Hook point for the goto statement */
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
  
  /* Prompt the user for trying again */
  printf("\n\nDo you feel like trying again? (Y/N): ");
  scanf("%c", &retry);

  /* Try to change the input to lowercase */
  if(retry <= 'a')
    retry += 'a' - 'A';

  switch(retry) {
  case 'y':
    printf("\n\nOk, let's try again..");
    goto entercalc;
    break;

  case 'n':
    printf("\n\nOk, bye then.");
    break;
  default :
    printf("\n\nWrong option type, finishing.");
  }
  
  return 0;
}