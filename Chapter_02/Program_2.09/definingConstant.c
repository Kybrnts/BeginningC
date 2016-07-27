/* Program 2.9 More round tables */
#include <stdio.h>
#define PI 3.141592654f
/*
 * Here PI is defined as a SYMBOL that is to be replaced by the code 3.141592654f.
 * By convention we name identifiers that appear in a #define statement w/caps.
 * Wherever PI is referenced within an expression, the preprocessor will substitute it with the specified value for
 * it in the #define directive.
 * All the substitutions will be made before compiling the program.
 */

int main(void) {
  float radius = 0.0f;
  float diameter = 0.0f;
  float circumference = 0.0f;
  float area = 0.0f;
  printf("Input the diameter of a table: ");
  scanf("%f", &diameter);
  radius = diameter/2.0f;
  circumference = 2.0f*PI*radius;
  area = PI*radius*radius;
  printf("\nThe circumference is %.2f", circumference);
  printf("\nThe area is %.2f\n", area);
  return 0;
}
