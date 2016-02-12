/* Program 7.11B Reallocating Memory */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  long *pData = NULL;                                     /* Stores the data                           */
  size_t count = 0,                                       /* Number of data items                      */
    oldCount = 0;                                         /* Previous count value                      */
  int i;

  while(1) {
    oldCount = count;                                     /* Save the prevoius count value             */
    printf("How many values would you like? ");
    scanf(" %u", &count);                                 /* Total is how many we need to find         */

    if(!count) {                                          /* If none required required, we are done    */
      if(!pData)                                          /* If memory is allocated                    */
	free(pData);                                      /* Release it                                */
      break;                                              /* Exit the loop                             */
    }

    /* Allocate sufficient memory to store count values */
    if(pData && count <= oldCount)                        /* If there's big enough old memory...       */
      pData = (long *)realloc(pData, sizeof(long)*count); /* realocate it                              */
    else {                                                /* If there wasn't enough old memory         */
      if(pData)                                           /* If there's old memory, release it         */
	free(pData);

      /* Allocate a new block of memory */
      pData = (long *)calloc(count, sizeof(long));
    }
    if(!pData) {                                          /* If no memory was allocated, abandon ship! */
      printf("\nNot enough memory.\n");
      return 1;
    }
    /* Read and process the data and output the result */
    printf("Please enter the %d requested values:\n", count);
    for(i = 0; i < count; i++) {
      printf("#%d> ", i + 1);
      scanf(" %ld", pData + i);
    }
    printf("You entered the following values:");
    for(i = 0; i < count; i++) {
      if(!(i%5U))
	printf("\n");
      printf("%12ld", *(pData + i));
    }
    printf("\n");
  }

  return 0;
}
