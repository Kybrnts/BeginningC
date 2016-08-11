/* Exercise 3-3A */
/* Now using integers only */
#include <stdio.h>
#define U_PRIZE 5
#define O_30_DISCCOUNT 15
#define O_50_DISCCOUNT 10

int main(void) {
  int quantity = 0;
  long przx100 = 0L;

  /* Get the quantity from keyboard */
  printf("Please enter the quantity of Tagos that you want to buy: ");
  scanf("%d", &quantity);
  
  if(quantity < 0) 
    printf("You must enter a non-negative value \n");
  else {
    /* Calculate final price's x100  */
    przx100 = U_PRIZE*quantity*(100 - (quantity > 50 ? O_50_DISCCOUNT : (quantity > 30 ? O_30_DISCCOUNT : 0)));
    printf("The final price is: %ld.%ld\n", przx100/100, przx100%100);
  }
  return 0;
}
