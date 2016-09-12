/* Program 5.6 Know your hat size - if you dare... */
#include <stdio.h>
#include <stdbool.h>

int main() {
  /********************************************************************************************************************
   * The size array stores hat sizes from 6 1/2 to 7 7/8. Each row defines one character of a size value so a size is *
   * selected by using the same index for each the three rows. e.g. Index 2 selects 6 3/4.                            *
   ********************************************************************************************************************/
  char size[][12] = {
    {'6', '6', '6', '7', '7', '7', '7', '7', '7', '7', '7', '7'},
    {'1', '5', '3', '7', ' ', '1', '1', '3', '1', '5', '3', '7'},
    {'2', '8', '4', '8', ' ', '8', '4', '8', '2', '8', '4', '8'}
  };
  /* Values in 1/8 inches */
  int headsize[] = {164, 166, 169, 172, 175, 178, 181, 184, 188, 191, 194, 197};
  float cranium = 0.0f;    /* Head circumference in decimal inches */
  int your_head = 0;       /* Head size in whole eighths           */
  size_t i = 0;            /* Loop control variable (counter)      */
  bool hat_found = false;  /* Indicates when a hat is found to fit */

  /* Get the circumference of the head */
  printf("Enter the circumference of your head above your eyebrows in inches, as a decimal value: ");
  scanf("%f", &cranium);
  /* Convert to whole eighths          */
  your_head = 8.0f*cranium;
  /* Because cranium contains the circumference of a head in inches, multiplying by 8.0 results in the number of eighths
   * of an inch that that represents. Thus the value stored in your_head will then be in the same units as the values
   * stored in the array headsize. Note that you need the cast to type int here to avoid a warning message from the
   * compiler. The code will still work if you omit the cast, but the compiler must then insert the cast to type int.
   * Because this cast potentially loses information, the compiler will issue a warning. The parentheses around the
   * expression (8.0*cranium) are also necessary; without them, you would only cast the value 8.0 to type int, not
   * the whole expression.
   */
  /********************************************************************************************************************
   * Search for a hat size                                                                                            *
   * Either your head corrsponds to the 1st headsize element or a fit is when your_head is greatar than one headsize  *
   * element and less than or equal to the next. In this case the size is the second headsize value.                  * 
   ********************************************************************************************************************/
  if(your_head == headsize[i])
    hat_found = true;
  else {
    for(i = 1; i < sizeof(headsize)/sizeof(headsize[0]); i++)
      /* Using sizeof() so that if we increase that array, this still works */
      if(your_head > headsize[i - 1] && your_head <= headsize[i]) {
	hat_found = true;
	break;
      }
    /* The process is a simple one and is carried out in this for loop. The loop index i runs from the second element in
     * the array to the last element. This is because we use i-1 to index the array in the if expression. On each loop
     * iteration, we compare our head size with a pair of successive values stored in the headsize array to find the
     * element value that's greater than or equal to our input size with the preceding value less than our input size.
     * The index found will correspond to the hat size that fits.
     */
  }
  if(hat_found)
    printf("Your hat size is %c %c%c%c\n", size[0U][i], size[1U][i], size[1U][i] == ' ' ? ' ' : '/', size[2U][i]);
  /* The printf() here uses the conditional operator to decide when to print a blank and when to print a slash (/) for
   * the fractional output value. The fifth element of the headsize array corresponds to a hat size of exactly 7. We
   * don't want it to print 7 /; we just want 7. Therefore, we customize the printf() depending on whether the element
   * size[1U][i] contains ' '. In this way, we omit the slash for any size where the numerator of the fractional part is
   * a space, so this will still work even if we add new sizes to the array.
   */
  else {                         /* If no hat was found      */
    if(your_head < headsize[0U]) /* Check for too small      */
      printf("You are the proverbial pinhead. No hat for you I'm afraid.\n");    
    else                         /* It must be to large then */
      printf("You, in technical parlance, are a fathead. No hat for you, I'm afraid.\n");      
  }
  return 0;
  /* Remember, when we use this program, if we lie about the size of your head, your hat won't fit. The more
   * mathematically astute, and any hatters reading this book, will appreciate that the hat size is simply the diameter
   * of a notionally circular head. Therefore, if you have the circumference of your head in inches, you can produce
   * your hat size by dividing this value bi PI.
   */
}
