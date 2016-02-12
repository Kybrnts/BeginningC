/* Program 9.9 REVERSI. An Othello type game */
#include <stdio.h>
#include <ctype.h>

#define SIZE 10      /* Board size. Must be even */
#define INPUTSIZE 10 /* Size of the input buffer */
#define COMP_C '@'   /* Computer's counter       */
#define PLAYER_C 'O' /* Player's counter         */

/* Function prototypes */
void display(char board[][SIZE]);
void getInput(char input[]);
void getAgain(char *again);
void getMove(int *x, char *y);
int validMoves(char player, char board[][SIZE], int moves[][SIZE]);
void makeMove(char player, int row, int col, char board[][SIZE]);
void computerMove(char player, int moves[][SIZE], char board[][SIZE]);
int bestMove(char player, int moves[][SIZE], char board[][SIZE]);
int getScore(char player, char board[][SIZE]);

int main(void) {

  char board[SIZE][SIZE], /* The board                                      */
    again,                /* Replay choice input                            */
    y;                    /* Column letter                                  */
  int moves[SIZE][SIZE],  /* Valid moves board                              */
    next_player = 0,      /* Player indicator: 1 for player, 0 for computer */
    row = 0,              /* Board row index                                */
    col = 0,              /* Board column index                             */
    no_of_games = 0,      /* Number of games                                */
    no_of_moves = 0,      /* Count of moves                                 */
    invalid_moves = 0,    /* Invalid move count                             */
    comp_score = 0,       /* Computer score                                 */
    user_score = 0,       /* Player score                                   */
    x = 0;                /* Row number                                     */
    
  /* Prompt the user of how to play */
  printf("\nREVERSI\n\n"
	 "You can go first on the game, then will take turns.\n");
  printf("\tYou'll be white - (%c)\n\tI'll be black - (%c).\n", PLAYER_C, COMP_C);
  printf("Select a square for your move by typing a digit for the row\n"
	 "and a letter from the column with no spaces between.\n");
  printf("\nGood luck! Press Enter to start.\n");
  getAgain(&again);

  /* The game's main loop */
  do {
    
    /* On even games, the player shall start, on odd ones the computer starts */
    next_player = ++no_of_games % 2;
    no_of_moves = 4; /* Always starts w/four counters */

    /* Blank all the board squares */
    for(row = 0; row < SIZE; row++)
      for(col = 0; col < SIZE; col++)
	board[row][col] = ' ';

    /* Place the initial four counters in the center */
    board[SIZE/2 - 1][SIZE/2 - 1] = board[SIZE/2][SIZE/2] = PLAYER_C;
    board[SIZE/2 - 1][SIZE/2] = board[SIZE/2][SIZE/2 - 1] = COMP_C;

    /* The game play loop */
    do {

      display(board); /* Display the board */

      if(next_player++ %2) {         /* Flip next player             */
	                             /* It is the player's turn      */
	if(validMoves(PLAYER_C, board, moves)) { 
 
	  /*Read player moves until a valid move is entered         */
	  for(;;) {
	    printf("\nPlease enter your move (row column): ");
	    getMove(&x, &y);          /* Read input                   */
	    y = tolower(y) - 'a';     /* Convert to column index      */
	    x--;                      /* Convert to row index         */
	    if(x >= 0 && y >= 0 && x < SIZE && moves[x][y]) {
	      makeMove(PLAYER_C, x, y, board);
	      no_of_moves++;          /* Increase the move count      */
	      break;
	    }else 
	      printf("Not a valid move, try again.\n");
	  }	  
	}else                         /* Not valid moves */
	  if(++invalid_moves < 2) {
	    printf("\nYou have to pass, press return");
	    getAgain(&again);
	  }else
	    printf("\nNeither of us can go, so the game is over.\n");
      }else {                         /* It is computer's turn                  */
	if(validMoves(COMP_C, board, moves)) {    /* Check for valid moves    */
	  invalid_moves = 0;                      /* Reset the invalid count  */
	  computerMove(COMP_C, moves, board);     /* Let the computer play    */
	  no_of_moves++;                          /* Increase the move count  */
	}else {
	  if(++invalid_moves < 2)
	    printf("\nI have to pass, you go\n"); /* Not valid move available */
	  else
	    printf("\nNeither of us can go, so the game is over.\n");
	}
      }      
    }while(no_of_moves < SIZE*SIZE && invalid_moves < 2);

    /* Now game is over */
    display(board); /* Show final board */

    /* Get final scores and display them */
    comp_score = user_score = 0;
    for(row = 0; row < SIZE; row++)
      for(col = 0; col < SIZE; col++) {
	comp_score += board[row][col] == COMP_C;
	user_score += board[row][col] == PLAYER_C;
      }
    printf("The final score is:\n");
    printf("Computer %d\nUser %d\n\n", comp_score, user_score);
    
    printf("Do you want to play again (y/n): ");
    getAgain(&again);            /* Get y or n       */

  }while(tolower(again) == 'y'); /* Go again on y    */
  
  printf("\nGoodbye\n");
  return 0;
}

/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
void getInput(char input[]) {
  int i;

  /* Continue reading untill getting a valid answer */
  while(1) {
    for(i = 0; i < INPUTSIZE; i++)            /* Read from input         */
      if((input[i] = getchar()) == '\n') {
	input[i++] = '\0';
	break;                               
      }
    if(i == INPUTSIZE && input[i - 1]) {      /* Input size exceeded?    */
      printf("Error! Input buffer size exceeded. Try again:");
      while(getchar() != '\n');               /* Flush stdin             */
      continue;
    }
    break;
  }  
}

/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
void getAgain(char *again) {
  
  char input[INPUTSIZE];
  getInput(input);   /* Read from input               */
  *again = input[0]; /* Keep only the first character */
}

/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
void getMove(int *x, char *y) {
  int i, j;
  char input[INPUTSIZE];

  /* Keep going till getting a valid input */
  while(1) {
    getInput(input);
    /* Remove spaces from input */
    for(i = 0, j = 0; input[j]; j++)
      if(!(input[j] == ' ' || input[j] == '\t'))
	input[i++] = input[j];
    /* First input must be a digit */
    if(!isdigit(input[0])) {
      printf("Error! Please enter row number and column letter: ");
      continue;
    }
    /* Second one must be a letter */
    if(!isalnum(input[1])) {
      printf("Error! Please enter row number and column letter: ");
      continue;
    }
    break;
  }
  *x = input[0] - '0';
  *y = input[1];
}

/**********************************************************************************************************************
 * Function    : display											      *
 * Inputs      : char board[][SIZE], The board array								      *
 * Outputs     : N/A												      *
 * Return      : Void												      *
 * Description : Displays the board in its current state with row numbers and column letters to identify squares.     *
 *               												      *
 **********************************************************************************************************************/
void display(char board[][SIZE]) {
  
  /* Display column labels                        */
  char col_label = 'a';                /* Column label         */
  int col, row;

  printf("\n");                        /* Start top line       */
  for(col = 0; col < SIZE; col++)
    printf("%4c", col_label + col);    /* Display the top line */
  printf("\n");                        /* End top line         */
  
  /* Display the rows...                          */
  for(row = 0; row < SIZE; row++) {

    /* Display the top line for the current row */
    printf("  +");
    for(col = 0; col < SIZE; col++)
      printf("---+");
    printf("\n%2d|", row + 1);
    
    /* Display the counters in current row      */
    for(col = 0; col < SIZE; col++)
      printf(" %c |", board[row][col]); /* Display counters in row */
    printf("\n");
  }
  
  /* Finally display the bottom line of the board */
  printf("  +");                   /* Start the bottom line  */
  for(col = 0; col < SIZE; col++)
    printf("---+");                /* Display the bottm line */
  printf("\n");                    /* End the bottom line    */
}

/**********************************************************************************************************************
 * Function    : validMoves											      *
 * Inputs      : > char player: The value of the constant that represent either the human player or the computer.     *
 *               > char board[][SIZE]: The board grid.								      *
 * Outputs     : int moves[][SIZE]: The board grid of current available valid moves.				      *
 * Return      : int: Valid move count.										      *
 * Description : Calculates which squares are valid moves for player. Valid moves are recorded in the moves array -   *
 *               true indicates a valid move, false indicates an invalid one.					      *
 *               												      *
 **********************************************************************************************************************/
int validMoves(char player, char board[][SIZE], int moves[][SIZE]) {

  int row,                                                   /* Current row                      */
    col,                                                     /* Current column                   */
    rowdelta,                                                /* Row increment around a square    */
    coldelta,                                                /* Column increment around a square */
    x = 0,                                                   /* Row index when searching         */
    y = 0,                                                   /* Column index when searching      */
    no_of_moves = 0;                                         /* Number of valid moves            */
  char opponent = (player = PLAYER_C) ? COMP_C : PLAYER_C;   /* Set the opponent                 */
  
  /* Initialize moves array to 0 */
  for(row = 0; row < SIZE; row++)
    for(col = 0; col < SIZE; col++)
      moves[row][col] = 0;
  
  /* Find squares for valid moves.                                                                                    */
  /* A valid move must be on a blank square and must enclose at least one opponent square between two player squares  */
  for(row = 0; row < SIZE; row++)
    for(col = 0; col < SIZE; col++) {

      /* Check all the squares around the blank square for the opponents counter                                      */
      for(rowdelta = -1; rowdelta <= 1; rowdelta++)
	for(coldelta = -1; coldelta <= 1; coldelta++) {
	  
	  /* Don't check outside the array, or the current square                                                     */
	  if(row + rowdelta < 0 || row + rowdelta >= SIZE || col + coldelta < 0 || (rowdelta == 0 && coldelta == 0))
	    continue;

	  /* Now check the square                                                                                     */
	  if(board[row + rowdelta][col + coldelta] == opponent) {
	    
	    /* If we find  the opponent, move in the delta direction over opponent counters searching for a player    */
	    /* counter                                                                                                */
	    x = row + rowdelta; /* Move to opponent square                                                            */
	    y = col + coldelta;

	    /* Look for a player square in the delta direction                                                        */
	    for(;;) {
	      x += rowdelta;    /* Go to next square in delta direction                                               */
	      y += coldelta;    

	      /* If you move  outside the array, give up                                                              */
	      if(x < 0 || x > SIZE || y < 0 || y > SIZE)
		break;
	      
	      /*If we find a blank square, give up                                                                    */
	      if(board[x][y] == ' ')
		break;
	      
	      /* If the square has a player counter then we have a valid move                                         */
	      if(board[x][y] == player) {
		moves[row][col] = 1; /* Mark as valid                                                              */
		no_of_moves++;          /* Increase valid moves count                                                 */
		break;                  /* Go check another square                                                    */
	      }	      	      
	    }	    
	  }
	}
    }
  return no_of_moves;
}

/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
void makeMove(char player, int row, int col, char board[][SIZE]) {

  int rowdelta,     /* Row increment           */
    coldelta,       /* Column increment        */
    x = 0,          /* Row index for searching */
    y = 0;          /* Col index for searching */

  /* Identify opponent */
  char opponent = (player == PLAYER_C) ? COMP_C : PLAYER_C;
  
  /* Place the player counter */
  board[row][col] = player;
  
  /* Check all the squares around this square for the opponents counter */
  for(rowdelta = -1; rowdelta <= 1; rowdelta++)
    for(coldelta = -1; coldelta <= 1; coldelta++) {

	/* Don't check off the board, or the current square */
	if(row + rowdelta < 0 || row + rowdelta >= SIZE || col + coldelta < 0 || col + coldelta >= SIZE ||
	   (rowdelta==0 && coldelta== 0))
	  continue;

	/* Now check the square */
	if(board[row + rowdelta][col + coldelta] == opponent) {
	    /* If we find the opponent, search in the same direction for a player counter */

	    x = row + rowdelta; /* Move to opponent square */
	    y = col + coldelta;

	    for(;;) {

		x += rowdelta; /* Move to the next square */
		y += coldelta;

		/* If we are off the board give up */
		if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		  break;

		/* If the square is blank give up */
		if(board[x][y] == ' ')
		  break;

		/* If we find the player counter, go backward from here changing all the opponents counters to player */
		if(board[x][y] == player) {
		    while(board[x -= rowdelta][y -= coldelta] == opponent) /* Opponent?      */
		      board[x][y] = player;                                /* Yes, change it */
		    break;                                                 /* We are done    */
		  }
	      }
	  }
      }
}

/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
int getScore(char player, char board[][SIZE]) {

  int row,                                                  /* Current row                */
    col,                                                    /* Current col                */
    score = 0;                                              /* Score for current position */
  char opponent = (player == PLAYER_C) ? COMP_C : PLAYER_C; /* Identify opponent          */
  
  /* Check all board squares */
  for(row = 0; row < SIZE; row++)
    for(col = 0; col < SIZE; col++) {
	score -= board[row][col] == opponent;              /* Decrement for opponent     */
	score += board[row][col] == player;                /* Increment for player       */
      }
  return score;
}


/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
int bestMove(char player, int moves[][SIZE], char board[][SIZE]) {

  int row,                    /* Current row index      */
    col,                      /* Current col index      */
    i,                        /* Loop  indexes          */
    j,
    score = 0,                /* Best score             */
    new_score = 0;            /* Score for current move */

  char new_board[SIZE][SIZE]; /* Local copy of board    */
  
  /* Check all valid moves to find the best */
  for(row = 0; row < SIZE; row++)
    for(col = 0; col < SIZE; col++)
      {
	if(!moves[row][col])             /* Not a valid move?      */
	  continue;                      /* Go to the next         */
 
	/* Copy the board */
	for(i = 0; i < SIZE; i++)
	  for(j = 0; j < SIZE; j++)
	    new_board[i][j] = board[i][j];

	/* Make move on the board copy */
	makeMove(player, row, col, new_board);

	/* Get score for move */
	new_score = getScore(player, new_board);

	if(score < new_score)            /* Is it better?               */
	  score = new_score;             /* Yes, save it as best score  */
      }
  return score;                          /* Return best score           */
}

/*********************************************************************************************************************
 * Function    : 
 * Inputs      : 
 * Outputs     : 
 * Return      : 
 * Description : 
 *               
 *********************************************************************************************************************/
void computerMove(char player, int moves[][SIZE], char board[][SIZE]) {

  int row,                                               /* Current row index                   */
    col,                                                 /* Current column index                */
    i,                                                   /* Loop indexes                        */
    j,
    best_row = 0,                                        /* Best row index (to be found)        */
    best_col = 0,                                        /* Best col index (to be found)        */
    new_score = 0,                                       /* Score for current move              */
    score = 100,                                         /* Opponent's score (starts w/minimum) */
    temp_moves[SIZE][SIZE];                              /* Local copy of the board             */
  char temp_board[SIZE][SIZE],                           /* Local valid moves list              */
    opponent = (player == PLAYER_C) ? COMP_C : PLAYER_C; /* Identify opponent                   */

  /* Go through all valid moves */
  for(row = 0; row < SIZE; row++)
    for(col = 0; col < SIZE; col++) {
	if(!moves[row][col])
	  continue;

	/* First make copies of the board array */
	for(i = 0; i < SIZE; i++)
	  for(j = 0; j < SIZE; j++)
	    temp_board[i][j] = board[i][j];

	/* Now make this move on the temporary board */
	makeMove(player, row, col, temp_board);

	/* find valid moves for the opponent after this move */
	validMoves(opponent, temp_board, temp_moves);

	/* Now find the score for the opponent's best move */
	new_score = bestMove(opponent, temp_moves, temp_board);
	if(new_score < score) { /* Is it worse?                     */
	                        /* Yes, so save this move           */
	  score = new_score;    /* Record new lowest opponent score */
	  best_row = row;       /* Record best move row             */
	  best_col = col;       /* and column                       */
	  }
      }
  /* Make the best move */
  makeMove(player, best_row, best_col, board);
}
