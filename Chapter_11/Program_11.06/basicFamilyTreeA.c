/* Program 11.6A Basics of a family tree (a functional approach) */
#include <stdio.h>
#include <stdlib.h>

struct Date {
  int day,
    month,
    year;
};
struct Family {                  /* Family structure declaration */
  struct Date dob;
  char name[20],
    father[20],
    mother[20];
  struct Family *next,           /* Pointer to next structure    */
    *previous;                   /* Pointer to last structure    */
};

/* Function prototypes */
/* Why can they appear before struture declaration even if they use that structures? (See previous version) */
void err_message(const char *message);
int get_yesno(void);
void free_person(struct Family **family);
int get_person(struct Family **family);
void setlink(struct Family *current, struct Family *last);
void display_header(void);
void display_person(const struct Family *family);
void display_foot(void);

/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
void flushin(void);
int get_name(char *string);
int stringToDec(const char *string, int size);
size_t mystrlen(const char *string);
int get_date(struct Date *date);

/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
int main(void) {

  struct Family *first = NULL,   /* Pointer to  first structure       */
    *current = NULL,             /* Pointer to current structure      */
    *last = NULL;                /* Pointer to last structure         */
  int es = 0;                    /* Exit status                       */

  while(1) {
    printf("\nDo you want to enter details of a%s person (Y or N)? ", first ? "nother" : "");
    if(!get_yesno())
      break;
    if((es = get_person(&current)) > 4) {
      err_message("Unable to allocate memory for current person.");
      break;
    }else if(es > 3) {
      err_message("Unable to get current person's name.");
      break;
    }else if(es > 2) {
      err_message("Unable to read current person's birth date.");
      break;
    }else if(es > 1) {
      err_message("Unable to read current person's father name.");
      break;
    }else if(es > 0) {
      err_message("Unable to read current person's mother name.");
      break;
    }
    if(!first)
      first = current;
    else {
      setlink(current, last);
    }
    last = current;
  }
  current = first;
  if(es > 0) {
    while(current) {
      last = current;
      current = current->next;
      free_person(&last);
    }
    printf("Finishing\n");
    return es;
  }
  display_header();
  while(current) {
    display_person(current);
    last = current;
    current = current->next;
    free_person(&last);
  }
  display_foot();
  return 0;
}
/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
void err_message(const char *m) {
  printf("Error! %s\n", m);
}
int get_yesno() {
  char answer[2] = "";
  /* Read 1 charater into answer (the other one is meant to be the "\0"). If a character is '\n' will be ignored  */
  scanf("%1[^\n]", answer);
  /* Clear every ignored (remaining) character */
  flushin();
  if(answer[0] == 'Y' || answer[0] == 'y')
    return 1;
  return 0;
}
void free_person(struct Family **f) {
  free(*f);
  *f = NULL;
}
void setlink(struct Family *c, struct Family *l) {
  l->next = c;
  c->previous = l;
}
int get_person(struct Family **f) {
  *f = (struct Family *)malloc(sizeof(struct Family));
  if(!*f) {
    err_message("Failed while allocating memory for new person.");
    return 5;
  }
  printf("\nEnter the name of the person: ");
  if(get_name((*f)->name))
    return 4;
  printf("Enter %s's date of birth (dd-mm-yyyy): ", (*f)->name);
  if(get_date(&(*f)->dob))
    return 3;
  printf("Who is %s's father? ", (*f)->name);
  if(get_name((*f)->father))
    return 2;
  printf("Who is %s's mother? ", (*f)->name);
  if(get_name((*f)->mother))
    return 1;
  return 0;
}
void display_header() {
  printf("\n\n+---------------------------------------------------------------------------------+"
         "\n|                            List of enterd persons                               |"
         "\n+----------------------+------------+----------------------+----------------------+"
	 "\n| Name                 | Birthday   | Father               | Mother               |");
}
void display_person(const struct Family *f) {
  printf("\n+----------------------+------------+----------------------+----------------------+"
	 "\n| %-20s | %02d/%02d/%04d | %-20s | %-20s |",
	 f->name, f->dob.day, f->dob.month, f->dob.year, f->father, f->mother);
}
void display_foot() {
  printf("\n+---------------------------------------------------------------------------------+\n");
}
/* ---------------------------------------------------- .o0o. ------------------------------------------------------- */
void flushin(void) {
  while(getchar() != '\n');
}
int get_name(char *s) {
  int first = 1,  /* First attempt flag           */
    fails = 0,    /* Failed input attempt counter */
    readed = 0,   /* Readed values number         */
    bcount = 0;   /* Readed bytes number          */
  while(!readed) {                                                 /* Try to read while we don't have any input       */
    if(fails++ == 5) {                                             /* Did we reach the attempt limit? (Count failure) */
    /* We increase the counter AFTER the test so that fails are
     * counted after each failed input attempt.
     */
      err_message("Name read attempts limit reached.");            /*   Yes, so display error message                 */
      return 1;                                                    /*        And report this error to invoker         */
    }
    if(first)                                                      /* Is this the first attempt?                      */
      first = 0;                                                   /*   Yes, so do not prompt user, and switch flag   */
    else                                          
      printf("Names cannot be empty. Try again: ");                /*   No, so prompt user again explaining issue     */
    readed = scanf("%19[^\n]%*[^\n]%n", s, &bcount);               /* Read up to 19 chars to "s" (including spaces)   */
    /* All charaters readed after the 19th, are to be readed but
     * also counted in "bcount". In case user enter EOL before 
     * the 19th char, bcount will be assigned to 0.
     */
    flushin();                                                     /* Clean any remaining char in the input           */
    /* We always need to perform this step after scanf(), that is
     * why we cannot do it in inside the while condition and hence
     * needed the "readed" variable.
     */
  }
  if(bcount > 19)                                                  /* Did we read more than 19 characters?            */
    printf("/!\\Warning/!\\ Entered name has been truncated.\n");  /*   Yes, then actually only 19 were read to "s"   */
  return 0;
}
int stringToDec(const char *str, int s) {
  if(s < 2)
    return *str - '0';
  return *(str + s - 1) - '0' + 10*stringToDec(str, s - 1);
}
size_t mystrlen(const char *c) {
  size_t n = 0;   /* Starts counter in 0                          */
  while(*(c + n)) /* Does c + counter offset points to '\0'?      */
    n++;          /* No, hence increase the counter and ask again */
  return n;       /* Yes, then return the counter                 */
}
int get_date(struct Date *d) {
/* Main logic behind this one is somewhat similar to the get_name()'s */
  int first = 1,
    fails = 0,
    readed = 0;
  char day[3] = "",
    month[3] = "",
    year[5] = "";
  while(readed != 3) {
    if(fails++ == 5) {
      err_message("Date read attempts limit reached.");
      return 1;
    }
    if(first)
      first = 0;
    else
      printf("Invalid data entered. Try again using \"dd-mm-yyyy\" format: ");
    readed = scanf("%2[0-9]%*1[/-]%2[0-9]%*1[/-]%4[0-9]", day, month, year);
    /* If we had used the %<digit>*/
    flushin();
  }
  d->day = stringToDec(day, mystrlen(day));
  d->month = stringToDec(month, mystrlen(month));
  d->year = stringToDec(year, mystrlen(year));
  return 0;
}
