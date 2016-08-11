/* Exercise 3-2 */
/*
 * Write a program that prompts the user to enter the date as three integer values for the month, the day in the month,
 * and the year. The program should then output the  date in the form 31st December 2003 when the user enters 12 31
 * 2003, for example.
 */
#include <stdio.h>

int main(void) {
  unsigned  month = 0u,
    day = 0u,
    year = 0u;
  char sfx1 = 0,
    sfx2 = 0;

  /* Get Month, day and year numbers in that order */
  printf("Enter the date (mm dd yyyyy): ");
  scanf("%u %u %u", &month, &day, &year);

  /* Check input data                              */
  if(month < 1u || month > 12u) { /* Check month   */
    printf("Bad month number\n");
  }else if(day < 1u || day > 31u) { /* Check day   */
    printf("Bad day number\n");
  }else { /* Now input is considered valid         */
          /* No year check implemented             */
    /* Build day's suffix                          */
    if((day > 10u && day < 20u) || day % 10u == 0 || day % 10u > 3u) {
      sfx1 = 't';
      sfx2 = 'h';
    }else if(day % 10u > 2u) {
      sfx1 = 'r';
      sfx2 = 'd';
    }else if(day % 10u > 1u) {
      sfx1 = 'n';
      sfx2 = 'd';
    }else {
      sfx1 = 's';
      sfx2 = 't';
    }
    /* Display the date in the new format          */
    printf("You entered the date: %s %d%c%c %d\n",
	   month == 1u ?
	   "Jannuary" : month == 2u ? 
	   "Februrary" : month == 3u ?
	   "March" : month == 4u ?
	   "April" : month == 5u ? 
	   "May" : month == 6u ?
	   "June" : month == 7u ?
	   "July" : month == 8u ?
	   "August" : month == 9u ?
	   "September" : month == 10u ?
	   "October" : month == 11u ?
	   "November" : "December",
	   day,
	   sfx1, sfx2,
	   year);    
  }
  return 0;
}
