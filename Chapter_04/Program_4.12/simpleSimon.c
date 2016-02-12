/* Program 4.12 Simple Simon */
#include <stdio.h>   /* For input and output */
#include <ctype.h>   /* For toupper() function */
#include <stdbool.h> /* For bool, true, false */
#include <stdlib.h>  /* For rand(), and srand() functions */
#include <time.h>    /* For time() function */

int main(void) {
  
  char another_game = 'Y'; /* Records if another game is to be played */
  bool correct = true;     /* True if correct sequence entered, false otherwise */
  int counter = 0;         /* Number of sequences to be entered successfully */
  int sequence_length = 0; /* Number of digits in a squence */
  time_t seed = 0;         /* Seed value for random number sequence */
  int number = 0;          /* Stores and input digit */
  int i;                   /* Inner loop control variable */
  time_t now = 0;          /* Stores current time - seed for random values */
  int time_taken = 0;      /* Time taken for game in seconds */
  

  /* Describe how the game is played */
  printf("\nTo play Simple Simon, ");
  printf("watch the screen for a sequence of digits.");
  printf("\nWatch carefully, as the digits are only displayed"
	 " for a second");
  printf("\nThe computer will remove them, and then promt you ");
  printf("to enter the same squence.");
  printf("\nWhen you do, you must put spaces between the digits. \n");
  printf("\nGood luck!\nPress Enter to play\n");
  scanf("%c", &another_game);

  /* One outer looop iteration is one game */
  do {
    correct = true;       /* By default indicates correct sequence entered */
    counter = 0;          /* Initialize count of number of successfull tries */
    sequence_length = 2;  /* Initial length of a digit sequence */
    time_taken = clock(); /* Record current time as start of game */
    
    /* Rest of the declarations for the program */
    
    /* Inner loop continues as long as squence are entered correctly */
    while(correct) {
      
      /* On every third successfull try, increase the sequence lenght */
      sequence_length += counter++%3 == 0;

      /* Set the seed to be the number of seconds since Jan 1, 1970 */
      seed = time(NULL);
      
      now = clock(); /* Record the start time for sequence */

      /* Generate a sequence of numbers and display the number */
      srand((unsigned int)seed);  /* Initialize the random sequence */
      for(i = 1; i <= sequence_length; i++)
	printf("%d ", rand()%10); /* Output a random digit */
      
      /* Wait one second */
      for( ; clock() - now < CLOCKS_PER_SEC; );
      
      /* Now ovewrite the digit sequence */
      printf("\r");    /* Go to beginning of the line */
      for(i = 1; i <= sequence_length; i++)
	printf("  ");  /* Output two spaces */

      if(counter == 1) /* Only output message for the first try */
	printf("\nNow you enter the sequence - don't forget"
	       " the spaces\n");
      else
	printf("\r"); /* Back to the beginning of the line */
      
      /* Prompt for the input sequence */
      
      /* Check the input sequence of digits against the original */
      srand((unsigned int)seed);     /* Restart the reandom sequence */
      
      for(i = 1; i <= sequence_length; i++) {
	scanf("%d", &number);       /* Read an input number */
	if(number != rand() % 10) { /* Compare against random digit */
	  correct = false;          /* Incorrect entry */
	  break;                    /* No need to check further */
	}
      }
      printf("%s\n", correct ? "Correct!" : "Wrong!");
    }
    
    /* Calculate the total time to play in seconds */
    time_taken = (clock() - time_taken)/CLOCKS_PER_SEC;

    /* Output the game score */
    printf("\n\n Your score is %d", --counter * 100 / time_taken);

    fflush(stdin);
    
    /* Check if a new game is required */
    printf("\nDo you want to play again (y/n)? ");
    scanf("%c", &another_game);

  } while(toupper(another_game) == 'Y');
  return 0;
}
