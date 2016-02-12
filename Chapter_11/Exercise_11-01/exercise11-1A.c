/* Exercise 11-1A An improved version */
#include <stdio.h>
#include <stdlib.h>

#define FEET_PER_YARD 3U    /* Unsigned constant for ammount of feet per yard */
#define INCHES_PER_FOOT 12U /* For ammount of inches per foot                 */

/* ---------------------------------------------------------------------------------------------------------------------
 * General purpose functions
 */
void err_message(const char *message); /* Output errors          */
void flushin(void);                    
int get_yesno(void);                   /* Gets the yes no answer */

/* ---------------------------------------------------------------------------------------------------------------------
 * Length structure definition, input/output and basic arithmetics
 */
typedef struct LengthTAG {
    unsigned yards, /* Yard bytes                      */
      feet,         /* Feet bytes                      */
      inches;       /* Inches bytes                    */
}Length;

Length *newLen(const unsigned inches, const unsigned feet, const unsigned yards); /* Creates a new lengt in heap  */
Length *readLen();                                                                /* Read length from input       */
void show(const Length *Len);                                                     /* Output length components     */
void show_foot(const Length *TotalLen);
void nullifyLen(Length **pLen);                                                   /* Release memory and null ptr. */
void add(Length *sum, const Length *Len1, const Length *Len2);                    /* Add two length values in sum */

/* ---------------------------------------------------------------------------------------------------------------------
 * Node list structure definition, 
 */
typedef struct LenNodeTAG {
  unsigned index;
  Length *Len;
  struct LenNodeTAG *prev,
    *next;
}LenNode;

LenNode *newLenNode(const unsigned index, const Length *Len);
LenNode *readLenNode(const unsigned index);
void show_header(void);
void show_nodeLen(const LenNode *LenN);
void nullifyLenNode(LenNode **LenN);

/* ---------------------------------------------------------------------------------------------------------------------
 * Execution starts here!
 */
int main(void) {
  LenNode *first = NULL,
    *current = NULL,
    *last = NULL;
  Length *total = NULL;
  unsigned count = 0;
  
  while(1) {
    printf("Enter a%s lenght (Y or N)?: ", first ? "nother" : ""); /* Prompt user                    */
    if(get_yesno())
      break;                                                       /* Finish when answer is no       */
    if(!(current = readLenNode(count)))                            /* Did we failed to read length ? */
      continue;                                                    /* Yes, then try again            */
    if(!first)                                                     
      first = current;                                             /* Set ptr. for first list item   */
    else {
      last->next = current;                                        /* Set next ref. for previous one */
      current->prev = last;                                        /* Set previous for current       */
    }
    last = current;                                                /* Remember for next iteration    */
    count++;
  }
  /* Now tell what we know */
  total = newLen(0U, 0U, 0U);
  if(!total) {
    err_message("Main: Failed to allocate memory for \"total\" variable. Finishing.");
    return 1;
  }
  show_header();
  current = first;
  while(current) {
    show_nodeLen(current);
    add(total, total, current->Len);
    last = current;
    current = current->next;
    nullifyLenNode(&last);
  }
  show_foot(total);
  nullifyLen(&total);

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
Length *newLen(const unsigned y, const unsigned f, const unsigned i) {
    Length *new = NULL;
  if(!(new = (Length *)malloc(sizeof(Length)))) {
    err_message("Failed to allocate memory for new Length.");
    return NULL;
  }
  /* Force to use the units correctly */
  new->inches = i%INCHES_PER_FOOT;
  new->feet = ((unsigned)(i/INCHES_PER_FOOT) + f)%FEET_PER_YARD;
  new->yards = (unsigned)(((unsigned)(i/INCHES_PER_FOOT) + f)/FEET_PER_YARD) + y;
  return new;
}
Length *readLen() {
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
  return newLen(yards, feet, inches);
}
void show(const Length *l) {
  printf("| %-6u | %-6u | %-6u |", l->yards, l->feet, l->inches);
}
void show_foot(const Length *t) {
  printf("\n+--------+--------+--------+--------+");
  printf("\n| Total: | %-6u | %-6u | %-6u |", t->yards, t->feet, t->inches);
  printf("\n+--------+--------+--------+--------+\n");
}
void nullifyLen(Length **pl) {
  free(*pl);
  *pl = NULL;
}
void add(Length *s, const Length *l1, const Length *l2) {
  Length *result = newLen(l1->yards + l2->yards,
	 		  l1->feet + l2->feet,
			  l1->inches + l2->inches);
  if(!result) {
    err_message("Unable to perform sum.");
    return;
  }
  s->yards = result->yards;
  s->feet = result->feet;
  s->inches = result->inches;
  nullifyLen(&result);
}
/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
LenNode *newLenNode(const unsigned i, const Length *l){
  LenNode *new = NULL;
  if(!(new = (LenNode *)malloc(sizeof(LenNode)))) {
    err_message("Failed to allocate memory for new LenNode");
    return NULL;
  }
  new->index = i;
  new->Len = l;
  new->prev = new->next = NULL;
  return new;
}
LenNode *readLenNode(const unsigned i) {
  return newLenNode(i, readLen());
}
void show_header(void) {
  printf("\n+-----------------------------------+"
         "\n|          Entered lengths          |");
  printf("\n+--------+--------+--------+--------+"
	 "\n| #      | Yards  | Feet   | Inches |"
         "\n+--------+--------+--------+--------+");
}
void show_nodeLen(const LenNode *lN) {
  printf("\n| %-6u ", lN->index);
  show(lN->Len);
}
void nullifyLenNode(LenNode **pLN) {
  nullifyLen(&((*pLN)->Len));
  free(*pLN);
  *pLN = NULL;
}
