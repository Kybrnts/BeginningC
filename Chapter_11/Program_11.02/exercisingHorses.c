/* Program 11.2 Exercising Horses */
#include <stdio.h>
#include <ctype.h>

int main(void) {
  
  struct horse {              /* Struct declaration            */
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
  };

  struct horse My_horses[50]; /* Struct array declaration      */
  int hcount, i;              /* Count of the number of horses */
  char test = '\0';           /* Test value for ending         */

  /* Get all horses members's values */
  for(hcount = 0; hcount < 50; hcount++) {
    printf("\nDo you want to enter details of a%s horse (Y or N)? ",
           hcount ? "nother " : "");
    scanf(" %c", &test);
    if(tolower((unsigned char)test) == 'n')
      break;
    
    printf("Enter the name of the horse: ");
    scanf("%s", My_horses[hcount].name);                  /* Name          */

    printf("How old is %s? ", My_horses[hcount].name);
    scanf("%d", &My_horses[hcount].age);                  /* Age           */

    printf("How high is %s ", My_horses[hcount].name);
    scanf("%d", &My_horses[hcount].height);               /* Height        */
  
    printf("Who is %s's father? ", My_horses[hcount].name);
    scanf("%s", My_horses[hcount].father);                /* Father's name */
  
    printf("Who is %s's Mother? ", My_horses[hcount].name);
    scanf("%s", My_horses[hcount].mother);                /* Mother's name */
  }

  /* Now tell them that what we know */
  for(i = 0; i < hcount; i++) {
    printf("\n\n%s is %d years old, %d hands high, and has %s and %s as parents.",
	   My_horses[i].name, My_horses[i].age, My_horses[i].height, My_horses[i].father, My_horses[i].mother);
  }
  printf("\n");
  return 0;
}
