/* Exercise 6.03 */
/*
 * Write a program that will output a randomly chosen thought for the day from a set of at least five thoughts of your
 * own choosing. 
 */
#include <stdio.h>
#include <wchar.h>  /* For wide character usage */
#include <stdlib.h> /* For rand() and strand() */
#include <time.h>   /* For using time() */

#define THOUGHTLENGTH 150 /* Maximum length of the string containing the quote */

int main(void) {
  /* The list of quotes */
  wchar_t thoughtlist[][THOUGHTLENGTH] = {L"Remember: The first rule of the tautology club,\n"
                                          "          is the first rule of the tautology club.\n",
                                          L"There are 10 types of people in this world: those who understand bynary and\n"
                                          "those who don't.\n",
                                          L"\"If I have seen farther it is by standing on the shoulders of giants\"\n"
					  "Isaac Newton [1642 - 1727]\n",
                                          L"\"The more I think about language, the more it amazes me that people ever\n"
                                          "understand each other at all.\" Kurt Godel [1906 - 1978]\n",
                                          L"\"The eternal mystery of the world is its comprehensibility.\"\n"
                                          "Albert Einstein [1879 - 1955]\n"};

  /* Initialize the random sequence of numbers using the numbers of seconds since Jan 1, 1970 */
  srand((unsigned int)time(NULL));
  
  /* Output the random quote */
  printf("%S", thoughtlist[rand() % 5]);
  
  return 0;
}
