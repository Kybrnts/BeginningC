/* Exercise 3-1 */
/* write a program that will first allow a user to choose one of two options:
 * 1. Convert a temperature from degrees Celsius to degrees Fahrenheit.
 * 2. Convert a temperature from degrees Fahrenheit to degrees Celsius.
 * 
 * The program should then prompt for the temperature value to be entered and output the new
 * value that results from the conversion. To convert from Celsius to Fahrenheit you can multiply
 * the value by 1.8 and then add 32. To convert from Fahrenheit to Celsius, you can subtract 32
 * from the value, then multiply by 5, and divide the result by 9.
 */
#include <stdio.h>
#define MC 9/5    /* Value of m in y = mx + n for conversion from celsius to farenheit */
#define NC 32     /* Value of n in previous equation */
#define MF 5/9    /* Value of m in y = mx + n for conversion from farenheit to celsius */
#define NF -160/9 /* Value of n in previous equation */

int main(void) {

  /* Declare variables of the right types */
  char unit = 0;        /* Stores an input character */
  _Bool goahead = 1; /* Stops execution when input a wrong conversion type */
  double degrees = 0.0, /* Sotres the input degrees */
    m = 0.0,            /* Value of m in y = mx + n for conversion */
    n = 0.0;            /* Value of n in the previous equation */

  /* Prompt the user to choose the type of conversion */
  printf("\nPlease enter the unit of the temperature you want to convert from."
         "\nCelsius (C) or Farenheit (F)?: ");
  scanf("%c", &unit);

  /* Try to change the input to lowercase */
  if(unit <= 'a')
    unit += 'a' - 'A';
  
  /* Verify the selected conversion type */
  switch(unit) {
  case 'c':
    printf("\nConverting from CELSIUS to FARENHEIT.");
    m = (double)MC;
    n = (double)NC;
    break;

  case 'f':
    printf("\nConvertinf from FARENHEIT to CELSIUS.");
    m = (double)MF;
    n = (double)NF;
    break;

  default:           /* Wrong conversion type */
    printf("\nWrong conversion type! Try again.");
    goahead = 0;  /* Prevent further execution */
  }
  /* From now on when goahead is set tu true, if "unit" is not set to 'c', it is set to 'f' */
  
  /* Continue with further calculations if necessary */
  if(goahead) {
    /* Prompt the user to enter the temperature */
    printf("\nPlease enter the temperature in %s degrees: ",
	   unit == 'c' ? "CELSIUS" : "FARENHEIT");
    /* Read temperature from keyboard */
    scanf("%lf", &degrees);
        
    /* Output the result */
    printf("\nTemperature in %s is %.2f degrees.", 
	   unit == 'c' ? "FARENHEIT" : "CELSIUS",
	   m*degrees + n);
  }

  return 0;
}
