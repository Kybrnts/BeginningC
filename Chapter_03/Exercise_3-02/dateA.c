/* Exercise 3-2A, Improved version */
/* This version provides full input validation */
#include <stdio.h>
enum Month {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
enum Day{d1st=1, d2nd, d3rd, d4th, d5th, d6th, d7th, d8th, d9th, d10th,
         d11th, d12th, d13th, d14th, d15th, d16th, d17th, d18th, d19th, d20th,
         d21st, d22nd, d23rd, d24th, d25th, d26th, d27th, d28th, d29th, d30th,
	 d31st};
int main(void) {
  int day = 0,
    month = 0,
    year = 0,
    dateok = 1;
  char sfx1 = 0,
    sfx2 = 0;

  /* Get Month, day and year numbers in that order */
  printf("Enter the date (mm/dd/yyyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);
  /* Check input data                              */
  if(year < 0 || month < Jan || month > Dec || day < d1st || day > d31st) {
    dateok = 0;
  }else if(month == Feb) {
    /* Is this a leap year?                        */
    if(year%400 == 0 || (year%100 != 0 && year%4 == 0)){
      if(day > d29th) /* Up to 29 days allowed     */
	dateok =0;
    /* This is not a leap year                     */
    }else if(day > d28th)
      dateok = 0;    /* Up to 28 days allowed      */      
  }else if(month == Jan || month == Mar || month == May || month == Jul
	   || month == Aug || month == Oct || month == Dec)
    if(day > d30th)
      dateok = 0;
  /* Continue w/processing if possible             */
  if(!dateok)
    printf("Error! Bad input. Please try again.\n");
  else {
    /* Build day's suffix                          */
    if((day > d10th && day < d20th) || day % 10u == 0 || day % 10u > 3u) {
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
