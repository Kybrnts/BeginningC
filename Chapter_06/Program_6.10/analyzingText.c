/* Program 6.10 Analyzing text */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXTLEN 10000   /* Maximum length of text            */
#define BUFFERSIZE 200  /* Input buffer size                 */
#define MAXWORDS 1000   /* Maximum number of different words */
#define WORDLEN  50     /* Maximum word length               */

int main(void) {
  char text[TEXTLEN + 1],
    buffer[BUFFERSIZE + 1],
    endstr[] = "*\n";                /* Signals the end of the input            */
  int i, j;                          /* Index/control flow variable             */
  const char space = ' ',            /* Defines the word space and quote        */
    quote = '\'';
  char words[MAXWORDS][WORDLEN + 1], /* Sotes all the readed words              */
    word[WORDLEN + 1];               /* Sotre  a single word                    */
  int nword[MAXWORDS],               /* Number of word occurrences              */
    wordlen = 0,                     /* Length of a word                        */
    wordcount = 0;                   /* Number of words stored                  */
  /*
   * The words array stores up to MAXWORDS word strings of length WORDLEN, excluding the terminating null. The nword
   * array hold counts of the number of occurrences of the corresponding words in the words array. Each time you find a
   * new word, you'll store it in the next available position in the words array and set the element in the nword array
   * that is at the same index position to 1. When you find a word that you have found and stored previously in words,
   * you just need to increment the corresponding element in the nword array.
   */
  _Bool isnew;                       /* Indicates if a word is present in words */


  printf("Enter text on an arbitrary number of lines."
	 "\nEnter a line containing just an asterisk to end input:\n\n");

  /* Read an arbitrary number of lines */
  while(1) {

    /* A string containing an asterisk followed by a newline */
    /* signals end of the input                              */
    if(!strcmp(fgets(buffer, BUFFERSIZE, stdin), endstr)) {
      /* 
       * The fgets() function reads a maximum of BUFFERSIZE-1 characters from stdin. If the user enters a line longer
       * than this, it won't really matter. The characters that are in excess of BUFFERSIZE-1 will be left in the input
       * stream and will be read on the next loop iteration. You can check that this works by setting BUFFERSIZE at 10,
       * say, and entering lines longer than ten characters.
       * Because the fgets() function returns a pointer to the string that you pass as the first argument, you can use
       * fgets() as the argument to the strcmp() function to compare the string that was read with endstr. Thus, the if
       * statement not only reads a line of input, it also checks whether the end of the input has been signaled by the
       * user.
       */
      break;
    }
    
    /* Check if we have space for atleast input */
    if(strlen(text) + strlen(buffer) + 1 > TEXTLEN) {
      /*
       * Before you append the new line of input to what's already stored in text, you check that there is still enough
       * free space in text to accommodate the additional line. To append the new line, just use the strcat() library
       * function to concatenate the string stored in buffer with the existing string in text.
       */
      printf("Maximum capacity for text exceeded. Terminating program.");
      return 1;
    }
    strcat(text, buffer);
  }
  
  /* Replace everything except alpha and single quote characters by spaces */
  for(i = 0; i < strlen(text); i++) {
  /*
   * This loop iterates over the characters in the string stored in the text array. We are assuming that words can only
   * contain letters, digits, and single-quote characters, so anything that is not in this set is replaced by a space
   * character.
   */
    if(text[i] == quote || isalnum(text[i]))
      continue;
    text[i] = space;
  }
 
  /* Find unique words and store in words array */
  i = 0;
  while(1) {

    /* Ignore any leading spaces before a word */
    while(text[i] == space)
      /*
       * This will skip any spaces so that the index refers to the first character of a word. This is achieved by
       * stepping the index as long as the current character is a space.
       */
      ++i;
    /* If we are at the end of text, we are done */
    if(text[i] == '\0')
      /*
       * It's possible that the end of the string in text has been reached, so you check for this next. If the current
       * character at position index is '\0', you exit the loop because all words must have been extracted.
       */
      break;

    /* Exctract a word
     * Extracting a word just involves copying any character that is alphanumeric or a single quote. The first character
     * that is not one of these marks the end of a word. You copy the characters that make up the word into the word 
     * array in another while loop, after converting each character to lowercase using the tolower() function from the
     * standard library.
     */
    wordlen = 0;                                                      /* Reset the word length         */
    while(text[i] == quote || isalpha(text[i])) {
      if(wordlen == WORDLEN) {                                        /* Check if the word is too long */	
	printf("Maximum word length exceeded. Terminating program.");
	return 1;
      }
      word[wordlen++] = tolower(text[i++]);                           /* Copy as lowercase             */
    }
    word[wordlen] = '\0';                                             /* Add string terminator         */

    /* Check for word already stored */
    isnew = 1;
    /* 
     * The isnew variable records whether the word is present and is first initialized to indicate that the latest word
     * you have extracted is indeed a new word.
     */
    for(j = 0; j < wordcount; j++) {
      /* 
       * Within the for loop you compare word with successive strings in the words array using the strcmp() library
       * function that compares two strings. The function returns 0 if the strings are identical; as soon as this occurs
       * you set isnew to false, increment the corresponding element in the nword array, and exit the for loop.
       */
      if(strcmp(word, words[j]) == 0) {
	++nword[j];
	isnew = 0;
	break;
      }
    }

    if(isnew) {
      /* Check if we have space for another word */
      if(wordcount >= MAXWORDS) {
	printf("\nMaximum word count exceeded. Terminating program.");
	return 1;
      }
      strcpy(words[wordcount], word); /* Store the new word */
      nword[wordcount++] = 1;          /* Set its count to 1 */
    }
  }
  
  /* Output the words and frequencies */
  for(i = 0; i < wordcount; i++) {
    if( !(i%3) ) { /* Three words to a line */
      printf("\n");
    }
    printf("  %-15s%5d", words[i], nword[i]);
  }
  
  return 0;
}
