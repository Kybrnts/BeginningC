/* Program 4.7A A more interesting Guessing Game */
#include <stdio.h>
#include <stdlib.h> /* For rand() and srand() */
#include <time.h>   /* For time() */

int main(void) {
  int chosen = 0,  /* Stores the lucky number */
    guess = 0,     /* Stores a guess */
    count = 5,     /* The maximum number of tries */ 
    limit = 20;    /* Upper limit for pseudo-random values */

  srand(time(NULL));          /* Use clock value as starting seed */
  chosen = 1 + rand()%limit;  /* Random int 1 to limit */

  printf("\nThis is a guessing game.");
  printf("\nI have chosen a number between 1 and %d"\
	 " which you must guess.\n", limit);

  for( ; count > 0 ; --count){
    printf("\nYou have %d tr%s left.", count, count == 1 ? "y" : "ies");
    printf("\nEnter a guess: ");
    scanf("%d", &guess);

    if(guess == chosen) {
      printf("\nYou guessed it!\n");
      return 0;
    }

    if(guess < 1 || guess > 20)
      printf("I said between 1 and 20.\n");
    else
      printf("Sorry. %d is wrong.\n", guess);
  }
  printf("\nYou have entered %d tries and failed. The number was %d\n", count, chosen);
  return 0;
}
