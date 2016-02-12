/* Program 11.5 Daisy chaining the horses both ways */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

  /* Structure declaration                              */
  struct horse {
    int age,
      height;
    char name[20],
      mother[20],
      father[20];
    struct horse *previous,      /* Pointer to previous structure (horse)  */
      *next;                     /* Pointer to next structure (horse)      */
  };
  struct horse *first = NULL,    /* Pointer to first horse of the list     */
    *current = NULL,             /* Pointer to the current horse           */
    *last = NULL;                /* Pointer to the last horse              */
  char test = '\0';              /* Test value for ending input            */

  for( ; ; ) {
    printf("\nDo you want to enter details of a%s horse (Y or N)? ", first ? "nother" : "");
    scanf(" %c", &test);    
    if(tolower((unsigned)test) == 'n')
      break;
    
    /* Allocate memory for the current (each new) horse */
    current = (struct horse *)malloc(sizeof(struct horse));
    
    if(!first) {
      first = current;           /* Set pointer to first horse             */
      current->previous = NULL;
    }else {
      last->next = current;      /* Set next address for previous horse    */
      current->previous = last;  /* Previous address for current horse     */
    }

    /* Reads current horse (each new) horse data        */
    printf("\nEnter the name of the horse: ");
    scanf("%s", current->name);
    printf("\nHow old is %s? ", current->name);
    scanf("%d", &current->age);
    printf("\nHow high is %s (in hands)? ", current->name);
    scanf("%d", &current->height);
    printf("\nWho is %s's father? ", current->name);
    scanf("%s", current->father);
    printf("\nWho is %s's mother? ", current->name);
    scanf("%s", current->mother);

    current->next = NULL;        /* In case this is the the last horse..   */
    last = current;              /* Save address of last horse             */
  }
  
  /* Now tell everything that we know                   */
  while(current) {               /* Output data in reverse order           */
    printf("\n\n%s is %d years old, %d hands high,", current->name,
	   current->age,
	   current->height);
    printf(" and has %s and %s as parents.", current->father,
	   current->mother);
    last = current;              /* Save pointer to enable memory release  */
    current = current->previous; /* Current must point to previous in list */
    free(last);                  /* Free memory for the horse we output    */
  }
  printf("\n");

  return 0;
}
