/*Program 1.3 Another very simple C Program - Displaying a Quotation */

#include <stdio.h>                       /* This is a preprocessor directive             */
/* * This isn't strictly part of the executable, but essential in this case. In fact, the program won’t work without it.
 *   The symbol # indicates this is a PREPROCESSING directive: an instruction to your compiler to do something BEFORE
 *   compiling the source code. The compiler handles these during an initial preprocessing phase before compilation.
 * * There are few prep. dircvs., and usually at program's source file header, but they CAN BE ANYWHERE.
 * * Here the compiler is instructed to “include” in your program the contents of the file named stdio.h, also called a
 *   HEADER file, because it’s usually included source's header. That file defines information about some functions
 *   provided by the standard C library.
 * * Generally, header files specify information that compiler uses to integrate predefined functions or other global
 *   objects within a program. We’ll be creating our own header files for use w/your programs.
 * * Stdio.h contains the info. that the compiler needs to understand what "printf" means, hence we have to include it.
 *   It also contains other funcs. that deal w/input and output, therefore its "stdio" short-hand-style name.
 * * All header files have file names w/the suffix ".h"
 */
int main(void)                           /* This identifies the function main() (DON'T use semicolon) */
{                                        /* This marks the begining of main()                         */
  printf("Beware the Ides of March!\n"); /* This line displays the quotation                          */
  return 0;                              /* This returns control to the operating system              */
}                                        /* This marks the end of main()                              */
