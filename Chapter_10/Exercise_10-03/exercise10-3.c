/* Exercise 10-3 */
/* Define a function that will output an array of values of type double that is passed as an argument along with the
 * number of elements in the array. The prototype of the function will be the following:
 *
 *      void show(double array[], int array_size, int field_width);
 *
 * The values should be output 5 to a line, each with 2 decimal places after the decimal point and in a field width of
 * 12. Use the function in a program that will output the values from 1.5 to 4.5 in steps of 0.3 (i.e., 1.5, 1.8, 2.1,
 * and so on, up to 4.5).
 */
#include <stdio.h>  /* Provides scanf() and printf() */
#include <stdlib.h> /* Provides malloc()             */

const double MAX = 4.5;

/* Function prototypes */
void show(double array[], int array_size, int field_width);

int main(void) {
  double sum,
    *array = NULL;
  int size = 0;

  /* Find the size for the array                           */
  for(sum = 1.5; sum <= MAX; sum += 0.3)
    size++;

  /* Allocate memory in the heap for the array of elements */
  array = (double *)malloc(size*sizeof(double));
  
  /* Initialize the array                                  */
  for(size = 0, sum = 1.5; sum <= MAX; sum += 0.3)
    *(array + size++) = sum;

  /* Display the aray of elements                          */
  show(array, size, 12);
  
  /* Free allocated memory in the heap                     */
  free(array);
    
  return 0;
}

void show(double da[], int s, int fw) {
  int i;               /* Double array index                           */
  char fspec1[8] = "", /* Frmt. spec. for "middle line" double element */
    fspec2[7] = "";    /* Frmt. spec. for "last line element"          */

  if(fw > 99)                                  /* Did we specify a number w/more than two digits for the field width */
    printf("Error! Unsupported width used.");  /* Yes, so show error message                                         */

  sprintf(fspec1, "%%%2d.2f, ", fw);           /* Print the format specifiers                                        */
  sprintf(fspec2, "%%%2d.2f\n", fw);
  
  for(i = 0; i < s; i++)                       /* Print using the matching format specifier                          */
    printf(i%5 < 4 ? i == s - 1? fspec2 : fspec1 : fspec2, da[i]);
}
