#include <stdio.h>

int main(void) {

  char c1, c2;
  char *p_c1 = &c1, *p_c2 = &c1;
  unsigned short b = 0;

  b = (p_c1 == 0x0000000F);

  printf("Value of boolean b is: %d\n", b);
  

  p_c1 = 0x0000000;

  while(p_c1 <= 0x0000000F)
    printf("Address: %p\n", p_c1++);

  printf("Searching for the address of c1..\n");
  for(p_c1 = &c1, p_c2 = 0x0000000; p_c2 < p_c1; p_c2 += 0x00000001);
  
  printf("Next address is %p, so it must be the address of c1\n", p_c2);
  printf("Also with the & operator, we know that address of c1 is %p", &c1);
  
  return 0;
}
