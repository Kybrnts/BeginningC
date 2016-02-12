/* Program 7.1 A simple program using poionters */
#include <stdio.h>

int main(void) {

  int number = 0;       /* Allocate memory for variable of tipe int and store in its bytes the value of 0 */
  int *pointer = NULL;  /* Allocate memory for a variable of type POINTER TO INT, that points to nowhere  */

  number = 10;
  printf("\nNumber's address: %p", &number);  /* Output the address                                          */
                                              /* Remember that the output specifier for memory address is %p */
  printf("\nNumber's value: %d\n\n", number); /* Output the stored value                                     */

  pointer = &number; /* Store the address of number in pointer                                          */
                     /* The "&" operator makes this statement to be evaluated to the address off number */
                     /* Remember: The only kind of value that you can store in a pointer is an address  */
  
  printf("Pointer's address: %p", &pointer);             /* Output the address                                        */
                                                         /* This statement is evaluated to the address of the first   */
                                                         /* byte that "pointer" occupies.                             */
  printf("\nPointer's size: %d bytes", sizeof(pointer)); /* Output the size                                           */
                                                         /* This returns the number of bytes that pointer uses, for   */
                                                         /* instance in a system of 32 this will be 4                 */
  printf("\nPointer's value: %p", pointer);              /* Output pointer's value (content)                          */
                                                         /* This will be the address of number                        */
  printf("\nValue pointed to: %d\n", *pointer);          /* Output the value at the contained address                 */
                                                         /* Here we used pointer to access the value stored in number */
                                                         /* The effect of the "*" operator is to access the data      */
                                                         /* contained in the address stored in pointer                */

  /*
   * While we've noted that the addresses shown will be different on different computers, they'll often be different
   * at different times on the same computer. The latter is due to the fact that your program won't always be loaded at
   * the same place in memory. The addresses of number and pointer are where in the computer the variables are stored.
   * Their values are what is actually stored at those addresses. For the variable called number, it's an actual integer
   * value (10), but for the variable called pointer, it's the address of number. Using *pointer actually gives you
   * access to the value of number. You're accessing the value of the variable, number, indirectly.
   *
   * You'll certainly have noticed that your indirection operator, *, is also the symbol for multiplication.
   * Fortunately, there's no risk of confusion for the compiler. Depending on where the asterisk appears, the compiler
   * will understand whether it should interpret it as an indirection operator or as a multiplication sign.
   */
  return 0;
}
