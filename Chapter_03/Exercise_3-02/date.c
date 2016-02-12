/* Exercise 3-2 */
/*
 * Write a program that prompts the user to enter the date as three integer values for
 * the month, the day in the month, and the year. The program should then output the 
 * date in the form 31st December 2003 when the user enters 12 31 2003, for example.
 */
#include <stdio.h>

int main(void) {

  unsigned short month = 0,
    day = 0,
    year = 0;
  char sfx1 = 0,
    sfx2 = 0;
  _Bool goahead = 1;

  /* Get Month, day and year numbers in that order */
  printf("\nEnter the number of month, day and year in that order: ");
  scanf("%hd %hd %hd", &month, &day, &year);

  /* Check input data */
  if(month < 1 || month > 12) {
    printf("\nBad month number");
    goahead = 0;
  }else if(day < 1 || day > 31) { /* Do not perform unnecessary checks */
    printf("\nBad day number");
    goahead = 0;
  }
  /* The previous check won't validate the input date, for instance */
  
  if(goahead) {
    /* Build day's suffix */
    if((day > 10 && day < 20) || day % 10 == 0 || day % 10 > 3) {
      sfx1 = 't';
      sfx2 = 'h';
    }else if(day % 10 > 2) {
      sfx1 = 'r';
      sfx2 = 'd';
    }else if(day % 10 > 1) {
      sfx1 = 'n';
      sfx2 = 'd';
    }else {
      sfx1 = 's';
      sfx2 = 't';
    }

    /* Display the date in the new format */
    printf("\nYou enter the date: %s %d%c%c %d",
	   month == 1 ?
	   "Jannuary" : month == 2 ? 
	   "Februrary" : month == 3 ?
	   "March" : month == 4 ?
	   "April" : month == 5 ? 
	   "May" : month == 6 ?
	   "June" : month == 7 ?
	   "July" : month == 8 ?
	   "August" : month == 9 ?
	   "September" : month == 10 ?
	   "October" : month == 11 ?
	   "November" : "December",
	   day,
	   sfx1, sfx2,
	   year);
  }

  return 0;
}
