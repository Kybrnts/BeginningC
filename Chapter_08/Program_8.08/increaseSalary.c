/* Program 8.8 A function to increase your salary that doesn't */
#include <stdio.h>

long *IncomePlus(long *pPay);  /* Prototype for increase function */

int main(void) {

  long your_pay = 30000L;      /* Starting salary              */
  long *pold_pay = &your_pay;  /* Pointer to pay value         */
  long *pnew_pay = NULL;       /* Pointer to hold return value */

  pnew_pay = IncomePlus(pold_pay);
  printf("\nOld pay = $%ld", *pold_pay);
  printf(" New pay = $%ld\n", *pnew_pay);
  return 0;
}

long *IncomePlus(long *pPay) {
  long pay = 0;               /* Local variable for the reult  */

  pay = *pPay + 10000L;       /* Increment the value for pay   */
  return &pay;                /* Return the address            */
}
/*
 * You may get different results on your computer, even possibly the correct one. This is because you're returning the
 * address of the variable pay, which  goes out of scope on exiting the function IncomePlus(). This is the cause of the
 * remarkable value for the new value of pay - it's junk, just a spurious value left around by something. This is an
 * easy mistake to to make.
 */
