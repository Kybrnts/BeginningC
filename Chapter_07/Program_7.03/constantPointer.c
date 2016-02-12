/* Program 7.3B  Constant pointer behaviour */

int main(void) {
  int count = 43;
  int *const pcount = &count; /* Defines a constant pointer                   */
  /*
   * The second statement declares and initializes pnumber and indicates that the address stored must not be changed.
   * The compiler will therefore check that you do not inadvertently attempt to change what the pointer points to
   * elsewhere in your code, so the following statements will result in an error message when you compile.
   */
  int item = 34;
  /* pcount = &item;             Error - attempt to change a constant pointer */

  *pcount = 345;             /* OK - changes the value of count */
  /* 
   * You can still change the value that pcount points to using pcount. This references the value stored in count
   * through the pointer and changes its value to 345. You could also use count directly to change the value.
   */

  int item = 25;
  const int *const pitem = &item;
  /* 
   * Finally it is possible to You can create a constant pointer that points to a value that is also constant
   */

}
