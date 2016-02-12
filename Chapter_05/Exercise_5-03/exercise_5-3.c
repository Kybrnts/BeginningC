/* Exercise 5-3 */
/*
 * Write a program that will read five values from the keyboard and store them in an array of type float with the name
 * amounts. Create two arrays of five elements of type long with the names dollars and cents. Store the whole number 
 * part of each value in the amounts array in the corresponding element of dollars and the fractional part of the amount
 * as a two-digit integer in cents (e.g., 2.75 in amounts[1] would result in 2 being stored in dollars[1] and 75 being
 * stored in cents[1]). Output the values from the two arrays of type long as monetary amounts (e.g., $2.75).
 */
#include <stdio.h>

int main(void) {
  unsigned short x;
  float amounts[5];
  long dollars[5],
    cents[5];

  /* Read five float values in "amounts" and split it in wholes and cents */
  printf("\nEnter five amounts:\n");
  for(x = 0; x < 5; x++) {
    printf("#%d> ", x + 1);
    /* Read one amount */
    scanf("%f", &amounts[x]);
    /* Get upt to 4 decimal digits */
    dollars[x] = (long)(amounts[x]*1000);
    /* Get whole cents dealing with the rounding issue */
    dollars[x] = dollars[x]%10 > 4 ? dollars[x]/10 + 1 : dollars[x]/10;
    cents[x] = dollars[x]%100;
    /* Finally get the dollars */
    dollars[x] = dollars[x]/100;
  }

  /* Output the monetary amounts */
  printf("\nThe entered amounts are:");
  for(x = 0; x < 5; x++) {
    printf("\n#%d> $%ld.%s%ld", x + 1, dollars[x], cents[x] < 10 ? "0" : "", cents[x]);
  }
  return 0;
}
