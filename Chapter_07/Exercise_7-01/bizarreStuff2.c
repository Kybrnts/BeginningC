#include <stdio.h>

#define MAXINPUT 5


int main(void) {

  unsigned short i, j,
    numbers_len = 0,
    swap_len = 0;
  double *numbers = NULL,
    *swap = NULL,
    number = 0.0;

  printf("Enter a list of five\n");

  for(i = 0; i < MAXINPUT; i++) {

    printf("#%d> ", i + 1);
    scanf(" %lf", &number);

    swap_len = numbers_len;
    swap = (double *)malloc(swap_len*sizeof(double));
    for(j = 0; j < numbers_len; j++)
      *(swap + j) = *(numbers + j);
    
    free(numbers);


    numbers_len++;
    numbers = (double *)malloc(numbers_len*sizeof(double));
    for(j = 0; j < swap_len; j++)
      *(numbers + j) = *(swap + j);

    free(swap);
    
    *(numbers + numbers_len - 1) = number;
    

  }

  for(i = 0; i < MAXINPUT; i++) {
    printf("Double stored in address: %p, is %lf\n", numbers + i, *(numbers + i));
  }
  
  return 0;
}
