/* Program 10.4 Reading hexadecimal and octal values */
#include <stdio.h>

int main(void) {
  int i = 0;
  unsigned int j = 0U;
  unsigned int k = 0U;
  int n = 0;

  printf("Input:\n");
  n = scanf("%d %x %o", &i, &j, &k);
  printf("\nOutput:\n");

  printf("%d values read.", n);
  printf("\ni = %d j = %d k = %d\n", i, j, k);

  return 0;
}
