/* Exercise 4-5 */
/* Modify the Simon Says game implemented in Program 4.7A so that the program will continue with an option to play
 * another game when the player fails to guess the number correctly and will allow as many games as the player requires.
 */
#include <stdio.h>
#include <stdlib.h> /* Provides rand() and srand() */
#include <time.h>   /* Provides time()             */
#include <ctype.h>  /* Provides tolower()          */

#define MAXTRIES_DFLT 3U /* Max guess tries defalut         */
#define LIMIT_DFLT 20U   /* Default limit for random values */

int main(void) {

  unsigned choosen = 0U,             /* Stores the lucky number              */
    count;                           /* Tries counter                        */
  long guess = 0U;                   /* Stores a guess                       */
  const unsigned LIMIT = LIMIT_DFLT, /* Upper limit for pseudo-random values */
    MAXTRIES = MAXTRIES_DFLT;        /* Maximum number of tries              */
  char answr = 'n';                  /* Stores the "play again" user answer  */

  srand(time(NULL));             /* Use clock value as starting seed. Use same seed for all games */
  printf("This is a guessing game.\n");
  do {                           /* Main loop. Each iteration is a complete game                  */
    choosen = 1U + rand()%LIMIT; /* Random int 1 to limit                                         */
    printf("I have choosen a number between 1 and %u which you must guess.\n", LIMIT);
    for(count = MAXTRIES; count > 0U ; --count){
      printf("You have %u tr%s left.\n", count, count == 1 ? "y" : "ies");
      printf("Enter a guess: ");
      scanf("%ld", &guess);
      if(choosen > 0 && guess == (unsigned)choosen) {
	printf("You guessed it!\n");
	break;                  /* Do not exit the program as before, just the inner loop         */
      }else if(guess < 1 || guess > LIMIT)
	printf("I said between 1 and %u.\n", LIMIT);
      else
	printf("Sorry. %ld is wrong. My number is %s than that.\n", guess, choosen > guess ? "greater" : "less");
    }
    if(count == 0U)            /* If we reached the maximum tries, then we must've failed         */
      printf("You have entered %u tries and failed. The number was %d\n", MAXTRIES, choosen);
                               /* Prompt the user to play again                                   */
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &answr);      /* Read any whitespaces and a character                            */
  }while(tolower(answr) == 'y');
  return 0;
}
