/* Program 9.4 Static versus automatic variables */
#include <stdio.h>

/* Function prototypes */
void test1(void);
void test2(void);

int main(void) {
  int i;

  for(i = 0; i < 5; i++) {
    test1();
    test2();
  }
  printf("\n");

  return 0;
}

/* Function test1 w/an automatic variable */
void test1(void) {
  int count = 0;
  /*
   * Because this is an automatic variable, it isn't initialized by default, and if you don't specify an initial value,
   * it will contain a junk value. This variable gets reinitialized to 0 at each entry to the function, and it's
   * discarded on exit from test1(); therefore, it never reaches a value higher than 1.
   */
  printf("\nTest1 count = %d", ++count);
}

/* Function test2 w/a static variable     */
void test2(void) {
  static int count = 0;
  /*
   * Although you specify an initial value, here the variable would have been initialized to 0 anyway because you
   * declared it as static.
   * 
   * All static variables are initialized to 0 unless you initialize them with some other value.
   *
   * The static variable count is used to count the number of times the function is called. This is initialized when
   * program execution starts, and its current value when the function is exited is maintained. It isn't reinitialized
   * on subsequent calls to the function. Because the variable has been declared as static, the compiler arranges things
   * so that the variable will be initialized only once. Because initialization occurs before program startup, you can
   * always be sure a static variable has been initialized when you use it.
   * 
   * Although a static variable will persist for as long as the program is running, it will be visible only within the
   * scope in which it is declared, and it can't be referenced outside of that original scope.
   */

  printf("\nTest2 count = %d", ++count);
}
