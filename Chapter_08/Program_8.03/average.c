/* Program 8.3 Average of two floats values */
#include <stdio.h>

/* Definition of a function  to calculate the average */
float average(float x, float y) {
    
  return (x + y)/2.0f;
}

int main(void) {

  float value1 = 0.0f,
    value2 = 0.0f,
    value3 = 0.0f;

  printf("Enter two floatig-point values separated by blanks: ");
  scanf("%f %f", &value1, &value2);
  value3 = average(value1, value2);
  printf("\nThe average is: %f\n", value3);
  
  return 0;
}
