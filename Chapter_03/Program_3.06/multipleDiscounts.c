/* Program 3.6 Multiple discount level */
#include <stdio.h>

int main(void) {
  const double unit_price = 3.50, /* Unit price in dollars     */
    discount1 = 0.05,             /* Discount for more than 10 */
    discount2 = 0.1,              /* Discount for more than 30 */
    discount3 = 0.15;             /* Discount for more than 40 */
  double total_price = 0.0;
  int quantity = 0;
  
  printf("Enter the number that you want to buy: ");
  scanf("%d", &quantity);
  
  total_price = quantity*unit_price*(1.0 -
				     (quantity > 50 ?
				      discount3 : (quantity > 20 ?
						   discount2 : (quantity > 10 ?
								discount1 : 0.0))));
  /* The discount will be according to the quantity.
   * Is the quantity > 50. If so the discount3 will be applied;
   * otherwise if the quantity is between 50 and 21 inclusive the discount2 will be applied;
   * and so on.
   */
  printf("The price for %d is $%.2f\n", quantity, total_price);  
  return 0;
}
