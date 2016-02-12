/* Program 2.18 Calculating the height of a tree */
#include <stdio.h>

int main(void) {

  long shorty = 0L,       /* Shorty's height in inches */
    lofty = 0L,           /* Lofty's height in inches */
    feet = 0L,
    inches = 0L,
    shorty_to_lofty = 0L, /* Distance between shorty and lofty in inches */
    lofty_to_tree = 0L,    /* Distance between Lofty and tree in inches */
    tree_height = 0L;     /* Height of the tree in inches */
  
  const long inches_per_foot = 12L;

  /* Get Lofty's height */
  printf("Enter Lofty's height to the top of his/her head, in whole feet: ");
  scanf("%ld", &feet);
  printf("                                                 ...and inches: ");
  scanf("%ld", &inches);
  lofty = feet*inches_per_foot + inches;

  /* Get Shorty's height */
  printf("Enter Shorty's height up to his/her eyes, in whole feet: ");
  scanf("%ld", &feet);
  printf("                                          ...and inches: ");
  scanf("%ld", &inches);
  shorty = feet*inches_per_foot + inches;

  /* Get the distance from Shorty to Lofty */
  printf("Enter the distance between Shorty and Lofty, in whole feet: ");
  scanf("%ld", &feet);
  printf("                                             ...and inches: ");
  scanf("%ld", &inches);
  shorty_to_lofty = feet*inches_per_foot + inches;

  /* Get the distance from Lofty to the tree */
  printf("Finally enter the distance from the tree to the nearest foot: ");
  scanf("%ld", &feet);
  lofty_to_tree = feet*inches_per_foot;

  /* Calculate the height of the tree in inches */
  tree_height = shorty + (shorty_to_lofty + lofty_to_tree)*(lofty - shorty)/(shorty_to_lofty);

  /* Display the result in feet and inches */
  printf("The height of the tree is %d feet and %ld inches.\n",
	 tree_height/inches_per_foot, tree_height%inches_per_foot);
  
  return 0;
}
