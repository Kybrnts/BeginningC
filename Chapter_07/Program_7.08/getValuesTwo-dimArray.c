/* Program 7.8 Getting the values of a two-dimensional array */
#include <stdio.h>

int main(void) {
  char board[3][3] = {{'1', '2', '3'},
		      {'4', '5', '6'},
		      {'7', '8', '9'}};
  unsigned short i;

  /* List all elements in the array */
  for(i = 0; i < 9; i++)
    printf(" board : %c\n", *(*board + i));
  
  return 0;

  /*
   * As you can see, you use the expression *(*board + i) to get the value of an array element. The expression between
   * the parentheses, *board + i, produces the address of the element in the array that is at offset i. Dereferencing
   * this results in the value at this address. It's important that the brackets are included. Leaving them out would
   * give you the value pointed to by board.
   * What you actually want to do, and what your expression does, is to add the value of i to the address contained in
   * board, and then dereference this new address to obtain a value.
   */
}
