/* Program 11.4A Daisy chaining horses */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
  
  struct Date {
    int year,
      month,
      day;
  };
  struct horse {
    int age,
      height;
    struct Date dob;
    char name[20],
      father[20],
      mother[20];
    struct horse *next;
  };
  
  struct horse *first = NULL,
    *previous = NULL,
    *current = NULL;
  char test = '\0';
  int vc;

  while(1) {
    printf("\nDo you want to enter details of a%s horse (Y or N)? ", first ? "nother" : "");
    scanf(" %c", &test);
    if(tolower((unsigned)test) == 'n')
      break;
    current = (struct horse *)malloc(sizeof(struct horse));
    if(!current) {
      printf("\nError!: Unable to allocate memory for this horse. Finishing..");
      return 1;
    }
    if(!first)
      first = current;
    if(previous)
      previous->next = current;
    printf("\nEnter the name of the horse: ");
    scanf("%s", current->name);
    printf("\nHow old is %s? ", current->name);
    scanf("%d", &current->age);
    printf("\nHow high is %s (in hands)? ", current->name);
    scanf("%d", &current->height);
    printf("\nEnter %s's date of birth (yyyy-mm-dd): ", current->name);
    vc = scanf("%4d%*1[-]%2d%*1[-]%2d", &current->dob.year,
	                                &current->dob.month,
	                                &current->dob.day);
    if(vc != 3) {
      printf("\nError! Invalid date entered. Using 0000-00-00 instead");
      current->dob.year = 0;
      current->dob.month = 0;
      current->dob.day = 0;
      while(getchar() != '\n');
    }
    printf("\nWho is %s's father? ", current->name);
    scanf("%s", current->father);
    printf("\nWho is %s's mother? ", current->name);
    scanf("%s", current->mother);
    current->next = NULL;
    previous = current;        
  }

  current = first;
  while(current) {
    printf("\n\n%s is %d years old, %d hands high,", current->name,
	                                             current->age,
	                                             current->height);
    printf( " born the %04d-%02d-%02d", current->dob.month,
	                                current->dob.day,
	                                current->dob.year);
    printf(" and has %s and %s as parents.", current->father,
	                                     current->mother);
    previous = current;
    current = current->next;
    free(previous);
  }
  printf("\n");
  return 0;
}

