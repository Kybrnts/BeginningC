/* Exercise 10-4 */
/* Define a function using the getchar() function that will read a string from stdin terminated by a character that is
 * passed as the second argument to the function. Thus the prototype will be the following:
 * 
 *     char *getString(char *buffer, char end_char);
 * 
 * The return value is the pointer that is passed as the first argument. Write a program to demonstrate the use of the
 * function to read and output five strings that are enterd from the keyboard, each terminated by a colon.
 */
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 50
#define ENDCHAR ':'
#define STRINGNUM 5

/* Function prototypes */
char *getString(char *buffer, char end_char);
void flushin(void);
void freestring(char **string);

int main(void) {
  char *strings[STRINGNUM] = { NULL };
  int i;
  
  printf("\nPlease, enter %d \"%c\" terminated strings:\n", STRINGNUM, ENDCHAR);
  for(i = 0; i < STRINGNUM; i++) {
    strings[i] = getString(strings[i], ENDCHAR);
  }
  for(i = 0; i < STRINGNUM; i++) {
    printf("String number %d: **%s**\n", i, strings[i]);
    freestring(&strings[i]);
  }
  return 0;
}
void flushin() {
  while(getchar() != '\n');
}
char *getString(char *b, char ec) {
  int i;
  b = (char *)malloc(BUFFSIZE*sizeof(char));   /* Allocate memory in the heap and use it as buffer      */
  for(i = 0; i < BUFFSIZE; i++)                /* Read up to BUFFSIZE chars until ec is found           */
    if((*(b + i) = getchar()) == ec) {         /* If ec is found...                                     */
      *(b + i++) = '\0';                       /* ...Add terminator (Later check dondition requires it) */
      break;                                   /* ...Stop reading.                                      */
    }
  if(i == BUFFSIZE && *(b + i - 1)) {          /* Did we reach buffer boundary but '\0' not yet there?  */
    printf("/!\\ Warning /!\\ Input buffer size exceeded. Strig truncated.\n");
    *(b + i - 1) = '\0';                       /* Add string terminator anyways after warning user.     */
    flushin();                                 /* Flush remaining unreaded characters                   */
  }
  return b;                                    /* Return buffer address to calling environment          */
}
void freestring(char **s) {
  free(*s);
  *s = NULL;
}
