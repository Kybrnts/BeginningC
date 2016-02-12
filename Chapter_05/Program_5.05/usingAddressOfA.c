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
  int data[5],
    i;
  for(i = 0; i < 5; i++)
    data[i] = 12*(i+1);

  printf("A variable of type long occupies %d bytes.", sizeof(long));
  printf("\nHere are the addresses of some variables of type long:");
  printf("\n The address of a is: %p The address of b is: %p", &a, &b);
  
  printf("\n\nA variable of type double occupies %d bytes.", sizeof(double));
  printf("\nHere are the addresses of some variables of type double:");
  printf("\nThe address of d is: %p The address of e is: %p", &d, &e);
  printf("\nThe address of f is: %p\n", &f);

  for(i = 0; i < 5; i++)
    printf("\ndata[%d] Address: 0x%p Contents: %d", i, &data[i], data[i]);
  printf("\n");
  
  return 0;
}
