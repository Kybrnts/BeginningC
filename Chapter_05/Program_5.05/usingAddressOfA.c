/* Program 5.5A Using the & operator */
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
  /* Declare an array variable */
  int data[5U];
  /* When we declare an array, we give the compiler all the information it needs to allocate the memory for it. The type
   * of value determines the number of bytes that each element will require, and the array dimension specifies the
   * number of elements. The number of bytes that an array will occupy is the number of elements multiplied by the size
   * of each element.
   */
  unsigned i;
  for(i = 0U; i < 5U; i++)
    data[i] = 12*(i+1);

  printf("A variable of type long occupies %lu bytes.\n", sizeof(long));
  printf("Here are the addresses of some variables of type long:\n");
  printf("The address of a is: %p The address of b is: %p\n", (void *)&a, (void *)&b);
  printf("The address of c is: %p\n\n", (void *)&c);

  printf("A variable of type double occupies %lu bytes.\n", sizeof(double));
  printf("Here are the addresses of some variables of type double:\n");
  printf("The address of d is: %p The address of e is: %p\n", (void *)&d, (void *)&e);
  printf("The address of f is: %p\n\n", (void *)&f);

  printf("A variable of type int [5] occupies memory as follows:\n");
  for(i = 0U; i < 5U; i++)
    printf("Data[%d] Address: %p Contents: %d\n", i, (void *)&data[i], data[i]);
  /* The array name, number, identifies the address in memory where the array elements are stored. The specific
   * location of an element is found by combining the address corresponding to the array name with the index value,
   * because the index value represents the offset of a number of elements from the beginning of the array.
   * The address of an array element is going to be the address where the array starts, plus the product of
   * the index value for the element and the number of bytes required to store each element.
   */
  return 0;
}
