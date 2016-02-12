/* Exercise 6.02 */
/*
 * Write a program that will allow a list of words to be entered separated by commas, and then extract the words and
 * output them one to a line, removing any leading or trailing spaces.
 */
#include <stdio.h>
#include <wchar.h>   /* Using wchar data type */
#include <stdbool.h>

#define INPUTLENGTH 500
#define WORDSLENGTH 50
#define OUTPUTLENGTH 25
#define EOL L'\n'
#define NULLCHAR L'\0'
#define COMMA L','
#define SPACE L' '
#define TAB L'\t'

int main(void) {
  /* Defining suitable variables */
  wchar_t input[INPUTLENGTH] = L"", /* Input buffer */
    words[WORDSLENGTH]= L"",        /* Set of words from the input */
    output[OUTPUTLENGTH] = L"";     /* Single word to be output */
  unsigned short i, j, k;           /* Indexes */
  bool something = 0,               /* Flag for emtpy output */
    firstword;                      /* Flag for first word of words */

  /* Read big string from stdin */
  printf("\nPlease enter a comma (,) separated word list:\n");
  if(fgetws(input, INPUTLENGTH, stdin) == NULL) {
    printf("Error! Failed while reading from stdin. Finishing program.");
    return 1;
  }
  
  printf("\nYou entered the following word list:\n");

  i = 0;
  while(1) {
    /* Ignore any leading commas before a list of words */
    while(input[i] == COMMA)
      ++i;

    /* If we get to the end of line character, then we must finish */
    if(input[i] == EOL)
      break;

    /* Get words between commas */
    j = 0;                   /* Reset the word possition */
    while(!(input[i] == COMMA || input[i] == EOL)) {
      if(j == WORDSLENGTH) { /* Check if there's enough space for additional character */
	                     /* We need one extra char for the string terminator */
	printf("Error! Maximum length between commas exceeded. Terminating program.");
	return 2;
      }
      words[j++] = input[i++];
    }                        /* If the EOL char was reached, i points to that char */
    words[j] = NULLCHAR;     /* Add the string terminator */
    
    /* Output each word in words */
    j = 0;
    firstword = 1;
    while(1) {
      while(words[j] == SPACE || words[j] == TAB)                              /* Ignore any leading spaces */
	++j;
      if(words[j] == NULLCHAR)                                                 /* If we got to the end of the list of */				       
	break;                                                                 /* words skip to the next list */
      
      k = 0;
      while(!(words[j] == SPACE || words[j] == TAB || words[j] == NULLCHAR)) { /* Keep skipping empty spaces */
	if(k == OUTPUTLENGTH) {
	    printf("Error! Maximum output length exceeded. Terminating program.");
	    return 3;
	}
	output[k++] = words[j++];
	something = 1;                                                        /* There should be at least one char */
      }
      output[k] = NULLCHAR;
      if(firstword)
	firstword = 0;
	printf("\n%S", output);
      else
	printf(" %S", output);
    }
  }
  if(!something) {
    printf("Error! You entered no words.\n");
    return 4;
  }
  return 0;  
}
