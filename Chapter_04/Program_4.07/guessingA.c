/* Program 4.7A A more interesting Guessing Game */
/* The previous example would have been much more entertaining if the number to be guessed could have been generated
 * within the program so that it was different each time the program executed. Well, you can do that using the rand()
 * function that’s declared in the stdlib.h header.
 */
#include <stdio.h>
#include <stdlib.h> /* Provides rand() and srand() */
#include <time.h>   /* Provides time()             */
#define MAXTRIES 5

int main(void) {
  int choosen = 0, /* Stores the lucky number              */
    guess = 0,     /* Stores a guess                       */
    count,         /* The maximum number of tries          */ 
    limit = 20;    /* Upper limit for pseudo-random values */

  srand(time(NULL));          /* Use clock value as starting seed */
  /* The sequence of numbers that’s generated by rand() uses a starting seed number, and for a given seed the sequence
   * will always be the same. If we use the function with the default seed value, we’ll always get the same sequence,
   * which won’t make the game very challenging but is useful when we are testing a program. However, stdlib.h provides
   * another standard function: srand(), which we can call to initialize the sequence with a particular seed that we
   * pass as an argument to the function. However we still need to generate a different seed for each execution.
   * The time() function that’s declared in the time.h header file, returns the number of seconds that have elapsed
   * since January 1, 1970, as an integer, and because time always marches on, we get a different value returned by
   * time() each time the program executes. Time() requires an argument to be specified, which we’ll specify here as
   * NULL. NULL is a symbol that’s defined in stdlib.h that represents a memory address that doesn’t refer to anything.
   */
  choosen = 1 + rand()%limit; /* Random int 1 to limit            */
  /* Each time we call rand(), it will return a random integer. The value will be from zero to a maximum of RAND_MAX,
   * the value of which is defined in stdlib.h. The integers generated by rand() are described as pseudo-random numbers
   * because truly random numbers can arise only in natural processes and can’t be generated algorithmically.
   */
  printf("This is a guessing game.\n");
  printf("I have choosen a number between 1 and 20 which you must guess.\n");
  for(count = MAXTRIES; count > 0 ; --count){
    printf("You have %d tr%s left.\n", count, count == 1 ? "y" : "ies");
    printf("Enter a guess: ");
    scanf("%d", &guess);
    if(guess == choosen) {
      printf("You guessed it!\n");
      return 0;
    }else if(guess < 1 || guess > 20)
      printf("I said between 1 and 20.\n");
    else
      printf("Sorry. %d is wrong. My number is %s than that.\n", guess, choosen > guess ? "greater" : "less");
  }
  printf("You have entered %d tries and failed. The number was %d\n", MAXTRIES, choosen);
  return 0;
}
