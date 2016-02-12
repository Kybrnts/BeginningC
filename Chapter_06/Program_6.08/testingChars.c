/* Program 6.8 Testing characters in a string */
#include <stdio.h>
#include <ctype.h> /* For character test functions */

int main(void) {
  
  char buffer[80];    /* Input buffer */
  int i = 0,          /* Buffer index */
    num_letters = 0,  /* Number of letters in input */
    num_digits = 0;   /* Number of digits in input */
  
  printf("\nEnter an interesting string of less than 80 characters: \n");
  /* Read a string into buffer */
  if(gets(buffer) == NULL) {
    printf("Error reading input.");
    return 1;         /* End the program */
  }
  /*
   * The string that you enter is read into the array buffer using a new standard library function, gets(). So far,
   * you've used only scanf() to accept input from the keyboard, but it's not very useful for reading strings because it
   * interprets a space as the end of an input value. The gets() function has the advantage that it will read all the
   * characters entered from the keyboard, including blanks, up to when you press the Enter key. This is then stored as
   * a string into the area specified by its argument, which in this case is the buffer array. A \0 will be appended to
   * the string automatically.
   *
   * As with any input or output operation, things can go wrong. If an error of some kind prevents the gets() function
   * from reading the input successfully, it will return NULL (normally, it returns the address passed as the argument
   * buffer, in this case).
   */
  
  while(buffer[i] != '\0') {
    if(isalpha(buffer[i]))
      num_letters++;  /* Increment the letter count */
    
    if(isdigit(buffer[i++]))
      num_digits++;   /* Increment the digit count */
  }
  printf("\nYour string contained %d letters and %d digits. \n",
	 num_letters, num_digits);
  
  return 0;
}
