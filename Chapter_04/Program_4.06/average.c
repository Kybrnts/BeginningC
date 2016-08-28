/* Program 4.6 The almos infinite loop - computing and average */
#include <stdio.h>

int main(void) {
  char answer = 'N';   /* Records yes or no to continue the loop */
  double total = 0.0,  /* Total values to be entered             */
    value = 0.0;       /* Value entered                          */
  unsigned count = 0U; /* Number of values entered               */
  
  printf("This program calculates teh average of"
	 " any number of values.\n");
  for(;;) {                                                                 /* Infinite loop                      */
    /* This loop is set up to continue indefinitely because it has no end condition. Therefore the block of statements
     * enclosed between the braces will be repeated indefinitely.
     */
    printf("Enter a value: ");                                              /* Prompt the user for the next value */
    scanf("%lf", &value);                                                   /* Read the next value                */
    total += value;                                                         /* Add value to total                 */
    ++count;                                                                /* Increment the count of values      */
    /* Check for more input */
    printf("Do you whant to enter another value? (Y or N): ");
    scanf(" %c", &answer);                                                  /* Read the response                  */
    /* Here the leading space in the format specifier string is required to avoid the last entered EOL to be asigned to
     * answer.
     */
    if(answer >= 'A' && answer <= 'Z' ? answer + 'a' - 'A' : answer == 'n') /* Look for any sign of no            */
      break;                                                                /* Exit from the loop                 */
    /* Executing a break within a loop has the efect of inmediately ending the loop. The execution will continue with
     * the next statement that follows the closing brace for the loop block.
     */
  }
  /* Output the average to 2 decimal places */
  printf("The average is %.2f\n", total/count);
  return 0;
}
