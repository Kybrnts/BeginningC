/* Program 3.2 Using if statements to decide on a discount */
#include <stdio.h>

int main(void) {
  const double unit_price = 3.50;                    /* Unit price in dollars */
  int quantity = 0;                                  /* How many units        */
  double total = 0.0;                                /* Total price           */
  
  printf("Enter the number that you want to buy: "); /* Prompt message        */
  scanf("%d", &quantity);                            /* Read the input        */
  
  if(quantity > 10)                                  /* 5% discount           */
    total = quantity*unit_price*0.95;
  else
    total = quantity*unit_price;
  printf("The price for %d is $%.2f\n", quantity, total);
  return 0;
}
