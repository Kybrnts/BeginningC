/* Exercise 2-3 */
/*
 * You're selling a product that's available in two versions: type 1 is a standard
 * version priced at $3.50, and type 2 is a deluxe version priced at $5.50. Write a program using
 * only what you've learned up to now that prompts for the user to enter the product type and a
 * quantity, and then calculates and outputs the price for the quantity entered.
 */
#include <stdio.h>                  /* This will be reading input from stdin and writing to stdout */

enum version {Standard=1, Deluxe=2}; /* Define a type for the available product versions */

int main(void) {

  /* Declaring variables of a suitable type */
  int input = 0,
    quantity = 0;
  enum version product = Standard;
  float price_per_unit = 0.0f,
    total_price = 0.0f;

  /* Get the product type and the quantity */
  printf("Please select the product version (1 for Standard or 2 Deluxe): ");
  scanf("%d", &input);
  product = input;
  printf("Please enter de product quantity: ");
  scanf("%d", &input);
  quantity = input;

  /* Calculate the price per unit */
  price_per_unit = 2*product + 1.50f;
  /*
   * In order to find this formula, we should think about one of the type "y = mx + n", in wich 
   * 3.5 = m*(1) + n, and 5.5 = m*(2) + n, finding the values for m and n simoultaniously.
   */

  /* Calculate the total price */
  total_price = quantity*price_per_unit;

  /* Display the result */
  printf("The total price is $ %.2f.", total_price);

  return 0;
}
