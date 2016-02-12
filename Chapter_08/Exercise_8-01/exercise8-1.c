/* Exercise 8.01 */
/*
 * Define a function that will calculate the average of an arbitrary number of floating point values that are passed to
 * the function in an array. Demonstrate the operation of this function by implementing a program that will accept an
 * arbitrary number of values entered from the keyboard, and output the average.
 * 
 * Note: In this case we used a limited number of floating point values by creating an array of 
 */
#include <stdio.h>   /* For standard i/o stuff                    */
#include <ctype.h>   /* For using atof()                          */
#include <string.h>  /* For string functions                      */
#include <stdlib.h>  /* For converting strings to numberic values */
#include <stdbool.h> /* For boolean data type support             */

#define INPUTLEN 20  /* Maximum size of input buffer      */
#define VALUESLEN 25 /* Maximum size of float values list */
#define SPACE ' '    /* Constant for space                */
#define TAB '\t'     /* Constant for tab                  */
#define PLUS '+'
#define MINUS '-'
#define POINT '.'

int inputfloat(char *, const int *, float *);       /* Enter and index from input buffer a float value */
double averagefloats(const float *, const int *);   /* Returns the average of list of float values     */
void outputaverage(double);                         /* Outputs a float value                           */


int main(void) {
  
  char *input = NULL;           /* Input buffer              */
  float values[VALUESLEN];      /* Values list               */
  int values_i = 0,             /* Values list index         */
    input_exit = 0;             /* inputfloat() return value */


  input = (char *)malloc(INPUTLEN*sizeof(char));
  if(!input) {
    printf("\nError! Unable to allocate memory for input buffer. Finishing program..\n");
    return 1;
  }
  
  printf("\nEnter sucesive float values to be averaged."
	 "\nJust press enter to finish:\n\n");

  /* Read list of float values to values list element until fill last possible element */  
  while(values_i < VALUESLEN) {
    input_exit = inputfloat(input, &values_i, &values[values_i]);
    if(input_exit == 3) {       /* In this case input buffer size was exceeded         */
      printf("Error! Input buffer size exceeded. Try again.\n");
      continue;                 /* Ignore this value                                   */
    }else if(input_exit == 2) { /* In this case user didn't enter a valid float value  */
      printf("Error! Input is not a float. Try again.\n");
      continue;                 /* Ignore this value                                   */
    }else if(input_exit == 1)   /* In this last case user simply pressed enter         */
      break;                    /* Finish input process                                */
    values_i++;
                                /* In any other case inputfloat() shall return 0       */
  }
  
  /* Check for index out of boundaries index list                                      */
  if(values_i == VALUESLEN && input_exit == 0) {
    printf("\nError! Maximum number of values exceeded. Finishing program..\n");
    return 1;
  }

  /* Input is no longer needed so, release the memory used by it                       */
  free(input);
  input = NULL;
  
  /* Calculate the average and display it                                              */
  outputaverage(averagefloats(values, &values_i));
  
  return 0;
}

int inputfloat(char *input, const int *values_i, float *currentvalue) {
  
  int j,                                                        /* Auxilar index                                      */
    input_i = 0;                                                /* Input buffer index                                 */

  /* Prompt the user to enter a float value */
  printf("Enter float value #%d> ", *values_i + 1);
  
  /* Read the answer                        */
  for(input_i = 0; input_i < INPUTLEN; input_i++)
    if((*(input + input_i) = getchar()) == '\n') {
      *(input + input_i++) = '\0';
      break;
    }

  /* Input size exceeded ?                  */
  if(input_i == INPUTLEN && *(input + input_i - 1)) {
    while(getchar() != '\n');                                   /* Consume remaining chars                            */
    return 3;                                                   /* Return specific value for this scenario            */
  }
  
  /* Is the input the empty string ? */
  if(*input == '\0') {
    return 1;                                                   /* Return specific value for this scenario            */
  }

  /* Remove spaces from input */
  for(input_i = 0, j = 0; *(input + j); j++) {       
    if(!(*(input + j) == SPACE || *(input + j) == TAB))
      *(input + input_i++) = tolower(*(input + j));
  }
  *(input + input_i) = '\0';

  /* Discard input if not numeric */
  if(!(*input == PLUS || *input == MINUS || isdigit(*input))) { /* Does it starts with a sign or a digit ?            */
    return 2;                                                   /* No, so return the specific value for this scenario */
  }
  for(input_i = 1; isdigit(*(input + input_i)); input_i++);     /* Does it continues w/a series of digits ?           */
  if(*(input + input_i) != POINT) {                             /* finished by a decimal point                        */
    if(*(input + input_i)) {
      return 2;                                                 /* No, so return the specific value for this scenario */
    }
  }
  if(*(input + input_i)) {                                      /* Does it continues w/a series of digits ?           */
    for(input_i++; isdigit(*(input + input_i)); input_i++);
    if(*(input + input_i)) {
      return 2;                                                 /* No, so return the specific value for this scenario */
    }
  }
  
  /* Assign float tu currentvalue */
  *currentvalue = atof(input);

  return 0;
}

double averagefloats(const float *values, const int *used_values) {
  int i;
  double average = 0.0;
  
  if(*used_values < 1) {
    printf("\nError! No values entered");
    return average;
  }
  for(i = 0; i < *used_values; i++)
    average += *values++;
  average /= *used_values;

  return average;
}

void outputaverage(double average) {
  
  printf("\nThe average is: %-7.3f\n", average);
  
  return;
}
