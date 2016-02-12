/* Program 7.15 An improved calculator */
/*
 * New version of chapter's 3 calculator, now using pointers.
 * 
 * New features:
 * -------------
 * * Allow use of signed decimals, including a decimal point w/an optional leading sign, - or + as well as signed 
 *   integers.
 * * Permit expressions to combine multiple operations (e.g. 2.5 + 3.7 - 6/6)
 * * Support for the '^' operator, which will mean "rised to the power or", so that 2^3 will produce 8.
 * * Allow a line to operate on the previous result. If the previous is 2.5 then writing = *2 + 7 will produce 12.
 * * An input line that starts w/an assignment operator will automatically assume the left operand is the previous
 *   result
 * 
 * Overall operations:
 * -------------------
 * 1. Read an input string entered by the user and exit if it is quit.
 * 2. Check for an = operator, and if there is one skip looking for the first operand.
 * 3. Search for an operator followed by an operand, executing each operator in turn unitl the end of the input string.
 * 4. Display the result and go back to step 1.
 */

#include <stdio.h>     /* Standard Input/Output                    */
#include <string.h>    /* For string functions                     */
#include <ctype.h>     /* For classifying chars                    */
#include <stdlib.h>    /* For converting strings to numeric values */
#include <math.h>      /* For power(), function                    */

#define BUFFER_LEN 256 /* Length of input buffer                   */
/*
 * You set the input string to a length of 256. This should be enough because most computers keyboard buffers are 255
 * characters (This refers to the maximum number of characters that you can type in before having to press Enter).
 */

int main(void) {
  
  char input[BUFFER_LEN],  /* Input expression                                          */
    number_string[30],     /* Stores a number string from input                         */
    op = 0;                /* Stores an operator                                        */
  unsigned int index = 0,  /* Index of the current character in input                   */
    to = 0,                /* To index for copying input to itself                      */
    number_length = 0;     /* Length of the string in number string                     */
  size_t input_length = 0; /* Length of input string (compatible w/strlen() return type */
  double result = 0.0,     /* The result of an operation                                */
    number = 0.0;          /* Stores the value of number_string                         */


  printf("\nTo use this calculator, enter any expression with or without spaces."
	 "\nAn expression may include the following operators:"
	 "\n  +,-,*,/,%% or ^(raise to a power)."
	 "\nUse the = at the beginning of a line to operate on the result of the"
	 "\nPrevious calculation."
	 "\nUse quit by itself to stop the calculator.\n\n");
  
  /* The main calculator loop */
  while(strcmp(fgets(input, BUFFER_LEN, stdin), "quit\n") != 0) {
    /* 
     * We read the input expression using the fgets() function that's declared in the stdio.h library header file. This 
     * will read an entire line of input, including spaces and the '\n' and then adding the '\0'. Then it returns a
     * pointer to that string, &input[0] in this case. That is exactly what strcmp() expects in both arguments; then it
     * will compare them, returning 0 if they are the same. In this case this will cause the loop to stop when fgets()
     * reads "quit\n" from stdin.
     */

    input_length = strlen(input);
    input[--input_length] = '\0'; /* Overwrites the '\n' readed by fgets() */
    
    /* Remove all spaces from input by copying the string to itself including the string terminating char */
    for(to = 0, index = 0; index <= input_length; index++)
      if(*(input + index) != ' ')           /* If it isn't a space       */
	*(input + to++) = *(input + index); /* Copy the character        */
    /*
     * Once we have your string, it would be better if we remove any spaces from the string. Because the input string is
     * well-defined, we don't need spaces to separate the operator from the operands.
     * 
     * We remove spaces by copying the string stored in input to itself. We need to keep track of two indexes in the
     * copy loop:
     * * One for the position in input where the next nonspace char is to be copied to;
     * * And one for the position of the next char to be copied. In the loop we don't copy spaces.
     * We just increment index to move to the next character. The to index gets incremented only when a char is copied.
     *
     * The previous loop is equivalent to this other one:
     * 
     *   for(to = 0, index = 0 ; index<=input_length ; index++)
     *     if(input[index] != ' ') 
     *       input[to++] = input[index];
     * 
     * Which is the one obtained by using the array notation instead.
     */

    input_length = strlen(input);           /* Get the new string length */
    index = 0;                              /* Start at the first char   */
    /*
     * After the loop is entered, we store the new string length in input_length and reset index to reference to the
     * first character in input.
     */
    
    /* Check for '=' and analyze & store teh left operand */
    if(input[index] == '=') /* Is the =?                      */
      index++;              /* Yes so Slip it over            */
    /*
     * This checks for '=' as the first char in the input. If we find one, we increment index to skip it, and go
     * straight looking for the operand, otherwise we execute the else, which looks for a numeric left operand.
     */
    
    else {                  /* No - look for the left operand */
      /* Look for a number that is the left operand for the first operator */
      
      /* Check for sign and copy it                                        */
      number_length = 0;                                         /* Initialize length */
      if(input[index] == '+' || input[index] == '-')             /* Is it + or - ?    */
	*(number_string + number_length++) = *(input + index++); /* Yes so copy it    */
      /*
       * We will copy all the chars that make up the number to number_string, but The number may start w/aunary sign,
       * '-' or '+', so we first check that. If we find it, then we copy it to number_string.
       * If the sign isn't found, index, recording the current character to be analyzed, will remain the same; otherwise
       * its value will be incremented after the sign is copied.
       */

      /* Copy all following digits                                         */
      for(; isdigit(*(input + index)); index++)                /* Is it a digit? */
	*(number_string + number_length++) = *(input + index); /* Yes - Copy it  */
      /*
       * One or more digits should be next, so the previous for loop that copies however many digits there are to
       * number_string. Each digit is copied and the index value is incremented accordingly. If there are no digits its
       * value will be unchanged.
       */
      
      /* Copy any fractional part */
      if(*(input + index) == '.') {                              /* Is it decimal point? */
	/* Yes so copy the point and the following digits */
	*(number_string + number_length++) = *(input + index++); /* Copy point     */
	for(; isdigit(*(input + index)); index++)                /* For each digit */
	  *(number_string + number_length++) = *(input + index); /* Copy it        */
      }
      /*
       * The number might not be an integer. In this case, there must be a decimal point next, which may be followed by
       * more digits. The if statement checks for the decimal point. If there is one, then the decimal point and any
       * following digits will also be copied.
       */
      
      *(number_string + number_length) = '\0';                   /* Append string terminator */
      /*
       * We must have finished copying the string for the first operand now, so you append a stringterminating character
       * to number_string.
       */
      
      /* If we have a left operand, the length of number_string will > 0. In this case convert to a double so we can */
      /* use it in the calculation                                                                                   */
      if(number_length > 0)
	result = atof(number_string); /* Store first number as result */      
      
      /*
       * While there may not be a value found, if we've copied a string representing a number to number_string, the
       * value of number_length must be positive because there has to be at least one digit. Therefore, you use the
       * value of number_length as an indicator that you have a number.
       * The string is converted to a floating-point value of type double by the atof() function. Note that we store the
       * value of the string in result. we'll use the same variable later to store the result of an operation. This will
       * ensure that result always contains the result of an operation, including that produced at the end of an entire
       * string. If we haven't stored a value here, because there is no left operand, result will already contain the
       * value from the previous input string.
       */  
    }

    /* Now look for 'op number' combinations */
    for(; index < input_length; ) {
    /*
     * This loop continues untill we reach the end of the input string, which will be when you have incremented the
     * the index 
     */
      
      op = *(input + index ++); /* Get the operator */
      /*
       * With the operator out of the way, we can then extract the characters that form the next number. This will be
       * the right operand for the operator. You haven't verified that the operator is valid here, so the code won't
       * spot an invalid operator at this point.
       */
      
      /* Copy the next operand and store it in number */
      number_length = 0; /* Initialize the length */

      /* Check for sign and copy it                   */
      if(input[index] == '+' || input[index] == '-')             /* Is it + or - ?*/
	*(number_string + number_length++) = *(input + index++); /* Yes - Copy it */

      /* Copy all following digits                    */
      for(; isdigit(*(input + index)); index++)                 /* For each digit */
	*(number_string + number_length++) = *(input + index);  /* Copy it        */

      /* Copy any fractional part                     */
      if(*(input + index) == '.') {                              /* Is it a decimal point? */

	/* Copy the decimal point and the following digits */
	*(number_string + number_length++) = *(input + index++); /* Copy the point */
	for( ; isdigit(*(input + index)); index++)               /* For each digit */
	  *(number_string + number_length++) = *(input + index); /* Copy it        */
      }      

      /* Terminate string */
      *(number_string + number_length) = '\0'; 

      /* Convert to double so we can use it in the calculation */
      number = atof(number_string);

      /*
       * The extraction of the string for the number that's the right operand is exactly the same as that for the left
       * operand. The same code is repeated. This time, though, the double value for the operand is stored in number.
       * With this we have the left operand stored in result, the operator stored in op, and the right operand stored in
       * number, thus prepared to execute an operation or the form "number = atof(number_string)".
       */

      /* Execute operation, as "result op= number" */
      switch(op) {
      case '+':
	result += number; /* Addition                      */
	break;
      case '-':
	result -= number; /* Substraction                  */
	break;
      case '*':
	result *= number; /* Multiplication                */
	break;
      case '/':           /* Secure division               */
	/* Check for zero second operand */
	if(number == 0)
	  printf("\n\n\aDivision by zero error!\n");
	else
	  result /= number;
	break;
      case '%':          /* Secure Modulo - reminder       */
	/* Check for zero second operand */
	if(number == 0)
	  printf("\n\n\aDivision by zero error!\n");
	else
	  result = (double)((long)result % (long)number);
	break;
      case '^':          /* Raise to a power               */
	result = pow(result, number);
	break; 
      default :          /* Invalid operation or bad input */
	printf("\n\na Illegal operation!\n");
      }
    }
    /*
     * The switch statement is essentially the same as in the previous calculator program, but with some extra cases.
     * Because we use the power function pow() to calculate resultnumber, you have to add an #include directive for the
     * header file math.h.
     */
    
    /* Output the result */
    printf("= %f\n", result); 
  }
  return 0;
}
