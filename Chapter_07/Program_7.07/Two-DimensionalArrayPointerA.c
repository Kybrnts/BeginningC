/* Program 7.7A Two Dimensional arrays */
#include <stdio.h>

int main(void) {
  char board[3][3] = {{'1', '2', '3'},
		      {'4', '5', '6'},
		      {'7', '8', '9'}};

  printf("Value of board[0][0] : %c\n", board[0][0]);
  printf("Value of *board[0]   : %c\n", *board[0]);
  printf("Value of **board     : %c\n", **board);

  return 0;
}
/*
 * As you can see, if you use board as a means of obtaining the value of the first element, you need to use two
 * indirection operators to get it: **board. You were able to use just one * in the previous program because you were
 * dealing with a one-dimensional array. If you used only the one *, you would get the address of the first element of
 * the array of arrays, which is the address referenced by board[0].
 *
 * Some observations:
 * i.   Guiven the "Type var, *pvar" and "pvar = &var", "pvar" evals to the address of "var" and "*pvar == var" is true.
 * ii.  If var is a one-dimensional array, "var + i" evals to the address of its i-element, hence "*(var + i) == var[i]"
 *      is true.
 * iii. If var is a two-dimensional array, "var + i" evals to the address of its i-element which is an array, hence
 *      "*(var + i)[j] == var[i][j]" is true.
 * iv.  If var is a two-dimensional array, "var[i]"  evals to the address of its i-element which is an array, hence
 *      "*(var[i] + j) == var[i][j]"  is true.
 * v.   If var is a two-dimensional array, "*(var + i) + j" evals to the addres of its j element of it i array, hence
 *      "*(*(var + i) + j) == var[i][j]".
 */
