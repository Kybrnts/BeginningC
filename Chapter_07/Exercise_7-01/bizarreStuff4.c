#include <stdio.h>

int main(void) {

  char input,
    *string = NULL,
    **p_string = NULL;
  unsigned short i;


  p_string = (char **)malloc(4*sizeof(char *));
  *p_string = (char *)malloc(4*sizeof(char));

  (p_string + 1) = (char **)malloc(4*sizeof(char *));

  return 0;
}
