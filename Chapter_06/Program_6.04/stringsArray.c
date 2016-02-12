/* Program 6.4 Arrays of strings */
#include <stdio.h>

int main(void) {
  
  char str[][41] = {   /* Stores a pair of strings */
    "To be or not to be",
    ", That is the question"
  };
  /* 
   * The size of the first dimension could be omitted because the compiler will deduce it from the ammount of
   * initializers found between braces, in this case 2.
   * We must make sure that the last dimension is large enough to accomodate the longest string, including the \0.
   */
  
  int count[] = {0, 0}; /* Lenghts of the strings */
  int i;                /* Loop control variable */
  
  /* Find the lenght of the strings */
  for(i = 0; i < 2; i++)
    while(str[i][count[i]])
      count[i]++;

  /* Check if we have enough space for both both strings */
  if(sizeof str[0] < count[0] + count[1] + 1) {
    printf("\nYou can't put a quarter into a pint pot.");
  }else {
    
    /* Copy 2nd string to forst */
    count[1] = 0;
    while(str[0][count[0]++] = str[1][count[1]++]);
    
    /* Output the combined string */
    printf("\n%s\n", str[0]);
  }
  
  return 0;
}
