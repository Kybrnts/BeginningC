/* Program 4.12 Reversing the digits */
#include <stdio.h>

int main(void) {
  unsigned number = 0U, /* The number to be reversed */
    rebnum = 0U,        /* The reversed number       */
    temp = 0U;          /* Working storage           */

  /* Get the value to be reversed      */
  printf("Enter a positive integer: ");
  scanf("%u", &number);
  /* Copy it to working storage        */
  temp = number; 
  /* This is necessary, because the process of reversing the digits destroys the original value, and you want to output
   * the original integer along with the reversed version.
   */  
  /* Reverse the number stored in temp */
  do{ /* The do-while loop is most appropriate here because any number will have at least one digit. */    
    rebnum = 10U*rebnum + temp%10U; /* Shift current digits to the left, and add rightmost temp digit */
    /* You get the rightmost digit from the value stored in temp by using the modulus operator, %, to get the remainder
     * after dividing by 10.
     */
    temp = temp/10U;               /* Remove rightmost digit from temp                              */
    /* You've now stored the rightmost digit of your input in rebmun, and so you now remove it from temp by dividing
     * temp by 10.
     */
  }while(temp); /* Continue while temp > 0 */
  /* At the end of the loop the while(temp) condition is checked */

  /* Output the result                 */
  printf("The number %u reversed is %u rebnum ehT\n", number, rebnum);
  return 0;
}
