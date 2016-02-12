/* Program 11.9 Generating a bar chart */
#include <stdio.h>   /* Porvides input/output */
#include <stdlib.h>  /* Needed for malloc()   */
#include <stdbool.h> 

#define PAGE_HEIGHT 20
#define PAGE_WIDTH 40
/*
 * We'll need the maximum and minimum values for the bars and the vertical height of the chart, which will be determined
 * by the difference between the maximum and minimum values. You also need to calculate the width of a bar, given the
 * page width and the number of bars, and you must adjust the height to accommodate a horizontal axis and the title.
 */

typedef struct barTAG {
  double value;
  struct barTAG *pnextbar;
}bar;
/*
 * * Using typedef so that we do not have to keep using the word struct.
 * * The barTAG will define a bar simply by its value.
 * * The "pointer to next" structure will enable for storing bars in a linked list. This has the benefit of allawing
 *   dynamic memory allocation, reducing waste.
 * * We only need one pointer to the next bar because we only want to create them in sequence from the input values and
 *   append each new bar to the tail of the previous one. We'll then create the visual representation of the bar chart
 *   by stepping through the structures in the linked list.
 * * We need to use the "struct barTag" type here because at this point the compiler hasn't finished processing the
 *   typedef yet, so bar isn't defined. In other words, the barTAG structure is analyzed first by the compiler, after
 *   which the typedef can be expedited to define the meaning of bar.
 */
typedef unsigned int uint; /* Type definition */
/*
 * We've added a typedef to define uint as an alternative to unsigned int. This will shorten statements that declare
 * variables of type unsigned int
 */

/* Function prototypes */
int bar_chart(bar *pfirstbar, uint page_width, uint page_height, char *title);


int main(void) {
  /* Code for main */  

  return 0;
}

/* Definition for the bar-char function */
int bar_chart(bar *pfirstbar, uint page_width, uint page_height, char *title) {

  bar *plastbar = pfirstbar; /* Pointer to previous bar         */
  double max = 0.0,          /* Maximum bar value               */
    min = 0.0,               /* Minimum bar value               */
    vert_scale = 0.0,        /* Unit step in vertical direction */
    position = 0.0;          /* Current vertical position       */
  uint bar_count = 1,        /* Number of bars - at least 1     */
    barwidth = 0,            /* Width of a bar                  */
    space = 2,               /* Spaces between bars             */
    i = 0,                   /* Loop count                      */
    bars = 0;                /* Loop counter through bars       */
  char *column = NULL,       /* Pointer to bar column section   */
    *blank = NULL;           /* Blank string for bar+space      */
  bool axis = false;         /* Indicates axis drawn            */
  /*
   * The space variable stores the number of spaces separating one bar from the next, arbitrarily assigned to value 2
   * for this.
   */

  /* Find maximum and minimum of all bars */  

  /* Set max and min to first bar value */
  max = min = plastbar->value;
  
  while((plastbar = plastbar->pnextbar)) {
    bar_count++;
    max = (max < plastbar->value)? plastbar->value : max;
    min = (min > plastbar->value)? plastbar->value : min;
  }
  vert_scale = (max - min)/page_height; /* Calculate step length */

  /* Check bar width */
  if((barwidth = page_width/bar_count - space) < 1) {
    printf("\nPage width too narrow.\n");
    return -1;
  }
  
  /* Set up a string that will be used to build the columns */
  /* Get the memory */
  if(!(column = malloc(barwidth + space + 1))) {
    printf("\nFailed to allocate memory in barchart() - terminating program.\n");
    exit(1);
  }
  for(i = 0; i < space; i++)
    *(column + i) = ' ';    /* Blank the space between bars */
  for( ; i < space + barwidth; i++)
    *(column + i) = '#';    /* Enter the bar characters     */
  *(column + i) = '\0';     /* Add string terminator        */

  /* Set up a string that will be used as blank column */

  /* Get memory */
  if(!(blank = malloc(barwidth + space + 1))) {
    printf("\nFailed to allocate memory in barchart() - terminating program.\n");
    exit(1);
  }
  
  for(i = 0; i < space + barwidth; i++)
    *(blank + i) = ' '; /* Blank total width for bar + space */
  *(blank + i) = '\0';  /* Add string terminator             */
  /*
   * We draw the bar using '#' characters. When a bar is drawed, a string containing "space" number of spaces and
   * "barwidth" '#' characters. For this we allocate the memory dynamically using malloc(), so we must add an
   * "include" directive for the header file "stdlib.h". The string used to draw the bar is "coumn", and "blank" is a
   * string of the same length containing spaces. After the bar chart has been drawn and just before the exit(), we
   * need to release the memory occupied by "column" and "blank"
   * 
   */
  printf("^ %s\n", title); /* Output title */

  /* Draw the bar chart */
  position = max;

  for(i = 0; i <= page_height; i++) {
  /*
   * The for loop outputs page_height lines of characters. Each line will represent a distance of vert_scale on the
   * vertical axis. We get this value by dividing page_height by the difference between the maximum and minimum values.
   * Therefore, the first line of output corresponds to position having the value max, and it’s decremented by
   * vert_scale on each iteration until it reaches min.
   */

    /* Check if we need to output the horizontal axis */
    /* On each line, you must decide first if you need to output the horizontal axis. This will be necessary when
     * position is less than or equal to 0 and you haven’t already displayed the axis.
     */
    if(position <= 0.0 && !axis) {
      printf("+");   /*  Start of horizontal axis */
      for(bars = 0; bars < bar_count*(barwidth + space); bars++)
	printf("-"); /* Output the horizontal axis*/
      printf(">\n");
      axis = true;   /* Axis was drawn            */
      position -= vert_scale; /* Decrement position */
      continue;
    }
    printf("|");    /* Output vertical axis   */
    plastbar = pfirstbar; /* start w/the first bar */
    
    /* For each bar.. */
    for(bars = 1; bars <= bar_count; bars++) {
      /* If position is between axis and value, output column */
      /* Otherwise output blank                               */
      printf("%s", position <= plastbar->value
                   && plastbar->value >= 0.0
                   && position > 0.0 
	           || position >= plastbar->value
                   && plastbar->value <= 0.0
	           && position <= 0.0 ? column : blank);
      plastbar = plastbar->pnextbar;
    }
    printf("\n"); /* End the line of output */
    position -= vert_scale; /* Decrement position */
  }
  if(!axis) { /* Have we output the horizontal axis */
    printf("+");
    for(bars = 0; bars <= bar_count*(barwidth+space); bars++)
      printf("-");
    printf(">");
  }
  
  /* Code for the rest of the function */
  

  free(blank);          /* Free memory for blank string   */
  free(column);         /* Free memory for collumn string */
  return 0;
}
