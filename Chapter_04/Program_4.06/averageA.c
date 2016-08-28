/* Program 4.6A The almos infinite loop - computing and average alternative version */
#include <stdio.h>
#include <ctype.h>    /* Provides tolower() function            */

int main(void) {
  char answer = 'N';   /* Records yes or no to continue the loop */
  double total = 0.0,  /* Total values to be entered             */
    value = 0.0;       /* Value entered                          */
  unsigned count = 0U; /* Number of values entered               */
  
  printf("This program calculates teh average of"
	 " any number of values.\n");
  for(;;) {                    /* Infinite loop                      */
    printf("Enter a value: "); /* Prompt the user for the next value */
    scanf("%lf", &value);      /* Read the next value                */
    total += value;            /* Add value to total                 */
    ++count;                   /* Increment the count of values      */
    printf("Do you whant to enter another value? (Y or N): ");
    scanf(" %c", &answer);     /* Read the response                  */
    if(tolower(answer) == 'n') /* Look for any sign of no            */
      /* In this version we simplified the answer check by issuing tolower() provided by ctype.h header file */
      break;                   /* Exit from the loop                 */
  }
  /* Output the average to 2 decimal places */
  printf("The average is %.2f\n", total/count);
  return 0;
}
