/* Program 6.3 Joining strings */
int main(void) {
  char str1[41] = "To be or not to be",
    str2[] = ", that is the question";
  int count1 = 0,
    count2 = 0;

  /* Find the lenght of the first string */
  while(str1[count1]) /* Increment count till we reach the string terminating character */
    count1++;
  
  /* Find the lenght of the second string */
  while(str2[count2])
    count2++;

  /* Check if there is enough espace for both strings */
  if(sizeof str1 < count1 + count2 + 1)
    /* 
     * Notice how you use the sizeof operator to get the total number of bytes in the array by just using the array name
     * as an argument. The value that results from the expression sizeof str1 is the number of characters that the array
     * will hold, because each character occupies 1 byte.
     */
    printf("\nYou can't put a quart into a pint pot.\n");
  else {
    /* Copy 2nd string to end of the first */
    count2 = 0;
    while(str2[count2])
      str1[count1++] = str2[count2++];
    
    /* Make sure to add terminator */
    str1[count1] = '\0';

    /* Output the combined string */
    printf("\n%s\n", str1);
  }  
  return 0;
}
