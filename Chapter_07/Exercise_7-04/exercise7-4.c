/* Exercise 7.04 */
/*
 * Write a program that will read a series of temperature recordings as floating-point values for an arbitrary number of
 * days, in which six recordings are made per day. The temperature readings should be stored in an array that's
 * allocated dynamically and that's the correct dimensions for the number of temperature values that are entered.
 * Calculate the average temperature per day, and then output the recordings for each day together, with the average on
 * a single line with one decimal place after the point.
 */
#include <stdio.h>   /* For standard i/o stuff                    */
#include <ctype.h>   /* For using tolower()                       */
#include <string.h>  /* For string functions                      */
#include <stdlib.h>  /* For converting strings to numberic values */
#include <stdbool.h> /* For boolean data type support             */

#define INPUTSIZE 20 /* Fixed input size                  */
#define RDNGSSIZE 6  /* Max number of readings per day    */
#define SPACE ' '    /* Constant for space                */
#define TAB '\t'     /* Constant for tab                  */
#define POINT '.'    /* Constant for decimal point        */
#define PLUS '+'     /* Constant for plus symbol          */
#define MINUS '-'    /* Constant for minus symbol         */

int main(void) {

  const char *inputword = "input",
    *doneword = "done",
    *quitword = "quit";

  char *input = NULL;                 /* Input buffer                                                               */
  float **readings = NULL,            /* List of arrays of readings, one element points to an array of six elements */
    **tmpreadings = NULL;             /* Temporal storage for readings list                                         */
  double *averages = NULL;            /* Storage for averages of each element of the readings list                  */

  unsigned int i, j, k,
    readingslen = 0,
    tmpreadingslen = 0,
    averageslen = 0;

  bool domath = false;


  /* Allocate memory for the input */
  input = (char *)malloc(INPUTSIZE*sizeof(char));
  if(!input) {
    return 1;
  }
  
  /* Explain the user the program usage */
  printf("\nEnter %d temperature readings for an arbitrary number of days to be averaged for each day."
	 "\nUse the words \"%s\", \"%s\" and \"%s\" to finish the program, to start entering readings"
	 "\nand to proceed with the math respectively.\n\n", RDNGSSIZE, quitword, inputword, doneword);
  
  /* Read each day */
  while(1) {
    printf("Input readings for %s day? (%s/%s/%s)$ ",
	   readingslen < 1 ? "first" : "next", inputword, doneword, quitword);

    /* Get answer */
    for(i = 0; i < INPUTSIZE; i++)                /* Read from input         */
      if((*(input + i) = getchar()) == '\n') {
	*(input + i++) = '\0';
	break;                               
      }
    if(i == INPUTSIZE && *(input + i - 1)) {      /* Input size exceeded?    */
      printf("Error! Input buffer size exceeded. Try again.\n");
      while(getchar() != '\n');                   /* Flush the stdin (avoid fflush) */
      continue;
    }
    for(i = 0, j = 0; *(input + j); j++) {       /* Remove spaces from input */
      if(!(*(input + j) == SPACE || *(input + j) == TAB))
	*(input + i++) = tolower(*(input + j));
    }
    *(input + i) = '\0';                         /* Add string terminator    */

    /* If answer is non of the three possible options ask again */
    if(!(strcmp(input, inputword) == 0 || strcmp(input, doneword) == 0 || strcmp(input, quitword) == 0)) {
      printf("Please use one of the following: %s, %s or %s\n", inputword, doneword, quitword);
      continue;
    }

    /* If answer is to quit finish program */
    if(strcmp(input, quitword) == 0) {
      printf("Ok, bye then...\n");
      return 0;
    }

    /* If answer is done, go ahead with the math */
    if(strcmp(input, doneword) == 0) {
      if(readingslen < 1) {
	printf("There are no temperature readings yet, please input some or quit.\n");
	continue;
      }
      else
	domath = true;
      break;
    }    
    
    /* If the answer it to input, Get the required readings and store them in memory */
    if(strcmp(input, inputword) == 0) {

      /* Save the previously entered values in temporal memory space and create more space */
      tmpreadingslen = readingslen;
      tmpreadings = (float **)malloc(tmpreadingslen*sizeof(float *));
      if(!tmpreadings) {
	printf("Error! Unable to allocate memory for the temporal readings list. Finishing program...\n");
	return 1;
      }
      for(i = 0; i < readingslen; i++)
	*(tmpreadings + i) = *(readings + i);
      free(readings);
      readings = NULL;
      readingslen++;
      readings = (float **)malloc(readingslen*sizeof(float *));
      if(!readings) {
	printf("Error! Unable to allocate memory for the new readings list. Finishing program...\n");
	return 1;
      }
      for(i = 0; i < tmpreadingslen; i++)
	*(readings + i) = *(tmpreadings + i);
      free(tmpreadings);
      tmpreadings = NULL;
      /* Allocate memory for the array of readings in the matching element of the readings list */
      *(readings + readingslen - 1) = (float *)calloc(RDNGSSIZE, sizeof(float));
      if(!(*(readings + readingslen - 1))) {
	printf("Error! Unable to allocate memory for the new readings list element. Finishing program..\n");
	return 1;
      }
      /* Read RDNGSSIZE temperature values to input */
      for(i = 0; i < RDNGSSIZE; i++) {
	
	/* Get one temperature reading */
	printf("  Temperature reading #%d or %s? ", i + 1, quitword);
	for(j = 0; j < INPUTSIZE; j++)
	  if((*(input + j) = getchar()) == '\n') {
	    *(input + j++) = '\0';
	    break;
	  }
	if(j == INPUTSIZE && *(input + j - 1)) {
	  printf("Error! Input buffer size exceeded. This reading will be ignored.\n");
	  while(getchar() != '\n');
	  i--;
	  continue;
	}
	for(j = 0, k = 0; *(input + k); k++) {
	  if(!(*(input + k) == SPACE || *(input + k) == TAB))
	    *(input + j++) = tolower(*(input + k));
	}
	*(input + j) = '\0';

	/* If input is to quit finish program */
	if(strcmp(input, quitword) == 0) {
	  printf("Ok, bye then...\n");
	  return 0;
	}
		
	/* Discard input if not numeric */
	if(!(*input == PLUS || *input == MINUS || isdigit(*input))) {
	  printf("Last entered value is not a float. Will be ignored.\n");
	  i--;
	  continue;
	}
	for(j = 1; isdigit(*(input + j)); j++);
	if(*(input + j) != POINT) {
	  if(*(input + j)) {
	    printf("Last entered value is not a float. Will be ignored.\n");
	    i--;
	    continue;      
	  }
	}
	if(*(input + j)) {
	  for(j++; isdigit(*(input + j)); j++);
	  if(*(input + j)) {
	    printf("Last entered value is not a float. Will be ignored.\n");
	    i--;
	    continue;
	  }
	}
	/* Save when numeric */
	(*(readings + readingslen - 1))[i] = atof(input);
      }
      continue;
    }
  }

  /* Input is no loger needed */
  free(input);
  input = NULL;
  
  /* If we have to do the math.. */
  if(domath) {
    
    /* Allocate memory for the averages list */
    averageslen = readingslen;
    averages = (double *)calloc(averageslen, sizeof(double));
    if(!averages) {
      printf("Error! Unable to allocate memory for the averages list. Finishing program..\n");
      return 1;
    }

    /* Calculate each day's average */
    for(i = 0; i < readingslen; i++) {
      for(j = 0; j < RDNGSSIZE; j++)
	averages[i] += (double)(*(readings + i))[j];
        averages[i] /= (double)RDNGSSIZE;
    }

    /* Display results in a suitable table format */
    printf("\nTable of resuts:"
           "\n+-------");
    for(i = 0; i < RDNGSSIZE; i++)
      printf("+-------------");
    printf("+---------+\n");
    printf("| Day #");
    for(i = 0; i < RDNGSSIZE; i++)
      printf(" | Reading #%-2d", i + 1);
    printf(" | Average |\n");
    printf("+-------");
    for(i = 0; i < RDNGSSIZE; i++)
      printf("+-------------");
    printf("+---------+\n");
    for(i = 0; i < readingslen; i++) {
        printf("| %-5d", i + 1);
	for(j = 0; j < RDNGSSIZE; j++)
	  printf(" | %-11.1f", (*(readings + i))[j]);
	printf(" | %-7.1f |\n", averages[i]);
    }
    printf("+-------");
    for(i = 0; i < RDNGSSIZE; i++)
      printf("+-------------");
    printf("+---------+\n");
  }
  return 0;
}
