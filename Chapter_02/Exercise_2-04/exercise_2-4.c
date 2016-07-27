/* Exercise 2-4 */
/*
 * Write a program that prompts for the user’s weekly pay in dollars and the hours worked to be entered through the
 * keyboard as floating-point values. The program should then calculate and output the average pay per hour in the
 * following form:
 * Your average hourly pay rate is 7 dollars and 54 cents.
 */
#include <stdio.h>

int main(void) {
  float w_pay = 0.0f,
    w_hrs = 0.0f,
    h_avg = 0.0f;
  int dollars = 0;
   
  /* Get payment value for the week, and the worked hours               */
  printf("Please enter your weekly pay in dollars: ");
  scanf("%f", &w_pay);
  printf("       ..and the total hours you worked: ");
  scanf("%f", &w_hrs);  
  /* Calculate the hourly average                                       */
  h_avg = w_pay/w_hrs;
  /* Get the dollars part separately (using implicit conversion)        */
  dollars = h_avg;
  /* Get the cents part separately (later printf will round the value)  */
  h_avg = (h_avg - dollars)*100;
  /* Display the average in the requested format                                */
  printf("Your average hourly pay rate is: %d dollars and %.0f cents.\n", dollars, h_avg);
  /* The conversion specifier for float values, correctly rounds the value of h_avg to the appropiate number of
   * precision digits specified: in this case 0.
   */
  return 0;
}
