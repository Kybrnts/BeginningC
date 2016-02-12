/* Program 7.14A Sorting strings without Bubble Sort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 100 /* Length of input buffer    */
#define NUM_P 100      /* Maximum number of strings */

int main(void) {
  
  char buffer[BUFFER_LEN], /* Space to store an input string    */
    *pS[NUM_P] = {NULL},   /* Array of pointers                 */
    *pTemp = NULL;         /* Temporary pointer                 */
  int i = 0, j,             /* Loop counter                      */
    last_string = 0;       /* Index of the last string entered  */


  printf("\nEnter succesive lines, pressing Enter at the end of each line.\n"
         "Just press Enter to end.\n\n");

  while((*fgets(buffer, BUFFER_LEN, stdin) != '\n') && (i < NUM_P)) {
    pS[i] = (char *)malloc(strlen(buffer) + 1);
    if(pS[i] == NULL) {    /* Check for no memory allocated */
      printf("Memory allocation failed. Program terminated.\n");
      return 1;
    }
    strcpy(pS[i++], buffer);
  }
  last_string = i;         /* Save last string index        */
  
  /* Sort the strings in ascending order */
  for(i = 0; i < last_string - 1; i++)
    for(j = i + 1; j < last_string; j++)
      if(strcmp(pS[i], pS[j])) {
	pTemp = pS[i];
	pS[i] = pS[j];
	pS[j] = pTemp;
      }
  /*
   * This is another simple way to sort the contents of ps array, that seems more eficient than the one used in the
   * previous version.
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
