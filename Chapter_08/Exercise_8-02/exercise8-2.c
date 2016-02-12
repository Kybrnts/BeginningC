/* Exercise 8.02 */
/*
 * Define a function that will return a string representation of an integer that is passed as the argument. For example,
 * if the argument is 25, the function will return "25". If the argument is -98, the function will return "-98".
 * Demonstrate the operation of your function with a suitable version of main().
 */
#include <stdio.h>   /* For standard i/o stuff                    */
#include <stdlib.h>  /* For using malloc and other stuff          */
#include <stdbool.h> /* For boolean data types                    */

enum digit {zero = '0', one = '1', two = '2', three = '3', four = '4',
	    five = '5', six = '6', seven = '7', eight = '8', nine = '9'};

char *intToString(int);
bool getSign(const int *);                        /* Gets the sign of a integer argument                   */
unsigned short getNumDigits(const int *);         /* Gets the number of digits of a whole number           */
enum digit getDigit(const int *, unsigned short); /* Gets the char of a digit in a specific position       */
unsigned tenToPW(const unsigned short *);         /* Returns the value of 10 to the power of the arg value */
unsigned absInt(const int *);                     /* Returns the absolute value of an integer              */

int main (void) {

  int inputInt;        /* Integer to be read from input              */
  char *intStr = NULL; /* String representation of the input integer */
  
  /* Prompt the user to enter a integer value */
  printf("\nEnter a integer (less than 10 digits long): ");
  scanf("%d", &inputInt);

  intStr = intToString(inputInt);
  if(!intStr) {
    printf("Finishing program..\n");
  }

  printf("String representation is %s\n\n", intStr);
  
  return 0;
}

/**********************************************************************************************************************
 * Function    : intToString											      *
 * Inputs      : int integer. Receives the integer to be converted to string.					      *
 * Outputs     : N/A												      *
 * Return      : char *. Reference to the string obtained after the conversion.					      *
 * Description : This is the function required by the exercise (see excersie description).			      *
 *               												      *
 **********************************************************************************************************************/
char *intToString(int integer) {

  bool negative = false;
  unsigned short i,
    num_len = 0;
  char *outstring = NULL;
  
  /* Exctract the sign of the integer         */
  negative = getSign(&integer);

  /* Calculate the required length            */
  num_len = getNumDigits(&integer) + 1;
  if(negative)
    num_len++;

  /* Allocate memory space for the string     */
  outstring = (char *)malloc(num_len*sizeof(char));
  if(!outstring) {
    printf("Error! Unable to allocate memory for \"outstring\".\n");
    return NULL;
  }

  i = 0;
  /* Prefix negative sign when required       */
  if(negative) {
    *(outstring + i++) = '-';
  }
  /* Fore each digit, get the digit character */
  while(i < num_len - 1) {
    *(outstring + i) = (char)getDigit(&integer, num_len - 2 - i);
    i++;
  }
  /* Add string terminator */
  *(outstring + i) = '\0';

  /* Return the result */
  return outstring;
}

/**********************************************************************************************************************
 * Function    : getSign                                                                                              *
 * Inputs      : const *int nteger. Receives a reference to the integer to which the sign is to be obtained           *
 * Outputs     : N/A												      *
 * Return      : Bool   											      *
 * Description : If the integer to which the received argument points to is less than zero, it returns true.          *
 *               Otherwise it will return false.                                     				      *
 *                                                                                                                    *
 **********************************************************************************************************************/
bool getSign(const int *integer) {
  if(*integer < 0)
    return true;
  return false;
}

/**********************************************************************************************************************
 * Function    : getNumDigitsa											      *
 * Inputs      : const int *integer. Receives a reference to the integer to which the number of decimal digits is to  *
 *               be obtained.										              *
 * Outputs     : N/A												      *
 * Return      : Unsigned short that represents the desired number of digits.					      *
 * Description : Divide the argument-referenced integer by 10 to the power of counter, as far as the results is       *
 *               greater than one, while counting in counter how many times the said division is made		      *
 * 														      *
 **********************************************************************************************************************/
unsigned short getNumDigits(const int *integer) {
  unsigned short count;
  unsigned absValue = absInt(integer);
  for(count = 1; absValue/tenToPW(&count) > 0u; count++);
  return count;
}

/**********************************************************************************************************************
 * Function    : getDigit											      *
 * Inputs      : > const int *integer. Receives a reference to a integer.					      *
 *               > unsigned short position. Receives the position of the digit to be extracted			      *
 * Outputs     : N/A												      *
 * Return      : The digit character representation for the integer value.					      *
 * Description : Returns the enum digit representaion of an integer in the specified position.			      *
 *               												      *
 **********************************************************************************************************************/
enum digit getDigit(const int *integer, unsigned short position) {
  unsigned short digit = (unsigned short)(absInt(integer)/tenToPW(&position)%10);
  switch(digit) {
  case 0: return zero; case 1: return one;
  case 2: return two; case 3: return three;
  case 4: return four; case 5: return five;
  case 6: return six; case 7: return seven;
  case 8: return eight; case 9: return nine;
  default: return zero;
  }
}

/**********************************************************************************************************************
 * Function    : tenToPow											      *
 * Inputs      : unsigned short *exp										      *
 * Outputs     : N/A												      *
 * Return      : unsigned int. The value to 10 to the power of the argument value.				      *
 * Description : Calculates the value of a 10-based power.							      *
 *               												      *
 **********************************************************************************************************************/
unsigned tenToPW(const unsigned short *exp) {
  unsigned short i;
  unsigned out = 1;
  for(i = 0; i < *exp; i++)
    out *= 10;
  return out;
}

/**********************************************************************************************************************
 * Function    : absInt												      *
 * Inputs      : const int *num. Reference to a whole number.							      *
 * Outputs     : N/A												      *
 * Return      : unsigned int. Returns the absolute value of the argument.					      *
 * Description : Calculates the absolute value of a integer number.						      *
 *               												      *
 **********************************************************************************************************************/
unsigned absInt(const int *num) {
  if(*num < 0)
    return (unsigned)(-1*(*num));
  else
    return (unsigned)(*num);
}
