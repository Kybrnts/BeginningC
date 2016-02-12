/* Program 7.14 Sorting strings */
/* 
 * Overall operation:
 *   i) Read in all teh input strings;
 *  ii) Sort the input strings in order;  
 * iii) Display the input strings in alphabetical order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_LEN 100 /* Length of input buffer    */
#define NUM_P 100      /* Maximum number of strings */

int main(void) {
  
  char buffer[BUFFER_LEN], /* Space to store an input string    */
    *pS[NUM_P] = {NULL},   /* Array of pointers                 */
    *pTemp = NULL;         /* Temporary pointer                 */
  int i = 0,               /* Loop counter                      */
    last_string = 0;       /* Index of the last string entered  */
  bool sorted = false;     /* Indicated when strings are sorted */


  printf("\nEnter succesive lines, pressing Enter at the end of each line.\n"
         "Just press Enter to end.\n\n");

  while((*fgets(buffer, BUFFER_LEN, stdin) != '\n') && (i < NUM_P)) {
    /* 
     * The fgets() function reads a complete string up to the point where the user press Enter, then adds '\0' to the
     * end, so that the capacity of buffer will not bee exceeded.
     * * Its first argument is a pointer to the memory area where the sting is to be stored;
     * * The second one is the max number of chars that can be stored;
     * * And the last one indicates the stream to be read.
     * * Finally the return value is either the address where the input string is stored (buffer in this case) or NULL
     *   if something goes wrong.
     * Remember that fgets() stores the '\n' that terminates the string before appending the '\0' whereas gets() does
     * not.
     *
     * The input process continues untill one of this happens:
     * * An empty line is entered (i.e. a line which its first character is '\n')
     * * Run out of space in the pointer array (i.e. the number of read attempts is greater than its size).
     */

    pS[i] = (char *)malloc(strlen(buffer) + 1);
    /*
     * As soon as each input line is collected in buffer, the correct amount of memory is allocated by malloc(). We get
     * the required number of bytes using the strlen() function and adding 1 for the '\0'.
     */

    if(pS[i] == NULL) {    /* Check for no memory allocated */
      printf("Memory allocation failed. Program terminated.\n");
      return 1;
    }
    strcpy(pS[i++], buffer);
    /*
     * After verifying that the required amount of memory was allocated, the string from buffer is copied to the newly
     * allocated piece of memory, using strcopy(). Afterwards we'll need to save the index of this last entered string
     * so that the "i" index could be reused.
     */
  }
  last_string = i;         /* Save last string index        */
  
  /* Sort the strings in ascending order */
  /*
   * Now that we save all the input strings in memory, we are going to sort them using a simple mechanism.
   * Pleasse note that this is NOT an efficient sort going, though it is easy to follow.
   */

  while(!sorted) {
    /*
     * The sort takes place here, and continues untill "sorted" is true.
     */
    sorted = true;
    for(i = 0; i < last_string - 1; i++)
      if(strcmp(pS[i], pS[i + 1]) > 0) {
	/*
         * Compare a pair of strings using the strcomp(). If the first string is greater than the second, swap the
	 * pointer values, though the strings themselves remain undisturbed exactly where they where in memory.
         * The time needed for swaping just the addresses is a fraction of the required to swap the entire strings.
         */
	sorted = false;    /* We were out of order */
	pTemp = pS[i];     /* Swap pointers pS[i]  */
	pS[i] = pS[i + 1]; /* and                  */
	pS[i + 1] = pTemp; /* pS[i + 1]            */
      }
  }
  /*
   * The swapping continues through all the string pointers:
   * * If we have to interchange any strings as we pass through them, we set sorted to false to repeat the whole thing.
   * * If we repeat the whole thing without interchanging any, then they're in order and we've finished the sort.
   * * We track the status of this with the bool variable sorted that is set to true at the beginning of each cycle, but
   *   if any interchange occurs, it gets set back to false.
   * * If we exit a cycle with sorted still true, it means that no interchanges occurred, so everything must be in order
   *   thus, we exit from the while loop.
   *
   * The reason this sort is none too good is that each pass through all the items only moves a value by one position
   * in the list. In the worst case, when we have the first entry in the last position, the number of times we have to
   * repeat the process is one less than the number of entries in the list. This inefficient but nevertheless famous
   * method of sorting is known as a "Bubble Sort".
   *
   * Handling strings and other kinds of data using pointers in this way is an extremely powerful mechanism in C. We can
   * throw the basic data (the strings, in this case) into a bucket of memory in any old order, and then we can process
   * them in any sequence you like without moving the data at all. We just change the pointers. We could use ideas from
   * this example as a base for programs for sorting any text. We had better find a better sort of sort, though.
   */
  
  /* Display the sorted strings */
  printf("\nYour input sorted in order is:\n\n");
  for(i = 0; i < last_string; i++) {
    printf("%s\n", pS[i]);
    free(pS[i]);
    pS[i] = NULL;
  }

  return 0;
}
