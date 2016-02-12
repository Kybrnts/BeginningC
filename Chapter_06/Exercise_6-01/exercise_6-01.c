/* Exercise 6.01 */
/*
 * Write a program that will prompt for and read a positive integer less than 1000 from the keyboard, and then create
 * and output a string that is the value of the integer in words.
 * For example, if 941 is entered, the program will create the string "Nine hundred and forty one".
 */
#include <stdio.h>
#define INPUTSIZE 4    /* From the first digit to the null character */
#define OUTPUTSIZE 50  /* Length of the most large possible output   */

int main(void) {

  /* Defining suitable variables */
  char input[INPUTSIZE] = "",    /* String for storing the input  */
    output[OUTPUTSIZE] = "";     /* String for storing the output */
  short number[] = {0, 0, 0},    /* Digits of the input number in order of importance */
    i, j;                        /* Indexes */
  
  /* Read string number from stdin to input */
  printf("\nPlease enter an integer between 0 and 1000: ");
  scanf("%4s", input); /* No need for & because input points to the address of its first element */
  

  /* Check if input has more than three chars */
  if(input[3]) { /* If last char is distinct than the null, user entered more than three chars */
    printf("Error! No integer between 0 and 1000 needs more than 3 chars.\n");
    return 1;
  }

  /* Check if non-digits chars where entered */
  for(i = 0; input[i]; i++) {
    if(input[i] < '0' || input[i] > '9') {
      printf("Error! You didn't enter a positive integer.\n");
      return 2;
    }      
  }
  
  /* Get the index of the last element */
  for(j = 0; input[j]; j++);
  --j;
  
  /* Put digits in their right place */
  for(i = j; i > -1; i--)
    number[i] = input[j - i] - '0';
  
  /* Output has nothig yet */  
  i = 0;

  /* Obtain the houndreds part of the ouptut */
  if(number[2]) {
    switch(number[2]) {
    case 1:
      for(j = 0; output[i] = "one"[j]; i++, j++);
      break;
    case 2:
      for(j = 0; output[i] = "two"[j]; i++, j++);
      break;
    case 3:
      for(j = 0; output[i] = "three"[j]; i++, j++);
      break;
    case 4:
      for(j = 0; output[i] = "four"[j]; i++, j++);
      break;
    case 5:
      for(j = 0; output[i] = "five"[j]; i++, j++);
      break;
    case 6:
      for(j = 0; output[i] = "six"[j]; i++, j++);
      break;
    case 7:
      for(j = 0; output[i] = "seven"[j]; i++, j++);
      break;
    case 8:
      for(j = 0; output[i] = "eight"[j]; i++, j++);
      break;
    default:
      for(j = 0; output[i] = "nine"[j]; i++, j++);
    }
      for(j = 0; output[i] = " hundred"[j]; i++, j++);
  }
  
  /* Concat. the "and" junction when necessary */
  if(number[2] && (number[1] || number[0])) {
    for(j = 0; output[i] = " and "[j]; i++, j++);
  }
  
  /* Obtain the tens part of the output */
  if(number[1]) {                                         /* Numbers that has tens */
    if(number[1] < 2) {                                   /* 10, 11, 12 or Teens */
      if(number[0] < 3) {                                 /* 10, 11 and 12 */
	switch(number[0]) {
	case 0:
	  for(j = 0; output[i] = "ten"[j]; i++, j++);
	  break;
	case 1:
	  for(j = 0; output[i] = "eleven"[j]; i++, j++);
	  break;
	default:
	  for(j = 0; output[i] = "twelve"[j]; i++, j++);
	}
      }else {                                             /* Teens */
	switch(number[0]) {
	case 3:
	  for(j = 0; output[i] = "third"[j]; i++, j++);
	  break;
	case 4:
	  for(j = 0; output[i] = "four"[j]; i++, j++);
	  break;
	case 5:
	  for(j = 0; output[i] = "fif"[j]; i++, j++);
	  break;
	case 6:
	  for(j = 0; output[i] = "six"[j]; i++, j++);
	  break;
	case 7:
	  for(j = 0; output[i] = "seven"[j]; i++, j++);
	  break;
	case 8:
	  for(j = 0; output[i] = "eitgh"[j]; i++, j++);
	  break;
	default:
	  for(j = 0; output[i] = "nine"[j]; i++, j++);
	}
	for(j = 0; output[i] = "teen"[j]; i++, j++);      /* Attach the "teen" part */
      }                                                   /* No more input processing needed from here */
      output[0] += 'A' - 'a';                             /* First letter to uppercase */
      printf("nYou entered the number: %s.\n", output);   /* Display output */
      return 0;                                           /* Finish execution */

    }else {                                               /* Twentys, thirtys.. ninetys.*/
      switch(number[1]) {
      case 2:
	for(j = 0; output[i] = "twenty"[j]; i++, j++);
	break;
      case 3: 
	for(j = 0; output[i] = "thirty"[j]; i++, j++);
	break;
      case 4:
	for(j = 0; output[i] = "fourty"[j]; i++, j++);
	break;
      case 5:
	for(j = 0; output[i] = "fifty"[j]; i++, j++);
	break;
      case 6:
	for(j = 0; output[i] = "sixty"[j]; i++, j++);
	break;
      case 7:
	for(j = 0; output[i] = "seventy"[j]; i++, j++);
	break;
      case 8:
	for(j = 0; output[i] = "eighty"[j]; i++, j++);
	break;
      default:
	for(j = 0; output[i] = "ninety"[j]; i++, j++);
      }
    }
  }

  /* Concat. the " " junction when necessary */
  if(number[1] && number[0])
    output[i++] = ' ';

  /* Obtain the units part of the output */
  if(number[0]) {
    switch(number[0]) {
    case 1:
      for(j = 0; output[i] = "one"[j]; i++, j++);
      break;
    case 2:
      for(j = 0; output[i] = "two"[j]; i++, j++);
      break;
    case 3:
      for(j = 0; output[i] = "three"[j]; i++, j++);
      break;
    case 4:
      for(j = 0; output[i] = "four"[j]; i++, j++);
      break;
    case 5:
      for(j = 0; output[i] = "five"[j]; i++, j++);
      break;
    case 6:
      for(j = 0; output[i] = "six"[j]; i++, j++);
      break;
    case 7:
      for(j = 0; output[i] = "seven"[j]; i++, j++);
      break;
    case 8:
      for(j = 0; output[i] = "eigth"[j]; i++, j++);
      break;
    default:
      for(j = 0; output[i] = "nine"[j]; i++, j++);
    }
  }
  
  /* Display output */
  output[0] += 'A' - 'a';
  printf("You entered the number: %s.\n", output);
  return 0;
}
