/* Program 3.7 Confused recruiting policy */
#include <stdio.h>

int main(void) {
  int age = 0,             /* Age for the applicant */
    college = 0,           /* Code for college attended */
    subject = 0;           /* Code for subject studied */
  _Bool interview = 0;     /* True for accept, false for reject */

  /* Get data on the applicant */
  printf("\nWhat college? 1 for Hardvard, 2 for Yale, 3 for other: ");
  scanf("%d", &college);
  printf("\nWhat subject? 1 for Chemistry, 2 for econimics, 3 for other: ");
  scanf("%d", &subject);
  printf("\nHow old is the applicant?: ");
  scanf("%d", &age);

  /* Check out the applicant */
  /* 
   * In the previous version the variable interview was set to true if any of the
   * four conditions was true.
   * Now we combine them using the || operator, for a shorter version, in which no
   * if statement is required.
   */
  interview = (age > 25 && college != 2)
              || (college == 2 && subject == 1)
              || (college == 1 && subject == 2 && age <= 28)
              || (college == 2 && age > 25 && subject != 1);

  /* Output of the interview */
  if(interview)
    printf("\n\nGive 'em an interview");
  else
    printf("\n\nReject 'em");
    

  return 0;
}
