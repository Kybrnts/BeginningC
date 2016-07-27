/* Exercise 2-3 */
/*
 * You're selling a product that's available in two versions: type 1 is a standard version priced at $3.50, and type 2
 * is a deluxe version priced at $5.50. Write a program using only what you've learned up to now that prompts for the
 * user to enter the product type and a quantity, and then calculates and outputs the price for the quantity entered.
 */
#include <stdio.h> /* This will be reading input from stdin and writing to stdout */
#define SP 3.50f   /* Define two constant tymbols for required price types        */
#define DP 5.50f           

int main(void) {

  /* Declaring variables of a suitable type */
  int input = 0,               /* Integer to be read from input                                              */
    quantity = 0;              /* Number of items to buy                                                     */
  char product = '\0';         /* Product type (only 0 or 1, so use the least memory consuming integer type) */
  float price_per_unit = 0.0f,
    total_price = 0.0f;

  /* Get the product version */
  printf("Please select the product version 0 (standard) or 1 (deluxe): ");
  scanf("%d", &input); /* Read input and                             */
  product = input % 2; /* make sure that porduct type is only 0 or 1 */
  /* Get product cuantity    */
  printf("Please enter de product quantity: ");
  scanf("%d", &input);
  quantity = input;

  /* Calculate the price per unit */
  price_per_unit = product*DP + (1 - product)*SP;
  /* In order to find this formula, we should think about one of the type "y = mx + n", in wich
   * SP = m*(0) + n, and DP = m*(1) + n, finding the values for m and n simoultaniously.
   * Hence m = DP - SP, and n = SP
   */

  /* Calculate the total price */
  total_price = quantity*price_per_unit;

  /* Display the result */
  printf("The total price is $%.2f.\n", total_price);

  return 0;
}
