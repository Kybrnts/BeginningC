/* Exercise 11-1 */
/*
 * Define a struct type with the name Length that represents a length in yards, feet, and inches. Define an add()
 * function that will add two Length arguments and return the sum as type Length. Define a second function, show(),
 * that will display the value of its Length argument. Write a program that will use the Length type and the add() and
 * show() functions to sum an arbitrary number of lengths in yards, feet, and inches that are entered from the keyboard
 * and output the total length.
 */
#include <stdio.h>
#include <stdlib.h>

#define FEET_PER_YARD 3U    /* Unsigned constant for ammount of feet per yard */
#define INCHES_PER_FOOT 12U /* For ammount of inches per foot                 */

/* ---------------------------------------------------------------------------------------------------------------------
 * General purpose functions
 */
void err_message(const char *message); /* Output errors          */
void flushin(void);                    /* */
int get_yesno(void);                   /* Gets the yes no answer */

/* ---------------------------------------------------------------------------------------------------------------------
 * Length structure definition, input/output and basic arithmetics
 */
typedef struct LengthTAG {
  unsigned yards,          /* Yard bytes                      */
    feet,                  /* Feet bytes                      */
    inches,                /* Inches bytes                    */
    count;                 /* Item counter                    */
  struct LengthTAG *prev,  /* Left subsidiary node reference  */
    *next;                 /* Right subsidiary node reference */
}Length;
Length *newLen(const unsigned count, const unsigned yards,
	       const unsigned feet, const unsigned inches);    /* Create lengh node     */
Length *readLen(const unsigned count);                         /* Read length values    */
void show(const Length *Len);                                  /* Output node value     */
void show_foot(const Length *Len);                             /* Output total length   */
void freeLen(Length **Len);                                    /* Frees node used mem.  */
void add(Length *sum, const Length *Len1, const Length *Len2); /* Adds values of nodes  */


/* ---------------------------------------------------------------------------------------------------------------------
 * Functions for handling list elements
 */
void show_header();


/* ---------------------------------------------------------------------------------------------------------------------
 * Execution starts here!
 */
int main(void) {
  
  Length *first = NULL,
    *current = NULL,
    *last = NULL,
    *total = NULL;
  unsigned count = 0;
  
  while(1) {
    printf("Enter a%s lenght (Y or N)?: ", first ? "nother" : ""); /* Prompt user                    */
    if(get_yesno())
      break;                                                       /* Finish when answer is no       */
    if(!(current = readLen(count)))                                /* Did we failed to read length ? */
      continue;                                                    /* Yes, then try again            */
    count++;
    if(!first)                                                     
      first = current;                                             /* Set ptr. for first list item   */
    else {
      last->next = current;                                        /* Set next ref. for previous one */
      current->prev = last;                                        /* Set previous for current       */
    }
    last = current;                                                /* Remember for next iteration    */
  }
  /* Now tell what we know */
  total = newLen(0U, 0U, 0U, 0U);
  if(!total) {
    err_message("Main: Failed to allocate memory for \"total\" variable. Finishing.");
    return 1;
  }
  show_header();
  current = first;
  while(current) {
    show(current);
    add(total, total, current);
    last = current;
    current = current->next;
    freeLen(&last);
  }
  show_foot(total);
  freeLen(&total);
  return 0;
}

/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
void err_message(const char *m) {
  printf("Error! %s\n", m);
}
void flushin(void) {
  while(getchar() != '\n');
}
int get_yesno() {
  char answer[2] = "";
  /* Read 1 charater into answer (the other one is meant to be the "\0"). If a character is '\n' will be ignored  */
  scanf("%1[^\n]", answer);
  /* Clear every ignored (remaining) character */
  flushin();
  if(answer[0] == 'Y' || answer[0] == 'y')
    return 0;
  return 1;
}

/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
Length *newLen(const unsigned c, const unsigned y, const unsigned f, const unsigned i) {
  Length *new = NULL;
  if(!(new = (Length *)malloc(sizeof(Length)))) {
    return NULL;
    err_message("Failed to allocate memory for new Length.");
  }
  new->count = c;
  /* Force to use the units correctly */
  new->inches = i%INCHES_PER_FOOT;
  new->feet = ((unsigned)(i/INCHES_PER_FOOT) + f)%FEET_PER_YARD;
  new->yards = (unsigned)(((unsigned)(i/INCHES_PER_FOOT) + f)/FEET_PER_YARD) + y;
  /* Initialize counter */
  new->count = 1;
  /* Initialize previous and next elements of the list */
  new->prev = new->next = NULL;
  return new;
}
Length *readLen(const unsigned count) {
  unsigned yards,
    feet, 
    inches;
  int readed = 0;
  printf("\nEnter the Length (Yards, feet, inches): ");
  readed = scanf("%u%*1[,] %u%*1[,] %u", &yards, &feet, &inches);
  if(readed < 3) {
    err_message("Failed to read length.");
    return NULL;
  }
  flushin();
  return newLen(count, yards, feet, inches);
}
void show(const Length *l) {
  printf("\n| %-6u | %-6u | %-6u | %-6u |", l->count, l->yards, l->feet, l->inches);
}
void show_foot(const Length *l) {
  printf("\n+--------+--------+--------+--------+");
  printf("\n| Total: | %-6u | %-6u | %-6u |", l->yards, l->feet, l->inches);
  printf("\n+--------+--------+--------+--------+\n");
}
void freeLen(Length **l) {
  free(*l);
  *l = NULL;
}
void add(Length *s, const Length *l1, const Length *l2) {
  Length *result = newLen(0U,
			  l1->yards + l2->yards,
	 		  l1->feet + l2->feet,
			  l1->inches + l2->inches);
  if(!result) {
    err_message("Unable to perform sum.");
    return;
  }
  s->yards = result->yards;
  s->feet = result->feet;
  s->inches = result->inches;
  freeLen(&result);
}
/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
void show_header() {
    printf("\n+-----------------------------------+"
         "\n|          Entered lengths          |");
  printf("\n+--------+--------+--------+--------+"
	 "\n| #      | Yards  | Feet   | Inches |"
         "\n+--------+--------+--------+--------+");
}
