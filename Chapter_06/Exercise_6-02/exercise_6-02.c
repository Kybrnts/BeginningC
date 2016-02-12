/* Exercise 6.02 */
/*
 * Write a program that will allow a list of words to be entered separated by commas, and then extract the words and
 * output them one to a line, removing any leading or trailing spaces.
 */
#include <stdio.h>
#include <wchar.h> /* Using wchar data type */
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
    output[OUTPUTLENGTH] = L"";     /* Set of words to be output */
  unsigned short i, j, k;           /* Indexes */
  bool something = 0;

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
	printf("Maximum length between commas exceeded. Terminating program.");
	return 2;
      }
      words[j++] = input[i++];
    }                        /* If the EOL char was reached, i points to that char */
    words[j] = NULLCHAR;     /* Add the string terminator */
    
    /* Output each word in words */
    j = 0;
    while(1) {
      while(words[j] == SPACE || words[j] == TAB)                              /* Ignore any leading spaces */
	++j;
      if(words[j] == NULLCHAR)                                                 /* If we got to the end of the list of */				       
	break;                                                                 /* words skip to the next list */
      
      k = 0;
      while(!(words[j] == SPACE || words[j] == TAB || words[j] == NULLCHAR)) {
	if(k == OUTPUTLENGTH) {
	    printf("Maximum output length exceeded. Terminating program.");
	    return 3;
	}
	output[k++] = words[j++];
	something = 1;
      }
      output[k] = NULLCHAR;
      printf("%S ", output);
    }
    printf("\n");
  }
  if(!something)
    printf("You entered no words.\n");
  return 0;  
}
