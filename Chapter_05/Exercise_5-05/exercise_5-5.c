/* Exercise 5-5 */
/* Write a program that will calculate the average grade for the students in each of an arbitrary number of classes. The
 * program should read in all the grades for students in all classes before calculating the averages. Output the student
 * grades for each class followed by the average for that class.
 * 
 */
#include <stdio.h>
#include <ctype.h>      /* Provides tolower()                                      */
#define MAXCLASSES 50U  /* Maximum for the arbitrary number of classes             */
#define MAXSTUDNTS 50U  /* Maximum for the arbitrary number of students in a class */

int main(void) {
  char answer;                                /* Stores the user answer                                    */
  int grades[MAXCLASSES][MAXSTUDNTS] = {{0}}; /* Stores grades of each s in a class                        */
  unsigned s, c,                              /* Current studant and class indexes                         */
    laststudents[MAXCLASSES] = {0},           /* Remembers what was the last s's grade entered for a class */
    lastclass;                                /* Remembers what was the last class entered                 */
  float average;                              /* Stores the average for each class                         */

  /* Main loop. Iterates over the rows (classes) of grades array */
  for(c = 0U; c < MAXCLASSES; c++) {
    /* Prompt user to enter next class grades */
    printf("Enter %s class grades (%u of %u), Y or N?: ", c ? "another" : "first", c + 1U, MAXCLASSES);
    /* Read user's answer into variable       */
    scanf(" %c", &answer);
    if(tolower(answer) != 'y') { /* If answer is not "y"..                         */
      if(!c)                     /* And this is the first class                    */
	return 0;                /* Then, nothing was entered, so finish execution */
      else                       /* Otherwise..                                    */
	break;                   /* Stop main loop only                            */
    }
    /* Prompt user to enter another sutdent for current class */
    for(s = 0U; s < MAXSTUDNTS; s++) {
      printf("Enter %s student's grade (%u of %u), Y or N?: ", s ? "another" : "first", s + 1U, MAXSTUDNTS);
      /* Read user's anwer into variable */
      scanf(" %c", &answer);
      if(tolower(answer) != 'y')  /* If answer is not "y"..              */
	break;                    /* Stop entering grades for this class */
      /*Prompt the user to enter current student's grade */
      printf("Grade for class #%u, student #%u> ", c + 1U, s + 1U);
      /* Read student's grade into current matrix element */ 
      scanf("%d", &grades[c][s]);
      laststudents[c] = s + 1U;   /* Update last entered student value   */
    }
    lastclass = c + 1U;           /* Update last entered class value     */
  }
  for(c = 0; c < lastclass; c++) {         /* For each class..                                                */    
    average = 0.0f;                        /* Reset average sum                                               */
    printf("--------------------------------------------------------------------------------------------\n"
	   "Class #%u summary:", c + 1);   /* Print the summary header                                        */
    for(s = 0; s < laststudents[c]; s++) { /* For each student in class..                                     */
      printf("%sStudent #%u grade: %3d",   /* Format string spec                                              */
	     s%4U == 0U ? "\n" : ", ",     /* Start a newline for the first student, and then after 4 of them */
	     s + 1,                        /* Show current student's number                                   */
	     grades[c][s]);                /* Show current student's grade                                    */
      average += grades[c][s];             /* Accumulate curernt student's grade in average sum               */
    }
    /* Print current class average if needed */
    printf("\nClass average: %.2lf\n\n", laststudents[c] ? average/laststudents[c] : 0.0f);
  }
  return 0;
}
