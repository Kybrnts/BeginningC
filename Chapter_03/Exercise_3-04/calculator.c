/* Exercise 3-4 */
/* Modify the last example in the chapter that implemented a calculator so that the user is given the option to enter y
 * or Y to carry out another calculation, and n or N to end the program. (Note: You'll have to use a goto statement for
 * this at this time, but you'll learn a better way of doing this in the next chapter).
 */
#include <stdio.h>

int main(void) {
  double number1 = 0.0, /* First operand value a decimal number */
    number2 = 0.0;      /* Second operand value a decimal number */
  char operation = 0,   /* Operation - must be +, -, *, /, or % */
    retry = 0;          /* Stores yes or no for retry questin's answer */
  
  /* Get data from user */
 entercalc:  /* Hook point for the goto statement */
  printf("Enter the calculation\n> ");
  scanf("%lf %c %lf", &number1, &operation, &number2);  
  /* Using the scanf function to read the data in this way, the user don't need to enter each input data in a separate
   * line. All that's required is one or more whitespace (i.e. space, tab or end of line) characters between each input
   * item.
   */
  /* Processing input data */
  switch(operation) {
  case '+': /* No checks necessary for addition */
    printf("= %f\n", number1 + number2);
    break;
  case '-': /* No checks necessary for substraction */
    printf("= %f\n", number1 - number2);
    break;
  case '*': /* No checks necessary for multiplication */
    printf("= %f\n", number1 * number2);
    break;
  case '/': /* Check second non-zero second operand */
    if(number2 == 0)
      printf("\a%s!\n", "Division by zero error");
    else
      printf("= %f\n", number1 / number2);
    break;
  case '%': /* Check second non-zero second operand */
    if((long)number2 == 0)
      printf("\a%s!\n", "Division by zero error");
    else
      printf("= %ld\n", (long)number1 % (long)number2);
    break;
  default : /* Operation is illegal if we get to this point */
    printf("\a%s!\n", "Illegal operation");
  }
  /* Prompt the user for trying again */
  printf("Do you feel like trying again? (Y/N): ");
  scanf(" %c", &retry);
  /* /!\ - Here the leading space in the format specifier string is CRITICAL - /!\
   * We must bare in mind that whenever we enter a character for a scanf() call, besides entering the character itself,
   * we also press RET. This keypress sends a '\n' to the STDIN which will be scanned by any subsecuent scanf() call. If
   * that call scans for a character (instead of a numeric type), it will assign the '\n' to it. 
   * If we want to skip this EOL, we can "consume" any number of previously non read whitespace chars with a leading
   * whitespace in the format specifier string.
   * See below link for a larger explanation on the subject: 
   * http://stackoverflow.com/questions/7166197/why-does-a-space-in-my-scanf-statement-make-a-difference
   */
  /* Try to change the input to lowercase */
  if(retry <= 'a')
    retry += 'a' - 'A';
  switch(retry) {
  case 'y':
    printf("Ok, let's try again..\n");
    retry = 0;
    goto entercalc;
  case 'n':
    printf("Ok, bye then.\n");
    break;
  default :
    printf("Wrong option type. Finishing..\n");
  }
  return 0;
}
