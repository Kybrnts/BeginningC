#include <stdio.h>
#include <stdlib.h>

int main(void) {

  char *number = ".1";

  printf("atof(%s) is %f", number, atof(number));

  return 0;
}
