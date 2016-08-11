/* Program 3.8 Lucky Lotteries */
#include <stdio.h>

int main(void) {
  int choice = 0; /* The number chosen */

  /* Get the choice input */
  printf("Pick a number between 1 and 10 and yo umay win a prize! ");
  scanf("%d", &choice);
  
  /* Check for an invalid selection */
  if((choice > 10) || (choice < 1))
    choice = 11; /* Selects the invalid choice message */
  
  switch(choice) {
  case 7:
    printf("Congratulations!\n");
    printf("You win the collected works of Amos Gruntfuttock.\n");
    break; /* Jumps to the end of the block */
  case 2:
    printf("You win the folding thermometer-pen-watch-umbrella.\n");
    break; /* Jumps to the end of the block */    
  case 8:
    printf("You win the lifetime supply of aspirin tablets.\n");
    break; /* Jumps to the end of the block */
  case 11:
    printf("Try between 1 and 10. You wasted your guess.\n");
    /* No break - so continue to the next statement */        
  default:
    printf("Sorry, you loose.\n");
    break; /* Defensive break - in case of new cases - */    
  }    
  return 0;
}
