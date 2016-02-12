/* Program 2.10 Round tables again */
#include <stdio.h>

int main(void) {
  float diameter = 0.0f,
    radius = 0.0f;
  const float Pi = 3.141592654f; /* Define the value of PI as fixed */
  /*
   * This declares the variable Pi and asigns a value for it.
   * Pi is still a variable, but the initial given value, can't change.
   * The assignment must appear in the declaration.
   * The compiler will check for further attempts to change its value. It will complain if he finds at least one.
   */

  printf("Input the diameter of the table:");
  scanf("%f", &diameter);
  radius = diameter/2.0f;
  printf("\nThe circumference is %.2f", 2.0f*Pi*radius);
  printf("\nThe area is %.2f", Pi*radius*radius);

  return 0;
}
