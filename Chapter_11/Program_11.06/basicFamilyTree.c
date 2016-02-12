/* Program 11.6 Basics of a family tree */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Family *get_person(void); /* Prototype for the function   */

struct Date {
  int day,
    month,
    year;
};
struct Family {                  /* Family structure declaration */
  struct Date dob;
  char name[20],
    father[20],
    mother[20];
  struct Family *next,           /* Pointer to next structure    */
    *previous;                   /* Pointer to last structure    */
};

int main(void) {
  struct Family *first = NULL,   /* Pointer to  first structure       */
    *current = NULL,             /* Pointer to current structure      */
    *last = NULL;                /* Pointer to last structure         */
  char more = '\0';              /* Test value for ending input       */

  for( ; ; ) {
    printf("\nDo you want to enter details of a%s person (Y or N)? ", first ? "nother" : "");
    scanf(" %c", &more);
    if(tolower((unsigned)more) == 'n')
      break;

    current = get_person();
 
    if(!first) {
      first = current;           /* Set pointer to first family       */
      last = current;            /* Remember for next iteration       */
    }else {
      last->next = current;      /* Set next addr for previous Family */
      current->previous = last;  /* Set previous addr for current     */
      last = current;            /* Remember for next iteration       */
    }
  }
  /* Now tell what we know */
  while(current) {            /* Output family in inverse order     */
    printf("\n%s was born %d/%d/%d, and has %s and %s as parents.", current->name,
	                                                            current->dob.day,
	                                                            current->dob.month,
	                                                            current->dob.year,
	                                                            current->father,
	                                                            current->mother);
    last = current;
    current = current->previous;
    free(last);
  }
  printf("\n");
  return 0;
}

/* Function to input data on Family Members */
struct Family *get_person() {
  struct Family *temp; /* Define temporary */

  /* Allocate memory for a structure */
  temp = (struct Family*)malloc(sizeof(struct Family));

  printf("\nEnter the name of the person: ");
  scanf("%s", temp->name);
  
  printf("\nEnter %s's date of birth (dd/mm/yyyy); ", temp->name);
  scanf("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);

  printf("\nWho is %s's father? ", temp->name);
  scanf("%s", temp->father);

  printf("\nWho is %s's mother? ", temp->name);
  scanf("%s", temp->mother);
  
  temp->next = temp->previous = NULL;
  
  return temp;
}
