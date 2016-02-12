/* Program 4.6 The almos infinite loop - computing and average */
#include <stdio.h>
#include <ctype.h> /* For the tolower() function */

int main(void) {
  char answer = 'N';  /* Records yes or no to continue the loop */
  double total = 0.0, /* Total values to be entered */
    value = 0.0;      /* Value entered */
  int count = 0;      /* Number of values entered */
  
  printf("\nThis program calculates teh average of"
	 " any number of values.");
  
  for( ; ; ) { /* Infinite loop */
    /*
     * This loop is set up to continue indefinitely because it has no end condition.
     * Therefor the blok of statements enclosed between the braces will be repeated indefinitely.
     */
    
    printf("\nEnter a value: "); /* Prompt the user for the next value */
    scanf(" %lf", &value);       /* Read the next value */
    total += value;              /* Add value to total */
    ++count;                     /* Increment the count of values */

    /* Check for more input */
    printf("Do you whant to enter another value? (Y or N): ");
    scanf(" %c", &answer);      /* Read the response */
    if(tolower(answer) == 'n')  /* Look for any sign of no */
      break;                    /* Exit from the loop */
    /*
     * Executing a break within a loop has the efect of inmediately ending the loop.
     * The execution will continue with the next statement that follows the closing brace for the loop block.
     */
  }
  /* Output the average to 2 decimal places */
  printf("\nThe average is %.2f\n", total/count);
  
  return 0;
}

