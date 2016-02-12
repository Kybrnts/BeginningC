/* Exercise 7.01 */
/*
 * Write a program to calculate the average for an arbitrary number of floating-point values that are entered from the
 * keyboard. Store all values in memory that's allocated dynamically before calculating and displaying the average. The
 * user shouldn't be required to specify in advance how many values there will be.
 */

#include <stdio.h>  /* For standard i/o stuff                    */
#include <ctype.h>  /* For using tolower()                       */
#include <string.h> /* For string functions                      */
#include <stdlib.h> /* For converting strings to numberic values */

#define INPUTSIZE 20  /* Maximum size for each input value */
#define SPACE ' '     /* Constant for space                */
#define TAB '\t'      /* Constant for tab                  */
#define POINT '.'     /* Constant for decimal point        */
#define PLUS '+'      /* Constant for plus symbol          */
#define MINUS '-'     /* Constant for minus symbol         */

int main(void) {
  char *input = NULL;             /* Reference to the string readed from stdin                     */
  const char quitword[] = "quit", /* When readed from input, the program stops                     */
    lastinputword[] = "done";     /* Stops reading from input and triggers the calculation process */
  unsigned short i,               /* Indexes */
    j,
    do_math,                      /* Flag that is set to true when lastinputword is readed         */
    values_len = 0,               /* "Values" element counter                                      */
    swap_len = 0;                 /* "Swap" element counter                                        */
  float *values = NULL,           /* Valid readed values list                                      */
    *swap = NULL;                 /* Space to store values list temporarily                        */
  double sum = 0.0;               /* Stores the sum of all the valid entered values                */



  /* Create the input buffer */
  input = (char *)malloc(INPUTSIZE*sizeof(char)); /* We could've used an array, but in that case we wouldn't be able */
                                                  /* To release this piece of memory later.                          */
  if(!input) {
    printf("\nError! Unable to allocate memory");
    return 1;
  }

  /* Prompt the user to enter a list of space separated floating point values */
  printf("Enter a list of floating point values to be averaged.\n"
	 "Use \"done\" to proceed w/the calculation or \"quit\" to finish:\n\n");
  
  /* Read the list of floating point values --------------------------------- */
  while(1) {

    /* Print a prompt for each value */
    printf("%s value? (quit/done)$: ", values_len < 1 ? "First" : "Next");

    /* Read one single value */
    for(i = 0; i < INPUTSIZE; i++)
      if((*(input + i) = getchar()) == '\n') { 
	*(input + i++) = '\0';                /* If we reach the \n we replace it with \0, then increase  the index   */
	break;                                /* and exit the loop inmediately. Anyway we make sure that i is always  */
      }                                       /* increased so input + i - 1 always points to the last readed char.    */
    if(i == INPUTSIZE && *(input + i - 1)) {  /* If we reach the last char and it isn't \0, then the user exceeded    */
                                              /* the allowed input size.                                              */
      printf("Error! Input buffer size exceeded. This value will be ignored.\n");
      fflush(stdin);                          /* Clean the remaining ureaded chars from stdin                         */
      continue;
    }
    
    /* Process input */
    for(i = 0, j = 0; *(input + j); j++) {                /* Remove all spaces/tabs by copy the string to itself.     */
      if(!(*(input + j) == SPACE || *(input + j) == TAB)) /* I stores the next position where the next non space/tab  */
	*(input + i++) = tolower(*(input + j));           /* is to be placed, and j the position of the next char     */
    }                                                     /* that is going to be checked.                             */
    *(input + i) = '\0';

    if(strcmp(input, quitword) == 0) {                    /* If input string is "quit" stop processing                */
      do_math = 0;
      printf("\nOk, bye then...");
      break;
    }

    if(strcmp(input, lastinputword) == 0) {               /* If input string is "done" stop reading and do the math   */
      do_math = 1;
      break;
    }

    /* Discard non numeric imput strings and store the others  */
    if(!(*input == PLUS || *input == MINUS || isdigit(*input))) {    /* If it doesn't start with +/-/digit, skip it */
      printf("Entered value \"%s\" is not a float. Will be ignored.\n", input);
      continue;
    }
    for(i = 1; isdigit(*(input + i)); i++);                          /* Go ahead w/all the following digits.        */
    if(*(input + i) != POINT) {                                      /* If a decimal point si not found, check if   */
      if(*(input + i)) {                                             /* we have not reach the string terminator     */
	printf("Entered value \"%s\" is not a float. Will be ignored.\n", input);
	continue;      
      }
    }
    if(*(input + i)) {                                              /* If a decimal point is found, and yet not     */ 
      for(i++; isdigit(*(input + i)); i++);                         /* the end of the string, continue w/all the    */
      if(*(input + i)) {                                            /* remainin digits                              */
	printf("Entered value \"%s\" is not a float. Will be ignored.\n", input);
	continue;
      }
    }
    /* Now convert the value and store it */
    swap_len = values_len;                              /* Swap betwen the already existing list of values and the  */
    swap = (float *)malloc(swap_len*sizeof(float));     /* new one, using the swap variable.                        */
    if(!swap) {
      printf("\nError! Unable to allocate memory");
      return 1;
    }
    for(i = 0; i < values_len; i++)
      *(swap + i) = *(values + i);
    free(values);
    values = NULL;

    values_len++;
    values = (float *)malloc(values_len*sizeof(float));
    if(!values) {
      printf("\nError! Unable to allocate memory");
      return 1;
    }
    for(i = 0; i < swap_len; i++)
      *(values + i) = *(swap + i);
    free(swap);
    swap = NULL;

    *(values + values_len - 1) = atof(input);
    
  }
  /* Input is now, no longer needed */
  free(input);

  /* Calculate the average -------------------------------------------------- */
  if(do_math) {
    for(i = 0; i < values_len; i++)
      sum += (double)*(values + i);

    printf("\n******************************"
	   "\n* The average is: %-10.3le *"
	   "\n******************************", values_len == 0 ?
	                                          (double)0 : sum/(double)values_len);
  }
  free(values); /* Values list is no longer needed */
  return 0;
}
