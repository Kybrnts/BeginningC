/* Program 5.8 Tic-Tac-Toe */
#include <stdio.h>

int main(void) {
  int player = 0,         /* Player number - 1 or 2                   */
    winner = 0,           /* The winning player                       */
    choice = 0,           /* Square selection number for turn         */
    row = 0;              /* Row index for a square                   */
    unsigned column = 0U, /* Column index for a square                */
      line = 0U,          /* Row or column index in the checking loop */
      i;                  /* Main loop control variable               */
  char board[3][3] = {    /* The board                                */
    {'1', '2', '3'},      /* Initial values are reference numbers     */
    {'4', '5', '6'},      /* used to select a vacant square for       */
    {'7', '8', '9'},      /* a turn.                                  */
  };

  /* The main game loop. The game continues for up to 9 turns   */
  /* As long as there is no winner                              */
  for(i = 0U; i < 9U && !winner; i++) {
    /* Display the board                                        */
    printf("\n"
	   "+---+---+---+\n"
	   "| %c | %c | %c |\n"
	   "+---+---+---+\n"
	   "| %c | %c | %c |\n"
	   "+---+---+---+\n" 
	   "| %c | %c | %c |\n"
	   "+---+---+---+\n",
	   board[0][0], board[0][1], board[0][2],
	   board[1][0], board[1][1], board[1][2],
	   board[2][0], board[2][1], board[2][2]);
    /* Select the player                                        */
    player = i%2 + 1;     
    /* Get valid player square selection                        */
    do{
      printf("Player %d, please enter a valid square number where you want to place your %c: ",
	     player,
	     player == 1 ? 'X': 'O');
      scanf("%d", &choice);
      /* Calculate position based on choice value               */
      row = --choice/3;   /* Get the row index of square */
      column = choice%3;  /* Get column index of square  */
      /* If we subtract 1 from the player’s chosen square number in choice, the square numbers are effectively 0 to 8.
       * Then the expression choice/3 gives the row number, and expression choice%3 will give the column number.
       */
    } while(choice < 0 || choice > 8 || board[row][column] > '9');
    /* This condition verifies that the square selected is valid. There are three ways an invalid choice could be made:
     * * The square number is less than the minimum, 0;
     * * The square number is greater than the maximum, 8;
     * * The square number selects a square that already contains 'X' or 'O'
     * In the later case, the contents of the square will have a value greater than the char '9', because the char code
     * for 'X' and '0' are greater than that of '9'. If the choice fails on any of these conditions, we repeat the req.
     */
    /* Insert player symbol                                     */
    board[row][column] = player == 1 ? 'X' : 'O';    
    /* Code to check for a winning line - diagonals first       */
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2])
       || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
      winner = player;
    /* To check for a winning line, we compare one element in a line with the other two to test for equality. If all
     * 3 are identical, then we have a winning line. We check both diagonals in the board array with the if expression,
     * and if either diagonal has identical symbols in all three elements, we set winner to the current player. This
     * player must be the winner because he or she was the last to place a symbol on a square.
     */
    else
      /* Check rows and columns for a winning line              */
      for(line = 0U; line <= 2U; line++)
	if((board[line][0] == board[line][1] && board[line][0] == board[line][2])
	   || (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
	  winner = player;
    /* If neither diagonal has identical symbols, we check the rows and the columns in the else clause using a for loop.
     * The for loop body consists of one if statement that checks both a row and a column for identical elements on each
     * iteration. If either is found, winner is set to the current player.
     * If winner is set to a value here, the main loop condition will be false, so the loop ends and execution continues
     * with the code following the main loop.
     */
  }
  /* Game is over, so display the final board                   */
    printf("\n"
	   "+---+---+---+\n"
	   "| %c | %c | %c |\n"
	   "+---+---+---+\n"
	   "| %c | %c | %c |\n"
	   "+---+---+---+\n" 
	   "| %c | %c | %c |\n"
	   "+---+---+---+\n",
	   board[0][0], board[0][1], board[0][2],
	   board[1][0], board[1][1], board[1][2],
	   board[2][0], board[2][1], board[2][2]);
  /* Display the result message                                 */
  if(winner == 0)
    printf("How boring, it is a draw.\n");
  else
    printf("Congrats player %d, YOU ARE A WINNER!\n", winner);
  return 0;
}
