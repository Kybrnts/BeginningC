/* Program 7.5 Arrays and pointers taken further */
#include <stdio.h>

int main(void) {
  
  char multiple[] = "My string",
    *p = multiple;               /* ie char *p = &multiple[0] */
  int i;

  printf("&(*p)= %p\n", &(*p));
  printf("*(&multiple[0])= %c\n", *(&multiple[0]));

  for(i = 0; multiple[i]; i++)
    printf("\nmultiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p",
	   i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
  
  return 0;
}
/*
 * Look at the list of addresses to the right in the output. Because p is set to the address of multiple, p + n is
 * essentially the same as multiple + n, so you can see that multiple[n] is the same as *(multiple + n). The addresses
 * differ by 1, which is what you would expect for an array of elements that each occupy one byte. You can see from the
 * two columns of output to the left that *(p + n), which is dereferencing the address that you get by adding an integer
 * n to the address in p, evaluates to the same thing as multiple[n].
 * 
 */
