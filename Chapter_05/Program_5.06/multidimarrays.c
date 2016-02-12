/* Program 5.6 Know your hat size - if you dare... */
#include <stdio.h>
#include <stdbool.h>

int main(void) {
  
  /* The size array stores hat sizes from 6 1/2 to 7 7/8 */
  /* Each row defines one character of a size value so   */
  /* a size is selected by using the same index for each */
  /* the three rows. e.g. Index 2 selects 6 3/4          */

  char size[3][12] = {
    {'6', '6', '6', '7', '7', '7', '7', '7', '7', '7', '7', '7'},
    {'1', '5', '3', '7', ' ', '1', '1', '3', '1', '5', '3', '7'},
    {'2', '8', '4', '8', ' ', '8', '4', '8', '2', '8', '4', '8'}
  };

  /* Values in 1/8 inches */
  int headsize[12] = {164, 166, 169, 172, 175, 178, 181, 184, 188, 191, 194, 197};

  float cranium = 0.0f;    /* Head circumference in decimal inches */
  int your_head = 0;       /* Head size in whole eighths           */
  int i = 0;               /* Loop counter                         */
  bool hat_found = false;  /* Indicates when a hat is found to fit */

  /* Get the circumference of the head */
  printf("\nEnter the circumference of your head above your eyebrows "
	 "in inches, as a decimal value: ");
  scanf(" %f", &cranium);

  /* Convert to whole eighths */
  your_head = (int)(8.0*cranium);
  /*
   * Because cranium contains the circumference of a head in inches, multiplying by 8.0 results in the number of eighths
   * of an inch that that represents. Thus the value stored in your_head will then be in the same units as the values
   * stored in the array headsize. Note that you need the cast to type int here to avoid a warning message from the
   * compiler. The code will still work if you omit the cast, but the compiler must then insert the cast to type int.
   * Because this cast potentially loses information, the compiler will issue a warning. The parentheses around the
   * expression (8.0*cranium) are also necessary; without them, you would only cast the value 8.0 to type int, not
   * the whole expression.
   */

  /* Search for the hat size */
  /* A fit is when your_head is greater than one headsize element */
  /* and less or equal than the next. The size is the second      */
  /* headsize value.                                              */
  for(i = 1; i < 12; i++)
    if(your_head > headsize[i - 1] && your_head <= headsize[i]) {
      hat_found = true;
      break;
    }
  /*
   * The process is a simple one and is carried out in this for loop. The loop index i runs from the second element in
   * the array to the last element. This is because you use i-1 to index the array in the if expression. On each loop
   * iteration, you compare your head size with a pair of successive values stored in the headsize array to find the
   * element value that is greater than or equal to your input size with the preceding value less than your input size.
   * The index found will correspond to the hat size that fits.
   */
  
  /* Check for minsize fit */
  if(your_head == headsize[0]) {
    i = 0;
    hat_found = true;
  }
  /*
   * If your input size corresponds exactly to the size corresponding to the first element in the array, this size will
   * fit but will not be discovered within the loop. You therefore check for this situation with last if statement.
   *
   * Now we found the value of "i" for which size[0][i] size[1][i] / size[2][i] = headsize[i].
   */

  if(hat_found)
    printf("\nYour hat size is %c %c%c%c\n",
	   size[0][i], size[1][i], (size[1][i] == ' ') ? ' ' : '/', size[2][i]);
  /*
   * The printf() here uses the conditional operator to decide when to print a blank and when to print a slash (/) for
   * the fractional output value. The fifth element of the headsize array corresponds to a hat size of exactly 7. You
   * don't want it to print 7 /; you just want 7. Therefore, you customize the printf() depending on whether the element
   * size[1][i] contains ' '. In this way, you omit the slash for any size where the numerator of the fractional part is
   * a space, so this will still work even if you add new sizes to the array.
   */

  else {
    /* Check for too small */
    if(your_head < headsize[0])
      printf("\nYou are the proverbial pinhead. No hat for"
	     " you I'm afraid.\n");
    /* It must be to large then */
    else
      printf("\nYou, in technical parlance, are a fathead."
	     " No hat for you, I'm afraid.\n");
      
  }
  return 0;
  /*
   * Remember, when you use this program, if you lie about the size of your head, your hat won't fit. The more
   * mathematically astute, and any hatters reading this book, will appreciate that the hat size is simply the diameter
   * of a notionally circular head. Therefore, if you have the circumference of your head in inches, you can produce
   * your hat size by dividing this value bi PI.
   */
}
