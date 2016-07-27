/* Program 2.8 Calculations on a table */
#include <stdio.h>

int main() {
  float radius = 0.0f,    /* The radius of the table */
    diameter = 0.0f,      /* The diameter of the table */
    circumference = 0.0f, /* The perimeter of the table */
    area = 0.0f,          /* The area of the table */
  /* Note how all the initial values have an f at the end because we're initializing values of type float. Without it
   * the values would be of type double. They would still work, but would be introducing some unnecessary conversion
   * that the compiler would have to arrange, from type double to type float.
   */
    Pi=3.14159265f;       /* An aproximation of the constant */
  /* There are more digits in the value of Pi that type float can accommodate, so the compiler will chop off the least
   * significant part so it fits.
   */

  printf("Input the diameter of the table: ");       /* Prompt the user to input the data */
  scanf("%f", &diameter);                            /* Read the diameter from keyboard to the variable "diameter"*/
  /* Scanf function is also provided by the stdio.h, and handles input from keyboard.
   * It takes what's entered through the keyboard and interprets it as specified by the control string of the first
   * argument (in this case, a float). Then stores the result in the variable specified in the second argument.
   * The "&" is called the "adress of" operator. 
   */
  radius = diameter/2.0f;                            /* Calculate the radius        */
  circumference = 2.0f*Pi*radius;                    /* Calculate the circumference */
  area=Pi*radius*radius;                             /* Calculate the area          */
  printf("\nThe circumference of the table is %.2f", 
	 circumference);
  printf("\nThe area of the table is %.2f\n",
	 area);
  return 0;
}
