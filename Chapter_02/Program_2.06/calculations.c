/* Program 2.6 Cookies and kids */
#include <stdio.h>

int main(void) {
  int cookies = 45,           /* Number of cookies in the jar */
    children = 7,             /* Number of children           */
    cookies_perch_child = 0,  /* Number of cookies per child  */
    cookies_left_over = 0;    /* Number of remaining cookies  */
  
  
  /* Calculate how many cookies each child gets when they're divided up */
  cookies_perch_child = cookies/children; /* Number of cookies per child */
  printf("You have %d children and %d cookies", children, cookies);
  printf("\nGive each child %d cookies.", cookies_perch_child);
  
  /* Calculate how many cookies are left over */
  cookies_left_over = cookies%children;
  printf("\nThere are %d cookies left over.\n", cookies_left_over);
  return 0;
}
