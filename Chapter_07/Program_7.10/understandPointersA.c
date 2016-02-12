/* Program 7.10 Understanding pointers to your hat size - No need for pointers */
#include <stdio.h>
#include <stdbool.h>

int main(void) {

  char size[3][12] = { /* Hat sizes as characters */
                      {'6','6','6','6','7','7','7','7','7','7','7','7'},
                      {'1','5','3','7',' ','1','1','3','1','5','3','7'},
                      {'2','8','4','8',' ','8','4','8','2','8','4','8'}};

  int headsize[12] = { /* Values in 1/8 inches */
                      164, 166, 169, 172, 175, 178, 181, 184, 188, 191, 194, 197};

  float cranium = 0.0;
  int your_head = 0,
    i;
  bool hat_found = false,
    too_small = false;

  
  /* Get the circumference of the head */
  printf("\nEnter the circumference of your head above your eyebrows in inches as decimal values: ");
  scanf(" %f", &cranium);

  /* Convert the whole eights of a inch */
  your_head = (int)(8.0*cranium);

  /* Search for a hat size */
  for(i = 0; i < 12; i++) {
    /* Find headsize in headsize array */
    if(your_head > *(headsize + i))
      continue;
    
    /* If it is first element and the head size is more than 1/8 smaller, then the head is too small for a hat */
    if(!i && (your_head < *headsize - 1)) {
      printf("\nYou are a proverbial pinhead. No hat for you I'm afraid.\n");
      too_small = true;
      break;
    }

    /* If head size is more than 1/8 smaller than the current element in headsize array, take the next element down */
    /* as the head size                                                                                             */
    if(your_head < *(headsize + i) - 1)
      i--;

    printf("\nYour hat size is %c %c%c%c\n", *(*size + i),           /* First row size  */
	                                     *(*size + 12 + i),      /* Second row size */
	                                     (i == 4) ? ' ': '/',
	                                     *(*size + 24 + i));     /* Third row size  */
    hat_found = true;
    break;
  }
  
  if(!(hat_found || too_small))
    printf("\nYou, in technical parlance, are a fathead. No hat for you, I'm afraid.\n");
  
  return 0;
}
