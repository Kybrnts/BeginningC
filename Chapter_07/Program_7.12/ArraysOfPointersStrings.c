/* Program 7.12 Arrays of Pointers to Strings */
#include <stdio.h>
#define BUFFER_LEN 512 /* Size of input buffer */
/*
 * The original statement for this code was the following:
 * "const size_t BUFFER_LEN = 512;"
 * Although it wasn't supported by tcc compiler; thus it had to be replaced w/the one above. In that case the variable
 * must be defined as constan so it could later be used as an array dimension, because array dimensions can only be
 * specified as constants.
 */

int main(void) {

  char buffer[BUFFER_LEN], /* Store for strings         */
    *pS[3] = { NULL },     /* Array of string pointers  */
    *pbuffer = buffer;     /* Pointer to buffer         */
  size_t index = 0,        /* Available buffer position */
    i;
  /*
   * Buffer will hold al the input strings. pS is an array of three pointers, that will store the addresses of the
   * strings inside buffer. pbuffer is a pointer that is initialized with the address of the first byte in buffer.
   * You'll use pbuffer to move through the buffer array as you fill it with input characters.
   * The index variable records the position of the currently unused element in buffer.
   */

  printf("\nEnter 3 messages that total less than %u characters.",
	 BUFFER_LEN - 2);

  /* Read the strings from the keyboard */
  for(i=0; i < 3; i++) {
      printf("\nEnter %s message\n", i > 0 ? "another" : "a" );
      /*
       * Here, you use a snappy way to alter the prompt in the printf() after the first iteration of the for loop, using
       * your old friend the conditional operator. This outputs "a" on the first iteration, and "another" on all
       * subsequent iterations.
       */

      pS[i] = &buffer[index];               /* Save start of string */
      /*
       * This assignment statement is storing the address stored in the pointer pbuffer in an element of the pS pointer
       * array.
       */
      
      /* Read up to the end of buffer if necessary */
      for( ; index < BUFFER_LEN; index++)   /* If you read \n ...   */
	if((*(pbuffer + index) = getchar()) == '\n') {
	    *(pbuffer + index++) = '\0';    /* ...substitute \0     */
	    break;
	}
      /*
       * In the previous for loop is where the string is readed and where its string terminator is appended as well.
       * This is the for loop that will read up to the end of buffer if necessary. If a '\n' is read, it is replaced by
       * '\0' and the loop ends.
       */
      
      /* Check for buffer capacity exceeded        */
      if((index == BUFFER_LEN) && ((*(pbuffer + index - 1) != '\0') || (i < 2))) {
	  printf("\nYou ran out of space in the buffer.");
	  return 1;
      }
      /*
       * After the loop you check for buffer being full without reaching the end of the string.
       */
  }
  
  printf("\nThe strings you entered are:\n\n");
  for(i = 0; i < 3; i++)
    printf("%s\n", pS[i]);
  /* In the loop, you output the strings that each of the elements in the pS point to. */
  
  printf("The buffer has %d characters unused.\n", BUFFER_LEN - index);
  /* Subtracting index from the number of elements in the buffer array gives the number of elements unused. */

  return 0;
}
