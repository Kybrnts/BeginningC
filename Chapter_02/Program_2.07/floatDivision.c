/* Program 2.7 Division with float values */
#include <stdio.h>

int main() {
  float plank_lenght = 10.0f, /* In feet */
    piece_count = 4.0f,       /* Number of equal pieces */
    piece_lenght = 0.0f;      /* Lenght of a piece in feet */
  
  piece_lenght = plank_lenght/piece_count;
  /* division with integer operands always produces an integer result. Unless the left operand of a division is an exact
   * multiple of the right operand when dividing one integer by another, the result will be inherently inaccurate.
   * Division with floating-point operands will give you an exact result. At least, a result that is as exact as it can
   * be with a fixed number of digits of precision.
   */
  printf("A plank %5.3f long can be cut into %5.3f pieces of %5.3f feet long.\n",
	 plank_lenght,
	 piece_count,
	 piece_lenght);

  return 0;
}
