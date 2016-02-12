/* Exercise 10-2 */
/*
 * Write a program that will read the numerical values in the following line of input, and output the total:
 * $3.50 , $4.75 , $9.95 , $2.50
 */
#include <stdio.h>  /* Provides scanf() and printf() */

const char formatspec[] = "%*1[$]%4f%*1[ ]%*1[,]%*1[ ]"
                          "%*1[$]%4f%*1[ ]%*1[,]%*1[ ]"
                          "%*1[$]%4f%*1[ ]%*1[,]%*1[ ]"
                          "%*1[$]%4f";

int main(int argc, char *argv[]) {
  float f1, f2, f3, f4;
  int read_values = 0;

  printf("Enter four floating point numbers: ");
  read_values = scanf(formatspec, &f1, &f2, &f3, &f4);
  if(read_values != 4) {
    printf("Error! Wrong input format. Please try again.\n");
    return 1;
  }
  printf("Total: %-5.2f\n", (f1 + f2 + f3 + f4));
  
  return 0;
}
