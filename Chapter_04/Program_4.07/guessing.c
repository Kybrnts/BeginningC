/* Program 4.7 A guessing game */
#include <stdio.h>

int main(void) {
  
  int choosen = 15, /* The lucky number */
    guess = 0,      /* Stores a guess */
    count = 3;      /* The maximum number of tries */

  printf("\nThis is a guessing game");
  printf("\nI have chosen a number between 1 and 20"
	 " which you must guess.\n");
  
  for( ; count > 0; --count) {
    /*
     * All the operational details of the game are within this loop, which will continue as long as count is positive,
     * so the loop will repeat count times.
     */
    
    printf("\nYou have %d tr%s left.", count, count == 1 ? "y" : "ies");
    /* This inserts a "y" after "tr" in the output when count is 1, and "ies" after "tr" in the output in all other
     * cases. You must, after all, get your plurals right.
     */

    printf("\nEnter a guess: "); /* Prompt for a guess */
    scanf("%d", &guess);         /* Read in a guess */
    
    /* Check for a correct guess */
    if(guess == choosen) {
      printf("\nYou guessed it!\n");
      return 0; /* End the program */
    }
    /*
     * If the guess is correct, you display a suitable message and execute the return statement. The return statement
     * ends the function main(), and so the program ends.
     */
    
    /* Check for invalid guess */
    if(guess < 1 || guess > 20)
      printf("I said between 1 and 20.\n");
    else
      printf("Sorry. %d is wrong.\n", guess);
    /*
     * This group of statements tests whether the value entered is within the prescribed limits. If it isn't, a message
     * is displayed reiterating the limits. If it's a valid guess, a message is displayed to the effect that it's
     * incorrect.
     */
  }
  printf("\nYou have entered three tries and failed. The number was %d\n", choosen);
  /*
   * This will be executed only if all three guesses were wrong. It displays an appropriate message, revealing the
   * number to be guessed, and then the program ends.
   * This program is designed so that you can easily change the value of the variable chosen and have endless fun.
   * Well, endless fun for a short while, anyway.
   */

  return 0;
}
