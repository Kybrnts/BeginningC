/* Program 7.6A */
#include <stdio.h>

int main(void) {

  long multiple[] = {15L, 25L, 35L, 45L};
  int i;

  for(i = 0; i < sizeof(multiple)/sizeof(multiple[0]); i++)
    printf("\nAddress multiple+%d (&multiple[%d]): %d *(multiple+%d) value: %d",
	                        i,            i,    multiple + i, i,         *(multiple + i));
  /* 
   * We could also write the for loop of the previous version like this, using the name of the array directly. This
   * works because the expressions multiple and multiple+i both evaluate to an address. We output the values of these
   * addresses and output the value at these addresses by using the * operator. The arithmetic with addresses works the
   * same here as it did with the pointer p. Incrementing multiple by 1 results in the address of the next element in
   * the array, which is 4 bytes (tipically) further along in memory. However, don't be misled; an array name is just a
   * fixed address and is not a pointer.
   */

  printf("\n    Type long occupies: 4 bytes");
  return 0;
}
