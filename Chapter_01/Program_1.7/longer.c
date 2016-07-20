/* Program 1.7. A longer Program */
#include <stdio.h> /* Include the header file for standard input/output
		    * We can see this preprocessing directive because it begins with "#".
		    * The "stdio.h" file provides the definitions needed to use "printf()"
		    */
int main(void) /* We define the start function "main" specifying that it returns an integer value. */
{ /* This is the very begining of the function body */
  printf("Hi there!\n\n\nThis program is a bit");                     /* This outputs "Hi there followed by two blank
                                                                       * lines and then the "This is a bit" part.
                                                                       * Two blank lines are produced by the three "\n"
                                                                       * escape sequences.
								       */
  printf(" longer than the others.");                                 /* The next line of output starts at the character
                                                                       * position immediately following the last character
                                                                       * of the previous out. This is why it should start
                                                                       * with a space.
                                                                       */
  printf("\nBut reallity it's only more text.\n\n\n\a\a");            /* This statement starts its output on a new line,
                                                                       * then adds two empty lines and beeps twice.
								       */
  printf("Hey, wait a minute!! What was that???\n\n\n");
  /* *******************************************************************************************************************
   *  This will produce three numbered lines of output.
   */
  printf("\t1.\tA bird?\n");
  printf("\t2.\tA plane?\n");
  printf("\t3.\tA control character?\n");
  /* ******************************************************************************************************************* */
  printf("\n\t\t\b\bAnd how will this look when it prints out?\n\n"); /* Because of the last newline character of the last
								       * statement and the first newline one of this,
                                                                       * there will be an empty line following the previous
                                                                       * output.
                                                                       * Two tabs are then sent to the display followed by
                                                                       * two backspaces, which moves you back two spaces
                                                                       * from the tab position.
                                                                       * Finally the text and two newline characters are
                                                                       * sent to the display.
								       */
  return 0; /* This ends the execution of main() and return "0" to the operating sistem */
} /* This is the end of the function body */
