/* Program 10.1 Exercising formatted input */
#include <stdio.h>

#define SIZE (size_t)20   /* Max characters in a word   */

int main(void) {
  int value_count = 0;    /* Count of input values read */
  float fp1 = 0.0;        /* Floating point value read  */
  int i = 0,              /* First integer read         */
    j = 0;                /* Second integer read        */
  char word1[SIZE] = " ", /* First string read          */
    word2[SIZE] = " ";    /* Second string read         */
  int byte_count = 0;     /* Count of input bytes read  */

  value_count = scanf("%f %d %d %[abcdefghijklmnopqrstuvwxyz] %*1d %s%n", 
		      &fp1, &i, &j, word1, word2, &byte_count);
  printf("\nCount of bytes read = %d\n", byte_count);
  printf("\nCount of values read = %d\n", value_count);
  printf("\nfp1 = %f  i = %d  j = %d\n", fp1, i, j);
  printf("\nword1 = %s  word2 = %s\n", word1, word2);
  return 0;
}

