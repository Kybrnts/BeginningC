/* Program 7.13 Generalizing string input */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 128 /* Length of input buffer    */
#define NUM_P 100      /* Maximum number of strings */
/*
 * We may now handle up to 100 strings now, since that is the maximum number of pointers that will be held by the pS
 * variable. If we'd like to change this, we just have to change this constant declaration value.
 */

int main(void) {
  char buffer[BUFFER_LEN],  /* Input buffer             */
    *pS[NUM_P] = {NULL},    /* Array of string pointers */
    *pbuffer = buffer;      /* Pointer to buffer        */
  int i = 0;                /* Loop counter             */
  /*
   * The buffer array is now just an input buffer that will contain each string as you read it. Therefore, the #define
   * directive for BUFFER_LEN now defines the maximum length of string you can accept.
   * You then have the declaration for your pointer array of length NUM_P, and your pointer, pbuffer, for working within
   * buffer. Finally, you have a couple of loop control variables.
   */

  printf("\nYou can enter up to %u messages each upt to %u characters.", NUM_P, BUFFER_LEN - 1);
  /*
   * This is for explaining what the inpunt constraints are.
   */

  for(i = 0; i < NUM_P; i++) {
    /*
     * The first for loop reads the strings and stores them. This ensures that you can input only as many strings as
     * there are pointers that you've declared. Once you've entered the maximum number of strings, the loop ends and you
     * fall through to the output section of the program.
     */

    pbuffer = buffer; /* Set pointer at beginning of the buffer */
    printf("\nEnter %s message, or press Enter to end\n", i > 0 ? "another" : "a");
    
    /* Read a string of up to BUFFER_LEN characters */
    while((pbuffer - buffer < BUFFER_LEN - 1) && ((*pbuffer++ = getchar()) != '\n'));
    /*
     * Here, a character obtained by getchar() is stored at the address pointed to by pbuffer, which starts out as the
     * address of buffer. The pbuffer pointer is then incremented to point to the next available space, and the
     * character that was stored as a result of the assignment is compared with '\n'. If it's '\n', the loop terminates.
     * The loop will also end if the expression pbuffer - buffer < BUFFER_LEN-1 is false. This will occur if the next
     * character to be stored will occupy the last position in the buffer array.
     */

    /* Check for empty line indicating end of input */
    if((pbuffer - buffer) < 2)
      break;
    /*
     * This detects an empty line because if you just press the Enter key only one character will be entered: the '\n'.
     * In this case, the break statement immediately exits the for loop and begins the output process.
     */
    
    /* Check for string too long                    */
    if((pbuffer - buffer) == BUFFER_LEN && *(pbuffer - 1) != 'n') {
      i--;
      continue;
    }
    /*
     * This if statement checks whether you attempted to enter a string longer than the capacity of buffer. Because you
     * end the while loop when the last position in the buffer array has been used, if you attempt to enter more
     * characters than the capacity of buffer, the expression pbuffer-buffer will be equal to BUFFER_LEN. Of course,
     * this will also be the case if you enter a string that fits exactly, so you must also check the last character in
     * buffer to see if it's '\n'. If it isn't, you tried to enter too many characters, so you decrement the loop
     * counter after displaying a message and go to the next iteration.
     */
    
    *(pbuffer - 1) = '\0';  /* Add terminator */
    /*
     * This places the '\0' in the position occupied by the '\n' character, because pbuffer was left pointing to the
     * first free element in the array buffer.
     */

    pS[i] = (char *)malloc(pbuffer - buffer); /* Get memory for string */
    if(pS[i] == NULL) {     /* Check if could actually get some */
      printf("\nOut of memory - ending program.");
      return 1;             /* Exit if didn't */
    }
    /*
     * The number of bytes required is the difference between the address currently pointed to by pbuffer, which is the
     * first vacant element in buffer, and the address of the first element of buffer. The pointer returned from
     * malloc() is stored in the current element of the pS array, after casting it to type char. If you get a NULL
     * pointer back from malloc(), you display a message and end the program.
     */
    
    /* Copy string from buffer to new memory        */
    strcpy(pS[i], buffer);
    /*
     * This uses the library function, strcpy(), to copy the contents of buffer to the memory pointed to by pS[i]. Take
     * care not to confuse the arguments when using the strcpy() function; the second argument is the source and the
     * first argument is the destination for the copy operation. Getting them mixed up is usually disastrous, because
     * copying continues until a '\0' is found.
     */
  }
  
  /* Output all the strings */
  printf("\nIn reverse order, the strings you entered are: \n");
  while(--i >= 0) {
    printf("\n%s", pS[i]);  /* Display strings last to first */
    free(pS[i]);            /* Release the memory we got */
    pS[i] = NULL;           /* Set pointer back to NULL for safety */
  }
  /*
   * The index i will have a value one greater than the number of strings entered. So after the first loop condition
   * check, you can use it to index the last string. The loop continues counting down from this value and the last
   * iteration will be with i at 0, which will index the first string. You could use the expression *(pS + i) instead
   * of pS[i], but using array notation is much clearer.
   * You use the function, free(), after the last printf(). This function is complementary to malloc(), and it releases
   * memory previously allocated by malloc(). It only requires the pointer to the memory allocated as an argument.
   * Although memory will be freed at the end of the program automatically, it's good practice to free memory as soon as
   * you no longer need it. Of course, once you have freed memory in this way, you can't use it, so it's a good idea to
   * set the pointer to NULL immediately, as was done here.
   */

  return 0;
}
