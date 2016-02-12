/* Exercise 10-1 */
/* Write a program that will read, store, and output the following five types of strings on separate lines, when one of
 * each type of string is entered on a single line without spaces between the lines:
 * * Type 1: A sequence of lowercase letters followed by a digit (e.g., number1)
 * * Type 2: Two words that both begin with a capital letter and have a hyphen between them (e.g., Seven-Up)
 * * Type 3: A decimal value (e.g., 7.35)
 * * Type 4: A sequence of upper- and lowercase letters and spaces (e.g., Oliver Hardy)
 * * Type 5: A sequence of any characters except spaces and digits (e.g., floating-point)
 * 
 * The following is a sample of input that should be read as five separate strings:
 * babylon5John-Boy3.14159Stan Laurel'Winner!'
 */
#include <stdio.h>  /* Provides scanf() and printf() */
#include <stdlib.h> /* Provides malloc()             */

#define WORDLEN 50 /* Maximum input word length */
int showDebug = 0; /* Running in debug mode?    */

const char debugsymbl[] = "-d";                                    /* Debug option symbol      */
const char formatspec[] = "%[a-z]%1[0-9]"                          /* Type 1 format specifier  */
                          "%1[A-Z]%[A-Za-z]%*1[-]%1[A-Z]%[A-Za-z]" /* Typ2 2 format specifier  */
                          "%f"                                     /* Type 3 format specifier  */
                          "%[A-Za-z ]"                             /* Type 4 format specifier  */
                          "%[^0-9 \n]"                             /* Type 5 format specifier  */
                          "%n";                                    /* Store read bytes ammount */

/* Function prototypes */
size_t mystrlen(const char *string);             /* Measures the length of the argument string            */
int mystrcpy(char *dest, const char *orig);      /* Copies the second argument string in the first one    */
int istoken(const char *str, const char *token); /* Determines if a string is a token, i.e. special       */
void flushln(void);                              /* Flush remaining chars of a line when readln fails     */
void freestr(char **s);                          /* Release heap memory used by string                    */
int readln(char *strings[]);                     /* Function to read an entire line into strings          */
char *decToString(float decimal);                /* Returns the string representation of a decimal number */
void writelns(char *strings[]);                  /* Function to write the five strings                    */

int main(int argc, char *argv[]) {

  int fails;                   /* Read line failed attempts counter    */
  char *strings[5] = { NULL }; /* List of strings of 5 different types */

  /* Test for debug option */
  if(argc > 1 && istoken(argv[1], debugsymbl)) {
    showDebug = 1;
  }

  /* Try to read a line no more than five times */
  for(fails = 0; fails < 5; fails++) {
    if(fails > 0)
      printf("Please try again. ");
    printf("Enter the five types of strings in a single line\n");
    if(readln(strings) == 0)
      break;
    flushln(); /* If fails, clear stdin */
  }
  if(fails == 5)
    return 1;
  writelns(strings);
  return 0;
}

/* Function to measure the lenght of a string */
size_t mystrlen(const char *c) {
  size_t n = 0;   /* Starts counter in 0                          */
  while(*(c + n)) /* Does c + counter offset points to '\0'?      */
    n++;          /* No, hence increase the counter and ask again */
  return n;       /* Yes, then return the counter                 */
}
/* Function to copy one string to a heap location to another */
int mystrcpy(char *d, const char *o) {
  int n = 0;           /* Starts counter in 0                                                 */
  while((*d++ = *o++)) /* Copy *o value to *d and step the pointers. Does d points to '\0'?   */
    n++;               /* No, then increase the counter, copy and step pointers and aks again */
  return n;            /* Yes, return the counter                                             */
}
/* Functio to compare one string against a special string */
int istoken(const char *s, const char *t) {
  
  while(*s == *t && *s && *t) { /* Compare each char of the first string against the one in */
    s++;                        /* the other in a matching position.                        */
    t++;                        /* Stop comparing if a null char is reached or if any       */
  }                             /* difference is found.                                     */
  if(*s || *t)                  /* Are we at the end of both strings ?                      */
    return 0;                   /* Yes, so the string matches the token                     */
  return 1;                     /* No, so they do not match.                                */
}
/* Function to flush remaining characters of an input line */
void flushln(void) {
  while(getchar() != '\n'); /* Read chars until EOL is read */
}
/* Function to release the memory used by a string */
void freestr(char **s) {
  free(*s);
  *s = NULL; /* This is why we need **s as a parameter, *s wouldn't work */
}
/* Function to convert a decimal value to a string */
char *decToString(float dec) {
  char *string = NULL;
  int result;
  string = (char *)malloc(11*sizeof(char));
  result = sprintf(string, "%010.5f", dec);
  if(result > 10)
    printf("/!\\Warning/!\\ The decimal value has been truncated.\n");
  return string;
}
/* Function to read an entire line of input */
int readln(char *strs[]) {

  int value_count = 0,
    byte_count = 0;
  size_t len = 0;
  char t1_word[WORDLEN] = "",
    t1_digit[2] = "";
  char t2_cap1[2] = "",
    t2_word1[WORDLEN] = "",
    t2_cap2[2] = "",
    t2_word2[WORDLEN] = "";
  float t3_decimal;
  char t4_word[WORDLEN] = "";
  char t5_word[WORDLEN] = "";

  value_count = scanf(formatspec, t1_word, t1_digit,
		      t2_cap1, t2_word1,
		      t2_cap2, t2_word2,
		      &t3_decimal,
		      t4_word,
		      t5_word,
		      &byte_count);

  /* Show debug info. by demand */
  if(showDebug) {
    printf("\nDebug info. *************************************************************** Debug info.\nRaw entered values:\n");
    printf("Formatspec = %s\n", formatspec);
    printf("Value_count = %d byte_count = %d\n", value_count, byte_count);
    printf("t1_word = %s t1_digit = %s\n", t1_word, t1_digit);
    printf("t2_cap1 = %s t2_word1 = %s t2_cap2 = %s t2_word2 = %s\n", t2_cap1, t2_word1, t2_cap2, t2_word2);
    printf("t1_decimal = %f\n", t3_decimal);
    printf("t4_word = %s\n", t4_word);
    printf("t5_word = %s\n", t5_word);
    printf("Debug info. *************************************************************** Debug info.\n\n");
  }

  /* Fail if necessary */
  if(value_count != 5) {
    printf("Invalid input entered.\n");
    return 1;
  }
  /* Assemble type1 string in the first element of the array */
  len = mystrlen(t1_word);
  strs[0] = (char *)malloc((len + 2)*sizeof(char));
  mystrcpy(strs[0], t1_word);
  mystrcpy(strs[0] + len, t1_digit);

  /* Assemble type2 string in the second element */
  strs[1] = (char *)malloc((mystrlen(t2_word1) + mystrlen(t2_word2) + 3)*sizeof(char));
  mystrcpy(strs[1], t2_cap1);
  mystrcpy(strs[1] + 1, t2_word1);
  len = mystrlen(t2_word1) + 1;
  mystrcpy(strs[1] + len, t2_cap2);
  mystrcpy(strs[1] + len + 1, t2_word2);

  /* Assemble type3 string in the third element */
  strs[2] = decToString(t3_decimal); /* Convert decimal value to string */

  /* Assempble typ4 string in the third element */
  len = mystrlen(t4_word);
  strs[3] = (char *)malloc((len + 1)*sizeof(char));
  mystrcpy(strs[3], t4_word);

  /* Assemble type5 string in the fourth element */
  len = mystrlen(t5_word);
  strs[4] = (char *)malloc((len + 1)*sizeof(char));
  mystrcpy(strs[4], t5_word);

  return 0;
}
/* Function to display and destroy the array type list */
void writelns(char *strs[]) {
  int i;
  printf("\n");
  for(i = 0; i < 5; i++) {
    printf("String type %d = :%s:\n", i, strs[i]);
    freestr(&strs[i]);
  }
}
