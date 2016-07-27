/* Program 2.5 Calculations with cookies */
#include <stdio.h>

int main(void) {
  int cookies = 5,           /* Number of cookies in the jar           */
    cookie_calories = 125,   /* Calories per cookie                    */
    total_eaten = 0,         /* Total cookies eaten                    */
    /* We'll use this variable to accumulate the total number of cookies eaten as the program progresses, so it must be 
     * initialized at 0.
     */
    eaten = 2;               /* Number to be eaten                     */
  
  cookies = cookies - eaten; /* Substract number of eaten from cookies */
  /* The values that an operator is applied to are called operands. An operator that requires two operands, such as % ,
   * is called a binary operator. An operator that applies to a single value is called a unary operator. Thus - is a
   * binary in the expression a - b and a unary in the expression -data.
   */
  total_eaten = total_eaten + eaten;
  printf("\nI have eaten %d cookies. There are %d cookies left",
	 eaten,
	 cookies);
  /* We can put the part of the statement that follows the first comma on a new line. It is possible to spread
   * statements out like this to make them easier to read or fit within a given width on the screen. Note that you
   * cannot split the string that is the first argument in this way. An explicit newline character isn’t allowed in the
   * middle of a string. When string splitting is needed between two or more lines, each segment of the string on a line 
   * must have its own pair of double quotes delimiting it.
   */
  eaten = 3;                 /* New value for cookies to be eaten      */
  cookies = cookies - eaten; /* Substract number of eaten from cookies */
  total_eaten = total_eaten + eaten;
  printf("\nI have eaten %d more."
         " Now there are %d cookies left\n",
	 eaten,
	 cookies);
  /* Where there are two or more strings immediately following one another like this, the compiler will join them to
   * form a single string.
   */
  printf("\nTotal energy consumed is %d calories.\n",
	 total_eaten*cookie_calories);
  /* Here the second argument to the printf() function is an arithmetic expression rather than just a variable. The
   * compiler will arrange for the result of the expression to be stored in a temporary variable, and that value will be
   * passed as the second argument to the printf() function. We can always use an expression for an argument to a
   * function as long as it evaluates to a result of the required type.
   */
  return 0;
}
