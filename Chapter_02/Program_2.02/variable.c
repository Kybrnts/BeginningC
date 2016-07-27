/* Program 2.2 Using a variable */
/* 
 * This is a better approach than that submitted in Program 2.1 source code
 * Here we allocate a piece of memory that can be used to store the salary value to be output.
 */
#include <stdio.h>

int main(void) {
  int salary;                            /* Declare a variable called salary                                          */
                                         /* Variable declaration starts w/a type name and ends w/a semicolon          */
                                         /* A variable can be one or more bytes, but the computer knows how may of    */                   
                                         /* them to use because of its "type". In this case an integer. This is known */
                                         /* as a definition, because that memory can be accessed through that name.   */
                                         /* A variable name is a sequence of uppercase or lowercase letters that      */
                                         /* starts with an underscore or a letter.                                    */
                                         /* Variable names are case sensitive (i.e. Ball and ball, are different)     */
                                         /* As of now we have not specified any value to be stored, so at this point  */
                                         /* salary will contain a "junk value".                                       */
  salary = 100000;                       /* A simple arithmetic assignment statement                                  */
                                         /* This is a simple arithmetic assignment statement. It takes the RHS value  */
                                         /* and stores its binary representation in the bytes of the LHS name.        */
                                         /* The "=" symbol is called the assignment operator.                         */
  printf("My salary is %d\n", salary);   /* There are two arguments in printf's parentheses, separated by a comma:    */
                                         /* 1. The control string, that controls how to output the values of the      */
                                         /*    following arguments.                                                   */
                                         /* 2. The second arument is the name of the variable whose value to output.  */
                                         /* The %d embedded in the control string is called a conversion specifier.   */
                                         /* This specifiers determine the form to which an original binary value is   */
					 /* to be converted, in this case, before to be displayed. Here we used a d   */
                                         /* which is a decimal specifier used for integers to be represented in base  */
                                         /* 10. and so sarlary's value will be displayed in the output.               */
                                         /* Conversion specifiers start with a % character for the printf() to        */
                                         /* recognize them.                                                           */
                                         /* To represent the % character itself in the control string, use the %%     */
                                         /* escape sequence.                                                          */
  return 0;
}
