/* Program 11.3 Exercising Structure within another */
#include <stdio.h>
#include <ctype.h>  /* Provides tolower() */
#include <stdlib.h> /* Provides  malloc() */

int main(void) {
  
  /* Structure (data type) declarations */
  struct Date {
    int day,
      month,
      year;
  };
  struct horse {             
    struct Date dob;
    int age,
      height;
    char name[20],
      father[20],
      mother[20];
  };
  
  struct horse *phorse[50]; /* Pointer to structure array declaration */
  int i,                    /* Index                                  */
    vc,                     /* Value count for scanf()                */
    hcount = 0;             /* Count of the number of horses          */
  char test = '\0';         /* Test value for ending input            */

    for(hcount = 0; hcount < 50; hcount++) {
      printf("\nDo you want to enter details of a%s horse (Y or N)? ", hcount ? "nother" : "");
      scanf(" %c", &test);
      if(tolower((unsigned)test) == 'n')
	break;

      /* Allocate memory to hold a structure */
      phorse[hcount] = (struct horse*)malloc(sizeof(struct horse));

      /* Get all allocated structure members values */
      printf("\nEnter the name of the horse: ");
      scanf("%s", phorse[hcount]->name);                                          /* Name              */

      printf("\nEnter %s's date of birth (yyyy-mm-dd): ", phorse[hcount]->name);
      vc = scanf("%4d%*1[-]%2d%*1[-]%2d", &phorse[hcount]->dob.year,              /* Date of birth     */
	                                  &phorse[hcount]->dob.month,
	                                  &phorse[hcount]->dob.day);
      if(vc != 3) {                                                               /* Check readed date */
	printf("\nError! Invalid date entered. Using 0000-00-00 instead");
	phorse[hcount]->dob.year = 0;
	phorse[hcount]->dob.month = 0;
	phorse[hcount]->dob.day = 0;
	while(getchar() != '\n');
      }

      printf("\nHow old is %s? ", phorse[hcount]->name);
      scanf("%d", &phorse[hcount]->age);                                          /* Age               */
    
      printf("\nHow high is %s (in hands)? ", phorse[hcount]->name);
      scanf("%d", &phorse[hcount]->height);                                       /* Height            */
    
      printf("\nWho is %s's father? ", phorse[hcount]->name);
      scanf("%s", phorse[hcount]->father);                                        /* Father's name     */

      printf("\nWho is %s's mother? ", phorse[hcount]->name);
      scanf("%s", phorse[hcount]->mother);                                        /* Mother's name     */
    }

    /* Now tell everything that we know */
    for(i = 0; i < hcount; i++) {
      printf("\n\n%s is %d years old, %d hands high,", phorse[i]->name,
	                                               phorse[i]->age,
	                                               phorse[i]->height);
      printf( " born the %04d-%02d-%02d", phorse[i]->dob.month,
	                                  phorse[i]->dob.day,
	                                  phorse[i]->dob.year);
      printf(" and has %s and %s as parents.", phorse[i]->father,
	                                       phorse[i]->mother);
      free(phorse[i]);
    }
    printf("\n");
    return 0;
}
