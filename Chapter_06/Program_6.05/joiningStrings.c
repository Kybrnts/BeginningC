/* Program 6.5 Joining Strings - revitalized */
#include <stdio.h>
#include <string.h>  /* For string functions */
#define STR_LENGHT 41

int main(void) {

  char str1[STR_LENGHT] = "To be or not to be",
    str2[STR_LENGHT] = ", that is the question";

  if(STR_LENGHT > strlen(str1) + strlen(str2))  /* Enough space ? */
    printf("\n%s\n", strcat(str1, str2));       /* Yes, so display joined string */
  else
    printf("\nYou can't put a quarter into a pint pot.");
  
  return 0;
}
