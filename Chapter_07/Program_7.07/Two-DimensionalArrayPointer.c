/* Program 7.7 Two Dimensional arrays and pointers */
#include <stdio.h>

int main(void) {
  char board[3][3] = {{'1', '2', '3'},
		      {'4', '5', '6'},
		      {'7', '8', '9'}};


  printf("Value of board          : %p\n", board);
  printf("Address of board[0][0]  : %p\n", &board[0][0]);
  printf("But what is in board[0] : %p\n", board[0]);
 
  return 0;
}

/*
 * As you can see, all three output values are the same, so what can you deduce from this? The answer is quite simple.
 * When you declare a one-dimensional array, placing [n] after the array name tells the compiler that it's an array
 * with n elements. When you declare a two-dimensional array by placing [m] for the second dimension after the [n] for
 * the first dimension, the compiler creates an array of size n, in which each element is an array of size m. As learned
 * in Chapter 5, when you declare a two-dimensional array, you're creating an array of subarrays. So when you access
 * this two-dimensional array using the array name with a single index value, board[0] for example, you're actually
 * referencing the address of one of the subarrays. Using the two-dimensional array name by itself references the
 * address of the beginning of the whole array of subarrays, which is also the address of the beginning of the first
 * subarray.
 *
 * Some observations: 
 * i.   Guiven the "Type var" statement, "&var" evals to the address of the first byte of that variable.
 * ii.  If "var" is an array, "var" evals to the address of the first byte of its first element (i.e. &var[0]).
 * iii. If "var" is an array, also "&var" evals to "&var[0]" (i.e. "var == &var" evals to true).
 * iv.  If "var" is a two-dimensional array "var[0]" is an array as well, then "var[0] == &var[0][0]" is true. Then
 *      because of iii, "&var[0][0] == &var[0]" is true, then because of ii, "&var[0][0] == var" is also true. 
 */
