/* Program 6.8A Testing characters in a string, improved */
#include <stdio.h>
#include <ctype.h> /* For character test functions */

int main(void) {
  
  char buffer[80];    /* Input buffer */
  int i = 0,          /* Buffer index */
    num_letters = 0,  /* Number of letters in input */
    num_digits = 0;   /* Number of digits in input */
  
  printf("\nEnter an interesting string of less than 80 characters: \n");

  /* Read a string into buffer */
  if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
    printf("Error reading input.");
    return 1;         /* End the program */
  }
  /*
   * A disadvantage of the gets() function is that it will read a string of any length and attempt to store it in
   * buffer. There is no check that buffer has sufficient space to store the string so there's an opportunity to crash
   * the program. To avoid this you could use the fgets() function, which allows you to specify the maximum length of
   * the input string. This is a function that is used for any kind of input stream, as opposed to gets() which only
   * reads from the standard input stream stdin; so you also have to specify a third argument to fgets() indicating the
   * stream that is to be read.
   *
   * The fgets() function reads a maximum of one less than the number of characters specified by the second argument.
   * It then appends a \0 character to the end of the string in memory, so the second argument in this case is
   * sizeof(buffer). Note that there is another important difference between fgets() and gets(). For both functions,
   * reading a newline character ends the input process, but fgets() stores a '\n' character when a newline is entered,
   * whereas gets() does not. This means that if you are reading strings from the keyboard, strings read by fgets() will
   * be one character longer than strings read by gets(). It also means that just pressing the Enter key as the input
   * will result in an empty string "\0" with gets(), but will result in the string "\n\0" with fgets().
   */
  
  while(buffer[i] != '\0') {
    if(isalpha(buffer[i]))
      num_letters++;
    else if(isdigit(buffer[i]))
      num_digits++;
    i++;
  }

  printf("\nYour string contained %d letters and %d digits. \n",
	 num_letters, num_digits);
  
  return 0;
}
