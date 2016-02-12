/* Program 4.11 Reversing the digits */
#include <stdio.h>

int main(void) {
  int number = 0,
    rebnum = 0,
    temp = 0;

  /* Get the value to be reversed */
  printf("\nEnter a positive integer: ");
  scanf(" %d", &number);

  temp = number; /* Copy it to working storage */
  /*
   * This is necessary, because the process of reversing the digits destroys the original value, and you want to output
   * the original integer along with the reversed version.
   */
  
  /* Reverse the number stored in temp */
  do{
    /* The do-while loop is most appropriate here because any number will have at least one digit. */
    rebnum = 10*rebnum + temp%10;
    /*
     * You get the rightmost digit from the value stored in temp by using the modulus operator, %, to get the remainder
     * after dividing by 10. Because temp originally contains 43, temp%10 will be 3. You assign the value of
     * 10*rebmun + temp%10 to rebmun. Initially, the value of the variable rebmun is 0, so on the first iteration 3 is
     * stored in rebmun.
     */
    temp = temp/10;
    /* 
     * You've now stored the rightmost digit of your input in rebmun, and so you now remove it from temp by dividing
     * temp by 10. Because temp contains 43, temp/10 will be rounded down to 4.
     */
  }while(temp); /* Continue while temp > 0*/
  /*
   * At the end of the loop the while(temp) condition is checked, and because temp contains the value 4, it is true.
   * Therefore, you go back to the top of the loop to begin another iteration
   */

  /* Output the result */
  printf("\nThe number %d reversed is %d rebnum ehT\n", number, rebnum);

  return 0;
}
