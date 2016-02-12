/* Exercise 8.04 */
/*
 * Define a function that will return the number of words in a string that is passed as an argument. (Words are
 * separated by spaces or punctuation characters. Assume the string doesn't contain embedded single or double quotes
 * that is, no words such as "isn't".) Define a second function that will segment a string that's passed as the first
 * argument to the function into words, and return the words stored in the array that's passed as the second argument.
 * Define a third function that will return the number of letters in a string that's passed as the argument. Use these
 * functions to implement a program that will read a string containing text from the keyboard and then output all the
 * words from the text ordered from the shortest to the longest.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SPACE ' '
#define TAB '\t'
#define POINT '.'
#define COMMA ','
#define COLON ':'
#define SEMICOLON ';'
#define EOLN '\n'
#define ESTR '\0'
#define INPUTSIZE 512

short stringIn(char *inputString);

size_t wordNum(const char *string);                 /* Function prototype of the fist one required by the problem */
short stringSeg(const char *string, char *words[]); /* Prototype for the second required                          */
size_t letterNumber(const char *string);            /* Prototype for the third required                           */

bool isWordSeparator(const char c);
void wordsSort(const char *strsToSort[], size_t size);
void swap(void **pointer1, void **pointer2);
void wordsOut(char *strs[], size_t size);

int main(void) {

  char **words = NULL,
    *input = NULL;
  size_t wordsSize = 0;

  input = (char *)malloc(INPUTSIZE*sizeof(char));
  if(!input) {
    printf("Earror! Unable to allocate memory for the input string. Finishing program..");
    return 1;    
  }

  printf("Enter a phrase to be split into words:\n\n");  
  while(stringIn(input) != 0);
  
  wordsSize = wordNum(input);

  words = (char **)calloc(wordsSize, sizeof(char *));
  if(!words) {
    printf("Error! Unable to allocate memory for the words array. Finishing program..");
    return 1;
  }
  
  if(stringSeg(input, words) != 0) {
    return 2;
  }
  
  free(input);
  input = NULL;
  
  wordsSort(words, wordsSize);

  wordsOut(words, wordsSize);

  return 0;
}

/**********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 **********************************************************************************************************************/
short stringIn(char *input) {

  size_t i;

  for(i = 0; i < INPUTSIZE; i++)
    if((*(input + i) = getchar()) == '\n') {
      *(input + i++) = '\0';
      break;                               
    }
  if(i == INPUTSIZE && *(input + i - 1)) {
    printf("Error! Input buffer size exceeded. Try again.\n");
    while(getchar() != '\n');
    return 1;
  }
  return 0;
}

/**********************************************************************************************************************
 * Function    : stringSeg											      *
 * Inputs      : const char *str, receives a reference to the string to segment.				      *
 * Outputs     : char *w[], receives a reference to the array in which to store each word of the input string	      *
 * Return      : N/A												      *
 * Description : This is the second function required in the problem description (see above)			      *
 *               												      *
 **********************************************************************************************************************/
short stringSeg(const char *str, char *w[]) {
  
  unsigned short i = 0;
  size_t wordsize = 0;

  while(1) {

    /* Ignore leading word separators               */
    while(isWordSeparator(*str) && *str)
      str++;

    /* If we reached the end of the string */
    if(*str == ESTR)
      break;

    /* Get size of incoming word, and allocate memory for it */
    wordsize = letterNumber(str) + 1;
    w[i] = (char *)malloc(wordsize*sizeof(char));
    if(!w[i]) {
      printf("Error! unable to allocate memory for word %d.", i);
      return 1;
    }
    
    /* Copy the word to the just-created space in memory */
    strncpy(w[i], str, wordsize - 1);
    
    /* Add string terminator and increment the word counter */
    *(w[i++] + wordsize) = ESTR;

    /* Skip the pointer to the end of the word */
    str += wordsize - 1;
  }
  return 0;
}

/**********************************************************************************************************************
 * Function    : WordNum											      *
 * Inputs      : const char *str. Receives a reference to the string phrase.					      *
 * Outputs     : N/A												      *
 * Return      : Unsigned. Returns the number of words in the referenced string phrase.				      *
 * Description : Walk through the input referenced string, character by character, counting the found words in a      *
 *               counter. When a word separator char is found, if it was already inside a word, increase the counter. *
 *               												      *
 **********************************************************************************************************************/
size_t wordNum(const char *str) {

  size_t words = 0;    /* Word counter                                                        */
  bool inword = false; /* Flag that indicates if the current referenced char is inside a word */

  do {
    if(isWordSeparator(*str)) { /* If the current character is a word speparator */
      if(inword) {
	inword = false;         /* The word finishes, and increase the counter   */
	words++;
      }
    }else
      inword = true;
  } while(*str++);

  return words;
}

/**********************************************************************************************************************
 * Function    : letterNumber											      *
 * Inputs      : Const char *str. Receives a reference to the word string.					      *
 * Outputs     : N/A												      *
 * Return      : size_t. Returns the number of letter in the referenced string word.				      *
 * Description : Walk through the input referenced word, character by character, counting the found letters in a      *
 *               counter. When a word separator char is found, stop and return the counter value                      *
 *               												      *
 **********************************************************************************************************************/
size_t letterNumber(const char *word) {
  
  size_t letters = 0;

  while(!isWordSeparator(*word++))
    letters++;

  return letters;
}


/**********************************************************************************************************************
 * Function    : isWordSeparator										      *
 * Inputs      : Const char c. Receives a copy of the character value to analize.				      *
 * Outputs     : N/A												      *
 * Return      : bool.												      *
 * Description : Returns true in case the input character is a word separator, otherwise returns false.		      *
 *               												      *
 **********************************************************************************************************************/
bool isWordSeparator(const char c) {
  switch(c) {
  case ESTR: case SPACE: case TAB: case EOLN: case POINT:
  case COMMA: case COLON: case SEMICOLON:
    return true;
  default:
    return false;
  }
  /* Search for "C switch flowchart" if you find this a little confusing. */
}

/**********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 **********************************************************************************************************************/
void wordsSort(const char *strs[], size_t n) {

  size_t i, j;

  for(i = 0; i < n - 1; i++)
    for(j = i + 1; j < n; j++)
      if(strcmp(strs[i], strs[j]) > 0)
	swap(&strs[i], &strs[j]);
}

/**********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 **********************************************************************************************************************/
void swap(void **p1, void **p2) {
  
  void *temp = *p1;

  *p1 = *p2;
  *p2 = temp;
}

/**********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 **********************************************************************************************************************/
void  wordsOut(char **p, size_t n) {
  int i;
  
  printf("\nYour input sorted in order is:\n\n");
  for(i = 0; i < n; i++) {
    printf("%s\n", *p);
    free(*p);
    *p++ = NULL;
  }
  printf("\n");
}
