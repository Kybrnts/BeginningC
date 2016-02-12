/* Program 10.7 Reading and unreading characters */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH (size_t)50

/* Function prototypes */
void eatspaces(void);
bool getinteger(int *n);
char *getname(char *name, size_t length);
bool isnewline(void);

int main(void) {
  int number;
  char name[LENGTH];
  
  printf("Enter a sequence of integers and alphabetic names:\n");
  while(!isnewline())
    if(getinteger(&number))
      printf("\nInteger value:%8d", number);
    else if(strlen(getname(name, LENGTH)) > 0)
      printf("\nName: %s", name);
    else {
      printf("\nInvalid input.");
      return 1;
    }
  return 0;
}

/* Function to check for newline */
bool isnewline(void) {
  char ch = 0;
  if((ch = getchar()) == '\n')
    return true;
  
  ungetc(ch, stdin);
  return false;
}

/* Function to ignore spaces from standard input */
void eatspaces(void) {
  unsigned char ch = 0;
  while(isspace(ch = getchar()));
  ungetc(ch, stdin);
}

/* Function to read an integer from standard input */
bool getinteger(int *n) {
  int value = 0,
  sign = 1;
  unsigned char ch = 0;
  
  eatspaces();
  /* Check first character */
  if((ch = getchar()) == '-')      /* Should be minus */
    sign = -1;
  else if(isdigit(ch))             /* ... or a digit  */
    value = 10*value + (ch - '0');
  else if(ch != '+') {
    ungetc(ch, stdin);
    return false;
  }
  
  /* Find more digits */
  while(isdigit(ch = getchar()))
    value = 10*value + (ch - '0');
  
  /* Push back first nondigit character */
  ungetc(ch, stdin);
  *n = value*sign;
  return true;
}

/* Function to read an alphabetic name from input */
char *getname(char *name, size_t length) {
  size_t count = 0;
  unsigned char ch = 0;
  eatspaces();                     /* Remove leading spaces        */
  while(isalpha(ch = getchar())) { /* As long as there are letters */
    name[count++] = ch;            /* store them in name           */
    if(count == length - 1)
      break;
  }
  name[count] = '\0';             /* Append string terminator      */
  if(count < length - 1)
    ungetc(ch, stdin);            /* Return nonletter to stream    */
  return name;
}
