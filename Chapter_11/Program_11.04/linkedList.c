/* Program 11.4 Daisy chaining horses */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(void) {
  
  struct horse {               /* Structure declaration   */
    int age,
      height;
    char name[20],
      father[20],
      mother[20];
    struct horse *next;
    /* We've added a member to the structure horse with the name next, which is a pointer to a horse type structure.
     * This will be used to link together all the horses you have, where each horse structure will have a pointer
     * containing the address of the next. The last structure will be an exception, of course: its next pointer will be
     * NULL. The structure is otherwise exactly as you had previously.
     */
  };
  
  struct horse *first = NULL, /* Pointer to first horse   */
    *current = NULL,          /* Pointer to current horse */
    *previous = NULL;         /* Pointer to last horse    */
  /* 
   * Each of this members has been defined as a pointer to a horse structure. The pointer "first" is used solely to
   * store the address of the first structure. The second and third pointers are working storage: "current" holds the
   * address of the current horse structure that we're dealing with, and "previous" keeps track of the address of the
   * previous structure that was processed.
   */
  char test = '\0';           /* Ending input test value  */
  
  for( ; ; ) {
  /* The input loop is now an indefinite loop, because you don't have an array to worry about. You don't need to mess
   * around with indexes. It's also unnecessary to keep count of how many sets of data are read in, so you don't need
   * the variable hcount or the loop variable i. Because you allocate memory for each horse, you can just take them as
   * they come.
   */
    printf("\nDo you want to enter details of a%s horse (Y or N)? ", first ? "nother" : "");
    /*
     * We used "first" to get a slightly different prompt on the second and subsequent iterations, because the only
     * time it should be NULL is on the first one.
     */
    scanf(" %c", &test);
    if(tolower((unsigned)test) == 'n')
      break;
    /*
     * After prompting, we exit from loop if the response 'n' or 'N' is detected, otherwise, you expect another set of
     * structure members to be entered.
     */
    current = (struct horse*)malloc(sizeof(struct horse));
    /*
     * On each iteration, the memory is allocatd for the current structure. To keep it short we didn't check for a NULL
     * malloc() return, but in practice is neccessary.
     */
    
    if(!first)                               /* Is this the first horse?                 */
      first = current;                       /* Yes, then save pointer to this horse     */
    /*
     * If the first pointer is NULL, we are on the first iteration, and this is the first structure to be entered, hence
     * we need to set the "first" to the value that malloc() returned. This address is key to access the first horse in
     * the chain.
     * Is it possible to access any element of the horse chain by starting w/the address of "first" and then looking in
     * the memeber pointer "next" to get the address of the next horse, and so on.
     */
    
    if(previous)                             /* Is this the following of some horse?     */
      previous->next = current;              /* Yes, current horse is next of previous   */
    /*
     * The "next" member of any horse needs to point to the next horse (if there is one), however the address of the
     * next structure can be determined only once you allocated it, therefore on SECOND and subsequent iterations we
     * need to store the address of "current" to "next" previous's structure member.
     * For the first iteration (first horse) the pointer "previous" will be NULL, hence doing nothing.
     */
    
    /* Get all allocated structure members values */
    printf("\nEnter the name of the horse: ");
    scanf("%s", current->name);               /* Name          */    
    
    printf("\nHow old is %s? ", current->name);
    scanf("%d", &current->age);               /* Age           */
    
    printf("\nHow high is %s (in hands)? ", current->name);
    scanf("%d", &current->height);            /* Height        */
    
    printf("\nWho is %s's father? ", current->name);
    scanf("%s", current->father);             /* Father's name */

    printf("\nWho is %s's mother? ", current->name);
    scanf("%s", current->mother);             /* Mother's name */

    current->next = NULL;                     /* In case this is the last horse entered, */
                                              /* indicate that there is no next one      */
    previous = current;                       /* Next one cannot be the first, save it.  */
    /*
     * The pointer "next", member of the structure pointed by current is set to NULL, in case this is the last
     * structure; if in fact there is a next one, the "next" member will be set in the next iteration. The pointer
     * previous is set to current and is ready for the next iteration, when the "current" structure will indeed be
     * the previous one.
     */
  }

  /* Now tell everything that we know */
  current = first;                            /* Start at the beginning                  */
  while(current) {                            /* As long as we have a next one           */

    /* Output all the data */
    printf("\n\n%s is %d years old, %d hands high,", current->name,
	                                             current->age,
	                                             current->height);
    printf(" and has %s and %s as parents.", current->father,
	                                     current->mother);
    previous = current;                       /* Save the pointer so we can free memory  */
    current = current->next;                  /* Get the pointer to the next one         */
    free(previous);                           /* Free memory for the old one             */
  } 
  printf("\n");
  return 0;
}
