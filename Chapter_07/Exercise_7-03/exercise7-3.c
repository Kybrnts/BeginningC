/* Exercise 7.03 */
/*
 * Write a program that will read a string from the keyboard and display it after removing all spaces and puncuation
 * characters. All operations should use pointers.
 */
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

#define LINESIZE 20
#define EOL L'\n'
#define NULCHR L'\0'
#define SPACE L' '
#define TAB L'\t'
#define POINT L'.'
#define COMMA L','
#define COLON L':'
#define SEMICOLON L';'

int main(void) {
  
  wchar_t *line = NULL;
  unsigned short i = 0;

  /* Allocate memory for the input line */
  line = (wchar_t *)malloc(LINESIZE*sizeof(wchar_t)); /* Add one extra space for the line terminator char */
  if(!line) { /* If unable to allocate memory finish program */
    printf("Error! Unable to allocate memory for \"line\"");
    return 1;
  }
  
  /* Prompt the user to enter a string */
  printf("Enter a line of text:\n");

  /* Read each character from stdin to "line" up to EOL, except spaces and punctuation characters */
  for(i = 0;  i < LINESIZE; i++) {
    if((*(line + i) = getwchar()) == EOL) {
      *(line + i++) = NULCHR;
      break;
    }
    if(*(line + i) == SPACE || *(line + i) == TAB
       || *(line + i) == POINT || *(line + i) == COMMA || *(line + i) == COLON || *(line + i) == SEMICOLON)
      i--;
  }
  if(i == LINESIZE && *(line + i - 1) != NULCHR) {
    printf("Error! Input line is too long");
    return 2;
  }

  /* Print the output */
  printf("Entered line without spaces or punctuation chars is:\n%S\n", line);

  return 0;
}
