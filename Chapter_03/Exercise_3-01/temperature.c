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
#define MC 9.0/5    /* Value of m in y = mx + n for conversion from celsius to farenheit */
#define NC 32       /* Value of n in previous equation */
#define MF 5.0/9    /* Value of m in y = mx + n for conversion from farenheit to celsius */
#define NF -160.0/9 /* Value of n in previous equation */

int main(void) {
  /* Declare variables of the right types */
  char unit = 'c';      /* Stores an input character                          */
  int goahead = 1;      /* Stops execution when input a wrong conversion type */
  double degrees = 0.0, /* Sotres the input degrees                           */
    m = 0.0,            /* Value of m in y = mx + n for conversion            */
    n = 0.0;            /* Value of n in the previous equation                */

  /* Prompt the user to choose the type of conversion */
  printf("Please enter the unit of the temperature you want to convert from\n"
         "Celsius (C) or Farenheit (F)?: ");
  scanf("%c", &unit);

  /* Try to change the input to lowercase */
  if(unit <= 'a')
    unit += 'a' - 'A';
  
  /* Verify the selected conversion type */
  switch(unit) {
  case 'c':
    printf("Converting from CELSIUS to FARENHEIT.\n");
    m = MC;
    n = NC;
    break;
  case 'f':
    printf("Convertinf from FARENHEIT to CELSIUS.\n");
    m = MF;
    n = NF;
    break;
  default:           /* Wrong conversion type */
    printf("Wrong conversion type! Try again.\n");
    goahead = 0;  /* Prevent further execution */
  }
  /* From now on when goahead is set tu true, if "unit" is not set to 'c', it is set to 'f' */

  /* Continue with further calculations if possible */
  if(goahead) {
    /* Prompt the user to enter the temperature */
    printf("Please enter the temperature in %s degrees: ",
	   unit == 'c' ? "CELSIUS" : "FARENHEIT");
    /* Read temperature from keyboard */
    scanf("%lf", &degrees);        
    /* Output the result */
    printf("Temperature in %s is %.1f degrees.\n", 
	   unit == 'c' ? "FARENHEIT" : "CELSIUS",
	   m*degrees + n);
  }
  return 0;
}
