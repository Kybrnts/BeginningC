/* Program 8.6A The functional approach to string sorting, now returning pointers */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *str_in(void);
void str_sort(const char *[], int);
void swap(void **p1, void **p2);
void str_out(char *[], int);

#define BUFFER_LEN 256
#define  NUM_P 50

int main(void) {

    char *pS[NUM_P];
    int count = 0;

    printf("\nEnter succesive lines, pressing Enter at the end of"
	   " each line.\nJust press Enter to end.\n");

    for(count = 0; count < NUM_P; count++) /* Max of NUM_P strings      */
      if((pS[count] = str_in()) == NULL)   /* Stop input on NULL string */
	break;

    str_sort(pS, count);
    str_out(pS, count);
    return 0;    
}

char *str_in(void) {

  char buffer[BUFFER_LEN];        /* Space to store input string */
  char *pString = NULL;           /* Pointer to string           */
  
  if(gets(buffer) == NULL) {      /* NULL returned from gets()?  */
    printf("\nError reading string.\n");
    exit(1);                      /* Error on input so exit      */
  }
  
  if(buffer[0] == '\0')           /* Empty string read?          */
    return NULL;

  pString = (char *)malloc(strlen(buffer) + 1);
  
  if(pString == NULL) {           /* Check memory allocation      */
    printf("\nOut of memory.");
    exit(1);                      /* No memory allocated so exit  */
  }
  
  return strcpy(pString, buffer); /* Return pString               */
}

void str_sort(const char *p[], int n) {

  bool sorted = false;
  int i;
  
  while(!sorted) {
    sorted = true;
    for(i = 0; i < n - 1; i++)
      if(strcmp(p[i], p[i+1]) > 0) {
	sorted = false;
	swap(&p[i], &p[i + 1]);
      }
  }
}

void swap(void **p1, void **p2) {
  void *pt = *p1;
  
  *p1 = *p2;
  *p2 = pt;
}

void  str_out(char *p[], int n) {
  int i;
  
  printf("\nYour input sorted in order is:\n\n");
  for(i = 0; i < n; i++) {
    printf("%s\n", *p);
    free(*p);
    *p++ = NULL;
  }
  return;
}
/*
 * When you use an array name as an argument to a function, a copy of the address of the beginning of the array is
 * transferred to the function. As a result, you have the possibility of treating the value received as a pointer in the
 * fullest sense, incrementing or decrementing the address as you wish. Here you replaced the array notation with
 * pointer in the printf() and free() function calls. You wouldn't be able to do so with an array declared within the
 * function body, but because you have a copy of the original array address, it's possible here. You can treat the
 * parameter just like a regular pointer. Because the address you have at this point is a copy of the original in
 * main(), this doesn't interfere with the original array address pS in any way.
 * There's little to choose between this version of the function and the original. The former version, using array
 * notation, is probably just a little easier to follow. However, operations expressed in pointer notation often execute
 * faster than array notation.
 */
