/* Exercise 3-3 */
/*
 * Write a program that will calculate the price for a quantity entered from the keyboard,
 * given that the unit price is $5 and there is a discount of 10 percent for quantities
 * over 30 and a 15 percent discount for quantities over 50.
 */
#include <stdio.h>
#define U_PRIZE 5.0;
#define O_30_DISCCOUNT 0.15;
#define O_50_DISCCOUNT 0.10;

int main(void) {
  
  /* Declaration of variables */
  int quantity = 0;
  double prize = 0.0;
  
  /* Get the quantity from keyboard */
  printf("\nPlease enter the quantity of Tagos that you want to buy: ");
  scanf("%d", &quantity);

  /* Calculate the final prize */
  prize = U_PRIZE*quantity(1 - (quantity > 50 ? O_50_DISCCOUNT : (quantity > 30 ? O_30_DISCCOUNT : 0)));

  /* Output the price*/
  printf("\nThe final price is: %.2f", prize);

  return 0;
}
