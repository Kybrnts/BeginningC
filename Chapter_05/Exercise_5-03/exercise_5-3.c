/* Exercise 5-3 */
/* Write a program that will read five values from the keyboard and store them in an array of type float with the name
 * amounts. Create two arrays of five elements of type long with the names dollars and cents. Store the whole number 
 * part of each value in the amounts array in the corresponding element of dollars and the fractional part of the amount
 * as a two-digit integer in cents (e.g., 2.75 in amounts[1] would result in 2 being stored in dollars[1] and 75 being
 * stored in cents[1]). Output the values from the two arrays of type long as monetary amounts (e.g., $2.75).
 */
#include <stdio.h>
#define SIZE 5U

int main(void) {
  unsigned x;                  /* Loop control variable          */
  float amounts[SIZE],         /* Amounts to be read from user   */
    curr;                      /* Current amount being processed */
  unsigned long dollars[SIZE], /* Requested arrays               */
    cents[SIZE];

  /* Read five float values in "amounts" and split it in wholes and cents */
  printf("Enter %u dollar amounts:\n", SIZE);
  for(x = 0U; x < SIZE; x++) {
    printf(" #%u> ", x + 1U);
    /* Read one amount                       */
    scanf("%f", &amounts[x]);
    /* Get absolute value of amounts         */
    curr = amounts[x] < 0 ? -amounts[x] : amounts[x];
    /* Store the whole part in dollars       */
    dollars[x] = curr;
    /* Remove whole part from current amount */
    curr = curr - dollars[x];
    /* Get upt to 2 decimal digits           */
    cents[x] = curr*100;
  }
  /* Output the monetary amounts                                          */
  printf("The entered amounts are:\n");
  for(x = 0U; x < SIZE; x++)
    printf(" #%u> %s$%ld.%s%ld%s\n",
	   x + 1U,
	   amounts[x] < 0 ? "(" : "",
	   dollars[x], cents[x] < 10UL ? "0" : "", cents[x],
	   amounts[x] < 0 ? ")" : "");
  return 0;
}
