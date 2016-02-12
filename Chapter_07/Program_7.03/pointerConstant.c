/* Program 7.3A  Pointer to constant behaviour */

int main(void) {
  long value = 9999L;

  const long *pvalue = &value; /* Defines a pointer to a constant          */
  /* *pvalue = 8888L;             Error - attempt to change const location */
  /*
   * Because you have declared the value pointed to by pvalue to be const, the compiler will check for any statements
   * that attempt to modify the value pointed to by pvalue and flag such statements as an error.
   */

  value = 7777L;
  /*
   * You have only asserted that what pvalue points to must not be changed. You are quite free to do what you want with
   * value.
   */
  

  long number = 8888L;
  pvalue = &number;           /* OK - changing the address in pvalue       */
  /*
   * The value pointed to has changed but you did not use the pointer to make the change. Of course, the pointer itself
   * is not constant, so you can still change what it points to.
   *
   * This will change the address stored in pvalue to point to number. You still cannot use the pointer to change the
   * value that is stored though.
   */
  
  return 0;
}
