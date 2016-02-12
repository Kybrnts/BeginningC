/* Program 2.7 Division with float values */
#include <stdio.h>

int main() {
  float plank_lenght = 10.0f, /* In feet */
    piece_count = 4.0f,       /* Number of equal pieces */
    piece_lenght = 0.0f;      /* Lenght of a piece in feet */
  
  piece_lenght = plank_lenght/piece_count;
  printf("A plank %5.3f long can be cut into %5.3f pieces of %5.3f feet long.",
	 plank_lenght,
	 piece_count,
	 piece_lenght);

  return 0;
}
