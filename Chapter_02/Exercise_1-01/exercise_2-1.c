/* Exercise 2-1 */
/* 
 * Write a program that prompts the user to enter a distance in inches and then
 * outputs that distance in yards, feet, and inches.
 */
#include <stdio.h> /* This will be reading input from stdin and writing to stdout */

#define INCHES_PER_FOOT (short)12  /* Inches per yard */
#define INCHES_PER_YARD (short)36  /* Inches per yard */
/*
 * Seems that in C there's no way to declare a short constant.
 * One workaround would be to cast it.
 */

int main(void) {
  /* Declare variables of suitable types */
  long input = 0,           /* Distance to be read from input */
    inches = 0,             /* Variable to store the remaining inches */
    feet = 0,               /* Store the converted input */
    yards = 0;              /* Store the converted input */  

  /* Get the distance to convert */
  printf("\nEnter the distance the whole in inches: "); /* Prompt the user to enter the distance in two steps */
  scanf("%ld", &input);                                /* Read the data entered in the input */
  inches = input;                                      /* Store the readed data */

  /* Convert the distance */
  yards = inches/INCHES_PER_YARD;
  inches = inches%INCHES_PER_YARD;
  feet = inches/INCHES_PER_FOOT;
  inches = inches%INCHES_PER_FOOT;

  /* Output the converted distance */
  printf("\nThat is a total of %ld ft, %ld yd and %ld in.", yards, feet, inches);

  return 0;
}
