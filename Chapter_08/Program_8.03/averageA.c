/* Program 8.3A avergage using function prototype */
#include <stdio.h>
float average(float, float); /* Function prototype */

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

float average(float x, float y) {
  return (x + y)/2.0f;
}
