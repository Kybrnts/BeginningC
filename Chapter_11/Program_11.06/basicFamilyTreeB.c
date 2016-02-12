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
    *previous,                   /* Pointer to last structure    */
    *p_to_pa,                    /* Pointer to father structure  */
    *p_to_ma;                    /* Pointer to mother structure  */
};

/* Function prototypes */
void err_message(const char *message);
int get_yesno(void);
void free_person(struct Family **family);
int get_person(struct Family **family);
void setlink(struct Family *current, struct Family *last);
int samestr(const char *string1, const char *string2);
int set_ancestry(struct Family *pmember1, struct Family *pmember2);
int related(struct Family *pmember1, struct Family *pmember2);
void display_header(void);
int mystrcpy(char *dest, const char *orig);
void dateToString(char string[10], const struct Date *date);
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
  int es = 0,                    /* Exit status                       */
    parents;                     /* Number of..                       */

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
  /* Check for relation for each person in the list from to second to last */
  while(current->next) {
    parents = 0;                     /* Reeset parent count                                              */
    last = current->next;            /* Get Pointer to next                                              */
    while(last) {                    /* This loop tests current person against all reminders in the list */
      if(related(current, last))     /* Found parent ?                                                   */
	if(++parents == 2)           /* Yes, update count and check it                                   */
	  break;                     /* Exit inner loop if both parents found                            */
      last = last->next;             /* Get address of the next                                          */
    }
    current = current->next;         /* Next in the list to check                                        */
  }
  current = first;
  display_header();
  while(current) {
    display_person(current);
    last = current;
    current = current->next;
  }
  display_foot();
  /* Now free Memory */
  current = first;
  while(current) {
    last = current;
    current = current->next;
    free_person(&last);
  }
  /*
   * Note that we don't free the memory in the above loop. If so, the additional statements to output the parent's
   * dates of birth won't be available (and will produce junk output) when the parent structure appears earlier in
   * the list. Hence we need an extra loop at the end to free the memory once the output is complete.
   */
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
int samestr(const char *s1, const char *s2) {
    while(*s1 == *s2 && *s1 && *s2) { /* Compare each char of the first string against the one in */
    s1++;                             /* the other in a matching position.                        */
    s2++;                             /* Stop comparing if a null char is reached or if any       */
  }                                   /* difference is found.                                     */
  if(*s1 || *s2)                      /* Are we at the end of both strings ?                      */
    return 0;                         /* Yes, so the string matches the token                     */
  return 1;                           /* No, so they do not match.                                */
}
int set_ancestry(struct Family *pm1, struct Family *pm2) {
  if(samestr(pm1->father, pm2->name)) {
    pm1->p_to_pa = pm2;
    return 1;
  }
  if(samestr(pm1->mother, pm2->name)) {
    pm1->p_to_ma = pm2;
    return 1;
  }
  return 0;
}
int related(struct Family *pm1, struct Family *pm2) {
  return set_ancestry(pm1, pm2) || set_ancestry(pm2, pm1);
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
  /* Initializing ancestry pointers to NULL */
  (*f)->p_to_pa = NULL;
  (*f)->p_to_pa = NULL;
  return 0;
}
void display_header() {
  printf("\n+-------------------------------------------------------------------------------------------------------------------------+"
         "\n|                                                List of enterd persons                                                   |");
  printf("\n+----------------------+------------+----------------------+----------------------+-------------------+-------------------+"
	 "\n| Name                 | Birthday   | Father               | Mother               | Father's Birthday | Mother's Birthday |"
         "\n+----------------------+------------+----------------------+----------------------+-------------------+-------------------+");
}
int mystrcpy(char *d, const char *o) {
  int n = 0;           /* Starts counter in 0                                                 */
  while((*d++ = *o++)) /* Copy *o value to *d and step the pointers. Does d points to '\0'?   */
    n++;               /* No, then increase the counter, copy and step pointers and aks again */
  return n;            /* Yes, return the counter                                             */
}
void dateToString(char s[11], const struct Date *d) {
  sprintf(s, "%02d/", d->day);
  sprintf(s + 3, "%02d/", d->month);
  sprintf(s + 6, "%04d", d->year);
}
void display_person(const struct Family *f) {
  char dob[11] = "",
    fdob[11] = "",
    mdob[11] = "";
  dateToString(dob, &f->dob);
  if(f->p_to_pa)
    dateToString(fdob, &(f->p_to_pa->dob));
  else
    mystrcpy(fdob, "*UNKNOWN*");
  if(f->p_to_ma)
    dateToString(mdob, &(f->p_to_ma->dob));
  else
    mystrcpy(mdob, "*UNKNOWN*");

  printf("\n| %-20s | %-10s | %-20s | %-20s | %-10s        | %-10s        |",
         f->name, dob, f->father, f->mother, fdob, mdob);
}
void display_foot() {
  printf("\n+-------------------------------------------------------------------------------------------------------------------------+\n\n");
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
