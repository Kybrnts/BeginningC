/* Program 6.6 Comparing strings */
#include <stdio.h>
#include <string.h>

int main(void) {

  char word1[20], /* Stores the first word */
    word2[20];    /* Stores the second word */
  /*
   * You set the size of the arrays to 20. This should be enough for an example, but there's a risk that this may not be
   * sufficient. As with the strcpy() function, it's your responsibility to allocate enough space for what the user may
   * key in.
   */

  printf("\nType in the first word (less than 20 characters): \n1: ");
  scanf("%19s", word1); /* Read the first word */
  /*
   * The function scanf() will limit the number of characters read if you specify a width with the format specification.
   * Also ensures the array limit will not be exceeded, any characters in excess of the width you specify will be left
   * in the input stream and will be read by the next input operation for the stream.
   *
   * Notice how in this example you haven't used an & operator before the variables in the arguments to the scanf()
   * function. This is because the name of an array by itself is an address. It corresponds to the address of the first
   * element in the array; Therefore, &word1[0] is equal to word1!!!
   */

  printf("\nType in the second word (less than 20 characters): \n2: ");
  scanf("%19s", word2); /* Read the second word */
  
  /* Comparte the words */
  if(strcmp(word1, word2) == 0)
    printf("You have entered identical words");
  else
    printf("%s precedes %s",
	   strcmp(word1, word2) < 0 ? word1 : word2,
	   strcmp(word1, word2) < 0 ? word2 : word1);

  return 0;
}
