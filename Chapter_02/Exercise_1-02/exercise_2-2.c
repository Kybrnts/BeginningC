/* Exercise 2-2 */
/*
 * Write a program that prompts for input of the length and width of a room in feet
 * and inches, and then calculates and outputs the floor area in square yards with
 * two decimal places after the decimal point.
 */
#include <stdio.h> /* This will be reading input from stdin and writing to stdout */

#define FEET_PER_YARD (short)3
#define INCHES_PER_YARD (short)36

int main(void) {

  /* Declare variables of suitable types */
  long input = 0,
    feet = 0,
    inches = 0;
  double length = 0.0,
    width = 0.0,
    area = 0.0;

  /* Get the length and the witdth of the room */
  printf("Enter the length of the room, the whole in feet: ");
  scanf("%ld", &input);
  feet = input;
  printf("                                  ...and inches: ");
  scanf("%ld", &input);
  inches = input;
  length = feet/(float)FEET_PER_YARD + inches/(float)INCHES_PER_YARD;

  printf("Enter the width of the room, the whole in feet: ");
  scanf("%ld", &input);
  feet = input;
  printf("                                 ...and inches: ");
  scanf("%ld", &input);
  inches = input;
  width = feet/(float)FEET_PER_YARD + inches/(float)INCHES_PER_YARD;
  
  /* Calculate the area of the room */
  area = length*width;

  /* Output the result */
  printf("The floor area of the room is %.2f square yards.", area);

  return 0;
}
