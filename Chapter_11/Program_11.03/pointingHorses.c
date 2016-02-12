/* Program 11.3 Exercising Horses */
#include <stdio.h>
#include <ctype.h>  /* Provides tolower() */
#include <stdlib.h> /* Provides  malloc() */

int main(void) {
  struct horse {             /* Structure (data type) declaration     */
    int age,
      height;
    char name[20],
      father[20],
      mother[20];
  };
  
  struct horse *phorse[50]; /* Pointer to structure array declaration */
  int i,
       hcount = 0;          /* Count of the number of horses          */
  char test = '\0';         /* Test value for ending input            */

  for(hcount = 0; hcount < 50; hcount++) {
    printf("\nDo you want to enter details of a%s horse (Y or N)? ", hcount ? "nother" : "");
    scanf(" %c", &test);
    if(tolower((unsigned)test) == 'n')
      break;
    
    /* Allocate memory to hold a structure */
    phorse[hcount] = (struct horse*)malloc(sizeof(struct horse));
    /* It's very important to use sizeof when you need the number of bytes occupied by a structure. It doesn't
     * necessarily correspond to the sum of the bytes occupied by each of its individual members, so you're likely to
     * get it wrong if you try to work it out yourself.
     * Variables other than type char are often stored beginning at an address that's a multiple of 2 for 2-byte
     * variables, a multiple of 4 for 4-byte variables, and so on. This is called boundary alignment and it has nothing
     * to do with C but is a hardware requirement where it applies. Arranging variables to be stored in memory like this
     * makes the transfer of data between the processor and memory faster. This arrangement can result in unused bytes
     * occurring between member variables of different types, though, depending on their sequence. These have to be
     * accounted for in the number of bytes allocated for a structure.
     */
    
    /* Get all allocated structure members values */
    printf("\nEnter the name of the horse: ");
    scanf("%s", phorse[hcount]->name);               /* Name          */    
    
    printf("\nHow old is %s? ", phorse[hcount]->name);
    scanf("%d", &phorse[hcount]->age);               /* Age           */
    
    printf("\nHow high is %s (in hands)? ", phorse[hcount]->name);
    scanf("%d", &phorse[hcount]->height);            /* Height        */
    
    printf("\nWho is %s's father? ", phorse[hcount]->name);
    scanf("%s", phorse[hcount]->father);             /* Father's name */

    printf("\nWho is %s's mother? ", phorse[hcount]->name);
    scanf("%s", phorse[hcount]->mother);             /* Mother's name */
  }

  /* Now tell everything that we know */
  for(i = 0; i < hcount; i++) {
    printf("\n\n%s is %d years old, %d hands high,",
           phorse[i]->name, phorse[i]->age, phorse[i]->height);
    printf(" and has %s and %s as parents.",
           phorse[i]->father, phorse[i]->mother);
    free(phorse[i]);
  }
  printf("\n");
  return 0;
}
