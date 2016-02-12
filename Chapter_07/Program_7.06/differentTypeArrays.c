/* Program 7.6 Different types of arrays */
#include <stdio.h>

int main(void) {

  long multiple[] = {15L, 25L, 35L, 45L},
    *p = multiple;
  int i;

  for(i = 0; i < sizeof(multiple) / sizeof(multiple[0]); i++)
    printf("\nAddress p+%d (&multiple[%d]): %d *(p+%d) value: %d",
	                i,            i,    p + i, i,         *(p + i));
  printf("\n    Type long occupies: 4 bytes");
  return 0;
}
/*
 * his time the pointer, p, is set to the address that results from multiple, where multiple is an array of elements of
 * type long. The pointer will initially contain the address of the first byte in the array, which is also the first
 * byte of the element multiple[0].
 * For the sake of simplicity this time the addresses are displayed using the %d specifier so they will be decimal
 * values.
 * Looking at the output we can see that the difference between p and p + 1 is of 4 bytes (tipically), though we only
 * stepped p by 1. This isn't a mistake. The compiler realizes that when you add 1 to an address value, what you
 * actually want to do is access the next variable of that type. This is why, when you declare a pointer, you have to
 * specify the type of variable that's to be pointed to.
 */
