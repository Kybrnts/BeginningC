/* Program 10.8 Integer output */
#include <stdio.h>

int main(void) {
  int i = 15,
    j = 345,
    k = 4567;
  long li = 56789L,
    lj = 678912L,
    lk = 23456789L;

  printf("\ni = %d   j = %d   k = %d   i = %6.3d   j = %6.3d   k = %6.3d\n",
	 i, j, k, i, j, k);
  printf("\ni = %-d  j = %+d  k = %-d  i = %-6.3d  j = -6.3d   k = %-6.3d\n",
         i, j, k, i, j, k);
  printf("\nli = %d  lj = %d  lk = %d\n", li, lj, lk);
  printf("\nli = %d  lj = %ld lk = %ld\n", li, lj, lk);

  return 0;
}
