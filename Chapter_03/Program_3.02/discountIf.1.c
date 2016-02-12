/* Program 3.2.1, improved 3.2 */
/*
 * One thing to notice is that floating-point variables aren't ideal for calculations involving money because of the
 * potential rounding that can occur. Providing that the amounts of money are not extremely large, one alternative is to
 * use integer values and just store cents.
 */
#include <stdio.h>

int main(void) {
  const long unit_price = 350L;                      /* Unit price in dollars */
  int quantity = 0;
  long discount = 0L,
    total_price = 0L,
    dollars = 0L,
    cents = 0L;
  
  printf("Enter the number that you want to buy: "); /* Prompt message */
  scanf("%d", &quantity);                            /* Read the input */

  if(quantity > 10)
    discount = 5L;
  total_price = quantity*unit_price*(100 - discount)/100;
  dollars = total_price/100;
  cents = total_price%100;
  printf("\nThe price of %d is $%ld.%ld\n", quantity, dollars, cents);
  
  return 0;
}
