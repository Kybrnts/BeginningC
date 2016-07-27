/* Program 2.6 Cookies and kids */
#include <stdio.h>

int main(void) {
  int cookies = 45,           /* Number of cookies in the jar */
    children = 7,             /* Number of children           */
    cookies_perch_child = 0,  /* Number of cookies per child  */
    cookies_left_over = 0;    /* Number of remaining cookies  */
  
  
  /* Calculate how many cookies each child gets when they're divided up */
  cookies_perch_child = cookies/children;
  /* The number of cookies is divided by the number of children by using the division operator / to produce the number
   * of cookies given to each child.
   */
  printf("You have %d children and %d cookies", children, cookies);
  printf("\nGive each child %d cookies.", cookies_perch_child);
  /* You can see from the output that cookies_per_child has the value 6. This is because the division operator always
   * produces an integer result when the operands are integers.
   */

  /* Calculate how many cookies are left over (get reminder using modulus operator) */
  cookies_left_over = cookies%children;
  printf("\nThere are %d cookies left over.\n", cookies_left_over);
  return 0;
}
/* REMEMBER:
 * 1. Division operator always produces an integer result when the operands are integers.
 * 2. With division, the result will always be negative if the operands have diffferent signs.
 * 3. With the modulus operator, the sign of the result is always the same as that of the LEFT operand.
 */
