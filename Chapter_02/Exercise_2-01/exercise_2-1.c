/* Exercise 2-1 */
/* 
 * Write a program that prompts the user to enter a distance in inches and then
 * outputs that distance in yards, feet, and inches.
 */
#include <stdio.h> /* This will be reading input from stdin and writing to stdout */

#define INCHES_PER_FOOT 12L  /* Inches per yard */
#define INCHES_PER_YARD 36L  /* Inches per yard */
/* As we will operate w/type LONG, we defined them as such to avoid implicit conversion */

int main(void) {
  /* Declare variables of suitable types */
  long input = 0, /* Distance to be read from input         */
    inches = 0,   /* Variable to store the remaining inches */
    feet = 0,     /* Store the converted input              */
    yards = 0;    /* Store the converted input              */  

  /* Get the distance to convert */
  printf("Enter the distance the whole in inches: "); /* Prompt the user to enter the distance in two steps */
  scanf("%ld", &input);                               /* Read the data entered in the input                 */
  inches = input;                                     /* Store the readed data                              */

  /* Convert the distance */
  yards = inches/INCHES_PER_YARD;  /* First group all inches in yards */
  inches %= INCHES_PER_YARD;       /* Get reminding inches            */
  feet = inches/INCHES_PER_FOOT;   /* Group reminding inches in feet  */
  inches %= INCHES_PER_FOOT;       /* Get remining inches             */

  /* Output the converted distance */
  printf("That is a total of %ld yd, %ld ft and %ld in.\n", yards, feet, inches);

  return 0;
}
