/* Program 5.7 Averaging a variable number of grades         */
/* /!\ - This is not ISO C90 Complaint, but rather C99 - /!\ */
#include <stdio.h>

int main(void) {
#ifdef __STDC_NO_VLA__
  printf("Variable length arrays are not supported.\n");
  return 1;
#endif

  size_t nGrades = 0,                     /* Number of grades */
    i;
  printf("Enter the number of grades: "); 
  scanf("%lu", &nGrades);
  int grades[nGrades];                    /* Array sorting nGrades values */
  long sum = 0L;                          /* Sum of the numbers           */
  float average = 0.0f;                   /* Average of the numbers       */

  for(i = 0; i < nGrades; i++) {
    printf("%2lu> ", i + 1);
    scanf("%d", &grades[i]);              /* Read a grade                 */
    sum += grades[i];                     /* Add it to sum                */
  }
  printf("The grades you entered are:\n");
  for(i = 0; i < nGrades; i++) {
    printf("Grade[%2lu] = %-3d ", i + 1, grades[i]);
    if((i + 1) % 5 == 0)                 /* After 5 values                */
      printf("\n");                      /* Go to a new line              */
  }
  average = (float)sum/nGrades;
  printf("Average of the %lu grades entered is: %.2f\n", nGrades, average);
  return 0;
}
