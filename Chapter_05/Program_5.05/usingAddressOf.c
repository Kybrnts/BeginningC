/* Program 5.5 Using the & operator */
#include <stdio.h>

int main(void) {
  /* Declare some integer variables */
  long a = 1L,
    b = 2L,
    c = 3L;
  /* Declare some floating-point variables */
  double d = 4.0,
    e = 5.0,
    f = 6.0;

  printf("A variable of type long occupies %lu bytes.\n", sizeof(long));
  printf("Here are the addresses of some variables of type long:\n");
  printf("The address of a is: %p The address of b is: %p\n", (void *)&a, (void *)&b);
  printf("The address of c is: %p\n", (void *)&c);
  /* We used %u for the value produced by sizeof because it will be an unsigned integer value.
   * The address format specifier is p, so it is needed for output variable's addresses. As per C standard: "The
   * argument shall be a pointer to void." The value of the pointer is converted to a sequence of printing characters,
   * in an implementation-defined manner. This is why we need to cast the addresses before actually using them. 
   * A memory address is typically 32 or 64 bits, and the size of the address will determine the maximum amount of
   * memory that can be referenced. For example, in a 64-bit address system the addresses will appear as 16 hexadecimal
   * digits; however this may change from one machine to another.
   * Is intresting to notice that in a system that implement longs using 4-bytes, the address of a is 4 units lower than
   * that of b, an c is also lower than b by 4.
   */
  printf("\nA variable of type double occupies %lu bytes.\n", sizeof(double));
  printf("Here are the addresses of some variables of type double:\n");
  printf("The address of d is: %p The address of e is: %p\n", (void *)&d, (void *)&e);
  printf("The address of f is: %p\n", (void *)&f);
  /* There is a similar situation w/the variables d, e and f, but if they are implemented using 8-bytes each, there can
   * be a gap between the locations of d and c. This happens because many compilers allocate spaces for variables at
   * addresses taht are a multiple of their size, so 4-byte variables are at addresses multiple of 4, and the 8-byte
   * ones would be at addresses multiple of 8. This ensures that accessing the memory is done more efficiently.
   * NOTE: If the output shows that the addresses for the variables of the same type are separated by greater amounts
   * than the size for the type, it is most likely because the program was compiled as a debug version. In debug mode,
   * the compiler allocates extra space to store additional information about the variable that will be used when you’re
   * executing the program in debug mode.
   */
  return 0;
}
