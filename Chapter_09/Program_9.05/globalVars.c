/* Program 9.5 Global variables */
#include <stdio.h>

int count = 0;             /* Declare a global variable   */
/*
 * This isn't a static variable (although you could make it static if you wanted to), but because it is global it will
 * be initialized by default to 0 if you don't initialize it. It's potentially accessible in any function from the point
 * where it's declared to the end of the file, so it's accessible in any of the functions here.
 */

/* Function prototypes */
void test1(void);
void test2(void);

int main(void) {
  int count;               /* This hides the global count */
  /*
   * Because it has the same name as the global variable, the global variable count can't be accessed from main().
   * Any use of the name count in main() will refer to the variable declared within the body of main(). The local
   * variable count hides the global variable.
   */
  
  for(count = 0; count < 5; count++) {
    test1();
    test2();
  }
  printf("\n");

  return 0;
}

/* Function test1 using the global variable */
void test1(void) {
  printf("\nTest1 count = %d", ++count);
}

/* Function test2 using a static variable */
void test2(void) {
  static int count = 0;    /* This hides the global count */
  /*
   * Because this is a static variable, it will be initialized to 0 by default. This variable also hides the global
   * variable of the same name, so only the static variable count is accessible in test2().
   */
  printf("\nTest2 count = %d", ++count);
}

/*
 * The function test1() works using the global count. The functions main() and test2() use their local versions of
 * count, because the local declaration hides the global variable of the same name.
 * 
 * Clearly, the count variable in main() is incremented from 0 to 4, because you have five calls to each of the
 * functions test1() and test2(). This has to be different from the count variables in either of the called functions;
 * otherwise, they couldn't have the values 1 to 5 that are displayed in the output.
 *
 * You can further demonstrate that this is indeed the case by simply removing the declaration for count in test2() as a
 * static variable. You'll then have made test1() and test2() share the global count, and the values displayed will run
 * from 1 to 10.
 * 
 * If you then put a declaration back in test2() for count as an initialized automatic variable the output from test1()
 * will run from 1 to 5, and the output from test2() will remain at 1, because the variable is now automatic and will be
 * reinitialized on each entry to the function.
 * 
 */
