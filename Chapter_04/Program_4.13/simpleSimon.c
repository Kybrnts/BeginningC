/* Program 4.13 Simple Simon */
#include <stdio.h>    /* Provides input and output         */
#include <ctype.h>    /* Provides toupper()                */
#include <stdbool.h>  /* Provides bool, true and false     */
#include <stdlib.h>   /* Provides rand() and srand()       */
#include <time.h>     /* Provides time()                   */

#define DELAY_DFLT 1U /* Default display period in seconds */

int main(void) {
  char another_game = 'Y';           /* Records if another game is to be played           */
  const unsigned DELAY = DELAY_DFLT; /* Display period in seconds                         */
  bool correct = true;               /* True if correct sequence entered, false otherwise */
  unsigned tries = 0U,               /* Nunber of successfull entries for sequence length */
    digits = 0U,                     /* Number of digits in a sequence                    */
    number = 0U,                     /* Stores an input digit                             */
    i,                               /* Inner loop control variable                       */
    score = 0U,                      /* Game score                                        */
    total_digits = 0U,               /* Total of digits entered in a game                 */
    game_time = 0U;                  /* Game time in seconds                              */
  time_t seed = 0,                   /* Seed value for random Number sequence             */
    wait_start = 0;                  /* Stores current time                               */
  clock_t start_time = 0;            /* Game start time in clock ticks                    */
  
  /* Describe how the game is played %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  printf("To play Simple Simon, watch the screen for a sequence of digits.\n");
  printf("Watch carefully, as the digits are only displayed for %u second%s!\n",
	 DELAY, DELAY > 1 ? "s" : "");
  printf("The computer will remove them, and then prompt you to enter the same sequence.\n"
	 "When you do, you must put spaces between the digits.\n"
	 "\nGood luck!\nPress Enter to play.\n");
  scanf("%c", &another_game);
  do { /* Game loop - One outer loop iteration is a complete game */
    /* Initialize game %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    correct = true;       /* Indicates correct sequence entered    */
    /* We added an #include directive for the stdbool.h, so we can use "bool" as type name. That header also defines the
     * the symbols true and false, to match 1 and 0 respectively.
     */
    tries = 0;            /* Initialize count of successfull tries */
    digits = 2;           /* Initial length of digit sequence      */
    start_time = clock(); /* Record time at start of the game      */
    /* Inner loop to play the game - continues as long as sequences are entered correctly */
    while(correct) {
      /* The while loop continues as long as correct has the value true. We will set it to false when the player enters
       * enters a sequence incorrectly.
       */
      tries++;              /* A new attempt                  */
      wait_start = clock(); /* Record start time for sequence */
      /* Generate a sequence of digits and display them %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      srand(time(&seed));         /* Initialize the random sequence, by writing in seed current time's value */
      for(i = 1U; i <= digits; i++)
	printf("%d ", rand()%10); /* Output a single random digit                                            */
      fflush(stdout);             /* Send all to the screen now                                              */
      /* The stdout stream is buffered, so will only display what's in the buffer after it reaches a newline (or when
       * it's told to).
       */
      /* Wait DELAY seconds %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      while(clock() - wait_start < DELAY*CLOCKS_PER_SEC);
      /* Overwrite (erase) the digit sequence %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      printf("\r");   /* Go to beginning of the line                     */
      for(i = 1U; i <= digits; i++)
	printf("  ");  /* Output two spaces                               */
      if(tries == 1U)  /* If this is the first try, explain when to input */
	printf("\rNow you enter the sequence - don't forget the spaces\n");
      else
	printf("\r"); /* Back to the beginning of the line               */
      /* Check entered digits %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      srand(seed);                    /* Reinitialize the same random sequence                    */
      for(i = 1U; i <= digits; i++) { /* Read the input sequence and compare against the original */
	scanf("%u", &number);         /* Read a digit                                             */
	if(number != rand()%10) {     /* Comparte w/generated digit                               */
	  correct = false;            /* Incorrect entry                                          */
	  break;                      /* No need to check further                                 */
	}
      }
      /* Increase teh sequence lenght %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      if(correct && tries%3 == 0) /* On every third successful try */
	digits++;                 /* Increase the number of digits */
      /* Show results for this try %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      printf("%s\n", correct ? "Correct!" : "Wrong!");
    }
    /* Calculate and output the game score %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    score = 10U*(digits - (tries%3U == 1U));                /* Points for sequence length */
    /* On the first try for a sequence of a given length, tries will have a value of the form 3*n+1 because three tries
     * are necessary at each sequence length. Thus, the expression (tries % 3 == 1) will be 1 (true) when the player
     * fails at the first try for a sequence of a given length, so the effect in the statement is to reduce the digit’s
     * value by 1 when this is the case.
     */
    total_digits = digits*(tries%3U == 0U ? 3U : tries%3U); /* Get the digit count        */
    /* If the player fails on the last attempt of the set of three for a given length, tries will be a multiple of 3. 
     * In this case 3*digits is the number of digits entered. If tries is not a multiple of 3, then the digit count is
     * the value of digits multiplied by the remainder after dividing tries by 3.
     */
    if(digits > 2)
      total_digits += 3U*((digits - 1U)*(digits - 2U)/2U - 1U);
    game_time = (clock() - start_time)/CLOCKS_PER_SEC - tries*DELAY;
    printf("clock() - start_time: %ld\n", clock() - start_time);
    printf("CLOCKS_PER_SEC: %ld\n", CLOCKS_PER_SEC);
    printf("tries*DELAY: %u\n", tries*DELAY);
    printf("Game_time: %u\n", game_time);

    if(total_digits > game_time)
      score += 10U*(game_time - total_digits); /* Add points for speed */
    /* To work out the points scored for a faster time, we need to define a standard time for entry of a digit and find
     * out how long the game took. We allow 1 second as the standard time to enter a digit, and award a further 10 pts.
     * for each second less than the standard that the player needed to enter all the digits in a complete game.
     */
    printf("Game time was %u seconds. Your score is %u\n", game_time, score);
    /* Clear the input buffer %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    while(getchar() != '\n'); /* Get one char from STDIN until EOL is reached */
    /* In it is explicitly said in the standard that fflush should only apply to output streams, hence fflush(stdin)
     * shall be avoided.
     */
    /* Check if a new game is required %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    printf("Do you want to play again (y/n)? ");
    scanf("%c", &another_game); /* Dont forget the leading space for the previous EOL */
  }while(toupper(another_game) == 'Y');
  /* If y or Y is entered, the loop continues for another game. Otherwise, the program ends. By converting another_game
   * to uppercase, we avoid having to check for either y or Y.
   */
  return 0;
}
