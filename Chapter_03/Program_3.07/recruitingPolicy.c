/* Program 3.7 Confused recruiting policy */
#include <stdio.h>

int main(void) {
  int age = 0,   /* Age for the applicant      */
    college = 0, /* Code for college attended  */
    subject = 0, /* Code for subject studied   */
  interview = 0; /* 1 for accept, 0 for reject */

  /* Get data on the applicant */
  printf("What college? 1 for Hardvard, 2 for Yale, 3 for other: ");
  scanf("%d", &college);
  printf("What subject? 1 for Chemistry, 2 for econimics, 3 for other: ");
  scanf("%d", &subject);
  printf("How old is the applicant?: ");
  scanf("%d", &age);

  /* Check out the applicant */
  /* Graduates over 25 who studied chemistry and didn't graduate from Yale */
  if((age > 25 && subject == 1) && (college == 3 || college == 1)) 
    interview = 1;
  /* Graduates from Yale who studied chemistry */
  if(college == 2 && subject == 1)
    interview = 1;
  /* Graduates from Hardvard who studied econimics and are not older than 28 */
  if(college == 1 && subject == 2 && !(age > 28))
    interview = 1;
  /* Graduates from Yale who are over 25 who didn't study chemistry */
  if(college == 2 && (subject == 2 || subject == 3) && age > 25)
    interview = 1;

  /* Output of the interview */
  if(interview)
    printf("Give 'em an interview\n");
  else
    printf("Reject 'em\n");
    
  return 0;
}
