/* Program 7.2 What's the pointer */
#include <stdio.h>

int main(void) {

  long num1 = 0L, /* Two variables of type long initialized to zero                                      */
    num2 = 0L,
    *pnum = NULL; /* One variable of type "pointer to long", initialized with no memory direction at all */
  /* /!\ Caution /!\
   * You should always initialize your pointers when you declare them. Using a pointer that isn't initialized to store
   * an item of data is dangerous. Who knows what you might overwrite when you use the pointer to store a value?
   */

  pnum = &num1;                               /* Get address of num1                                                    */
                                              /* This will assign the address of num1 to pnum because the "&num1"       */
                                              /* statement is evaluated to that address.                                */     
  *pnum = 2;                                  /* Set num1 to 2                                                          */
                                              /* Indirectly by using the new pointers feature                           */
  ++num2;                                     /* Increment num2                                                         */
  num2 += *pnum;                              /* Add num1 to num2                                                       */
                                              /* Again accessing num1 content by new pointers feature                   */
  pnum = &num2;                               /* Get address of num2       */
  ++*pnum;                                    /* Increment num2 inderectly */
  /*
   * First, the pointer is reassigned to point to num2. The variable num2 is then incremented indirectly through the
   * pointer. You can see that the expression ++*pnum increments the value pointed to by pnum without any problem.
   * However, if you want to use the postfix form, you have to write (*pnum)++. The parentheses are essential- assuming
   * that you want to increment the value rather than the address. If you omit them, the increment would apply to the
   * address contained in pnum. This is because the operators ++ and unary * (and unary &, for that matter) share the
   * same precedence level and are evaluated right to left. The compiler would apply the ++ to pnum first, incrementing
   * the address, and only then dereference it to get the value. This is a common source of error when incrementing
   * values through pointers, so it's probably a good idea to use parentheses in any event.
   */

  printf("\nnum1 = %ld, num2 = %ld, *pnum = %ld, *pnum + num2 = %ld\n",
	 num1, num2, *pnum, *pnum + num2);
  
  return 0;
}
