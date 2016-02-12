/* Exercise 9.3 */
/*
 * Define a function that will accept an array of pointer to strings as an argument and return a pointer to a string
 * that contains all the strings joined into a single string, each terminated by a newline character. If an original
 * string in the input array has newline as its last character, the function shouldn't add another to the string.
 * Write a program to demonstrate this functioin in operation by reading a number of strings from the keyboard and
 * outputting the resultant combined string.
 */
#include <stdio.h>
#include <stdlib.h>

#define STRSSIZE  100  /* Size of the string list */
#define MAXSTRLEN 2048 /* Max string lenght       */
#define INPUTLEN 256   /* Input buffer size       */
#define MAXATTEMPTS 5  /* Max read attempts       */
#define TEOS "*next*"  /* End of string token     */
#define TEOI "*done*"  /* End of input token      */

/* Function prototypes */
int mystrlen(const char *string);                /* Measures the length of the argument string             */
int mystrcpy(char *dest, const char *orig);      /* Copies the second argument string in the first one     */
int strssize(char *strs[], const int strsnum);   /* Gets how many chars are used in a list of strings      */
char *joinstrs(char *strings[], const int size); /* The function required by the problem                   */
void display(const char *string);                /* Display a string                                       */
int readln(char **string);                       /* Reads an entire line from keyboard                     */
/* 
 * We are willing to define readln() so that it is able to read a string from stdin, allocate enough consecutive bytes
 * from the heap to hold it, and assign the address of the first of those bytes to the received parameter, which will be
 * one element of an array of pointers to char. Hence it needs to be of the type pointer.
 * If we think of the available options for a parameter declared as say "char *s" that was assigned to the element of
 * the previous array, we can later in the body of the function call "*s", which is of the type "char", and so it cannot
 * be assigneto the address of the first of the allocated bytes, and of course "s" itself which is just a copy of the
 * original value, so even if we assign it to the address of the first allocated byte it would be useless as well.
 * Now if we think of the options for an argument declared as "char **s", we can perfectly assign "*s" it to the address
 * of the first allocated bytes (because it matches the required type). In addition that will change the value of the
 * received parameter (because **s points to its address).
 */
void flushln(void);                              /* Flush remaining chars of a line when readln fails      */
void freestr(char **string);                     /* Release the heap allocated space for a single string   */
void freestrs(char **strings, const int size);   /* Release the heap allocated space for a list of strings */
char mytolower(const char c);                    /* Turns alphabetic chars to lower case                   */
int istoken(const char *str, const char *token); /* Determines if a string is a token, i.e. special        */
int readstr(char **string, const int num);       /* Reads a whole string as a line series from keyboard    */

int main(int argc, char *argv[]) {
  char *strings[STRSSIZE] = { NULL };
  char *joined = NULL;
  int returned,
    i;

  if(argc > 1) {                            /* Do we have arguments?                */
    joined = joinstrs(&argv[1], argc - 1);  /* Yes, so join them in a single string */
    if(!joined) {
      printf("Error! Unable to allocate memory for the new string. Finishing program..\n");
      return 1;
    }
    display(joined);
    freestr(&joined);
    return 0;
    /*
     * In this case we used the argv array as "array of pointers to strings" to be joined. It seems that argv memory
     * space is allocated in the stack, and so it can't be released with the free function.
     */
  }
  /* Here we don't have arguments to join, so ask for them reading from stdin */
  printf("Enter a list of strings each as a line series.\n"
	 "Use the tokens %s/%s in a single line to separate strings/finish.\n\n", TEOS, TEOI);
  for(i = 0; i < STRSSIZE; i++) {
    if(!(returned = readstr(&strings[i], i))) {
      printf("OK, no more strings then.\n");
      i++;
      break;      
    }
    if(returned > 2) {
      printf("Error! Failed to read input. Finishing program..\n");
      freestrs(strings, i); /* Remove previously stored strings (nothing's been stored in #i) */
      return 2;
    }
    if(returned == 2)
      printf("Warning! Last entered line will not be ignored.\n");
    if(i == STRSSIZE)
      printf("Maximum input strings number reached. No more allowed.\n");
  }
  joined = joinstrs(strings, i);
  if(!joined) {
    printf("Error! Unable to allocate memory for the new string. Finishing program..\n");
    freestrs(strings, i);
    return 1;
  }
  freestrs(strings, i);
  display(joined);
  freestr(&joined);
  return 0;
}

/**********************************************************************************************************************
 * Function    : mystrlen                                                                                             *
 * Inputs      : Const char *c. Address of the first byte of a string						      *
 * Outputs     : N/A												      *
 * Return      : Counted characters starting from the address c, up to right before the first occurrence of '\0'.     *
 * Description : Starts counting 0 characters, checking that the *c is not '\0' and then increasing c offset one char *
 *               and checking again... Hence returning position in which '\0' is found, relative to the first char.   *
 *														      *
 **********************************************************************************************************************/
int mystrlen(const char *c) {
  int n = 0;      /* Starts counter in 0                          */
  while(*(c + n)) /* Does c + counter offset points to '\0'?      */
    n++;          /* No, hence increase the counter and ask again */
  return n;       /* Yes, then return the counter                 */
}

/**********************************************************************************************************************
 * Function    : mystrcpy											      *
 * Inputs      : const char *o. Reference to the fist byte of a string to be copied.				      *
 * Outputs     : char *d. Reference to the fist byte of a string destination (its characters to be changed).	      *
 * Return      : Count of the copied characters.								      *
 * Description : Starts the count in 0. Copies the o pointed value to the matching d destination, changing both	      *
 *               pointing addresses to the next character and then if the copied value is not '\0' it increases the   *
 *               count; then copies stepping the pointers and checking again.. Hence copying the '\0' char and        *
 *               returning the relative position to the first char in which '\0' is present in the second parameter.  *
 * 														      *
 **********************************************************************************************************************/
int mystrcpy(char *d, const char *o) {
  int n = 0;           /* Starts counter in 0                                                 */
  while((*d++ = *o++)) /* Copy *o value to *d and step the pointers. Does d points to '\0'?   */
    n++;               /* No, then increase the counter, copy and step pointers and aks again */
  return n;            /* Yes, return the counter                                             */
}

/**********************************************************************************************************************
 * Function    : strssize											      *
 * Inputs      : > char *s[]. A list of strings (Address of the first element of the array)			      *
 *             : > const int n. The number of the list elements							      *
 * Outputs     : N/A												      *
 * Return      : Total number of characters used for the list.							      *
 * Description : Returns to total amount of used characters to build the list, other than the '\0'. For this we must  *
 *             : consider that for every '\n' missing at the end of a string from the list we need to ad one extra    *
 *             : char space, so that later we have space for adding the required '\n' string separator.               *
 *														      *
 **********************************************************************************************************************/
int strssize(char *s[], const int n) {
  int len = mystrlen(s[0]);                       /* Obtain the length of the first element                    */
  if(*(s[0] + len - 1) != '\n')                   /* Increase its size if required                             */
    len++;
  if(n < 2)                                       /* Does the list contains one element?                       */
    return len;                                   /* Yes, then return the required length for this element     */                                               
  return len + strssize(&s[1], n - 1);            /* No, then return the required length for this element plus */
                                                  /*     the size for the list made of the other elements      */
}              

/**********************************************************************************************************************
 * Function    : joinstrs											      *
 * Inputs      : > char *strs[]. List of strings to be joined							      *
 *             : > const int s. Size of the list of strings							      *
 * Outputs     : N/A												      *
 * Return      : Reference to the first character of a new string that contains all the elements of the list one      *
 *             : after the other.										      *
 * Description : See the exercise's details above.								      *
 *														      *
 **********************************************************************************************************************/
char *joinstrs(char *strs[], const int s) {
  char *joined = NULL,  /* Pointer to the joined strings               */
    *pJ = NULL;         /* Pointer to walk through the previous string */
  int i;
  joined = (char *)malloc((strssize(strs, s) + 1)*sizeof(char)); /* Allocate enough memory size for the new string */
                                                                 /* For this consider that the length of the new   */
                                                                 /* string requires to comprise all the lengths    */
                                                                 /* minus one of the previous strings plus one.    */
  if(!joined) {                                                  /* Check for allocated space                      */
    return NULL;
  }
  pJ = joined;                                                   /* Initialize pJ                                  */
  for(i = 0; i < s; i++) {                                       /* Copy a strings element to the proper place in  */
    pJ += mystrcpy(pJ, strs[i]);                                 /* the just-allocated memory space, and skip pJ   */
                                                                 /* to the first available place there.            */
    if(*(pJ - 1) != '\n')                                        /* Add EOL if required, and if so step pJ         */
      *pJ++ = '\n';
  }
  *(++pJ) = '\0';                                                /* Add the string terminator                      */
  return joined;                                                 /* Return the newly created string                */
}

/**********************************************************************************************************************
 * Function    : display											      *
 * Inputs      : char *s. Reference to the first character of the string to display				      *
 * Outputs     : N/A												      *
 * Return      : Void												      *
 * Description : Display a string in a fancy way								      *
 *														      *
 **********************************************************************************************************************/
void display(const char *s) {
  printf("\nInput strings joined ================= \n%s======================================\n", s);
}

/**********************************************************************************************************************
 * Function    : readln												      *
 * Inputs      : char **s. Address of the address where the first element of a string is stored.		      *
 * Outputs     : N/A												      *
 * Return      : > 2 if the input buffer size was exceeded;							      *
 *             : > 1 if it was not possible to allocate enough space in the heap for the input line;		      *
 *             : > 0 if it successfully read the entire input line into *s.					      *
 * Description : Reads one single line into *s									      *
 *														      *
 **********************************************************************************************************************/
int readln(char **s) {
  char buffer[INPUTLEN]; /* Input buffer string */
  int i;                 /* Counter             */
  for(i = 0; i < INPUTLEN; i++)                             /* Stop reading when input length is reached              */
    if((*(buffer + i) = getchar()) == '\n') {               /* Read single character. Was EOL reached ?               */
      *(buffer + i++) = '\0';                               /* Yes, replace '\n' with '\0' and increase counter,      */
      break;                                                /*      then finish.                                      */
    }                                                       /* NO, read and ask again                                 */
  if(i == INPUTLEN && *(buffer + i - 1)) {                  /* Did we reach the input length but no '\0' is there?    */
    return 2;                                               /* Yes, so input buffer size was exceeded, report this to */
                                                            /*      calling function by returning 2.                  */
  }
  *s = (char *)malloc((mystrlen(buffer) + 1)*sizeof(char)); /* NO, so allocate memory on the heap for the buffer      */
  if(!(*s)) {                                               /* Failed to allocate memory?                             */
    return 1;                                               /* Yes, so report it to calling function by returning 1   */
  }
  mystrcpy(*s, buffer);                                     /* No, so copy the buffer to *s                           */
  return 0;                                                 /* Report success to calling function by returning 0      */
}

/**********************************************************************************************************************
 * Function    : flushln											      *
 * Inputs      : N/A												      *
 * Outputs     : N/A												      *
 * Return      : Void												      *
 * Description : This is meant to be called when readln fails, and we need to get the rid of any remaining characters *
 *               in the current stdin line.									      *
 *														      *
 **********************************************************************************************************************/
void flushln(void) {
  while(getchar() != '\n'); /* Read chars until EOL is read */
}

/**********************************************************************************************************************
 * Function    : freestr											      *
 * Inputs      : > char **s. Reference to the heap address where the first element of a string is stored              *
 *             : > const int size of the list of strings							      *
 * Outputs     : N/A												      *
 * Return      : Void												      *
 * Description : Releases all the memory used to store the string						      *
 *														      *
 **********************************************************************************************************************/
void freestr(char **s) {
  free(*s);
  *s = NULL; /* This is why we need **s as a parameter, *s wouldn't work */
}

/**********************************************************************************************************************
 * Function    : freestrs											      *
 * Inputs      : > char **s. Reference to the heap address where the first element of a string-element-list is stored *
 *             : > const int size of the list of strings							      *
 * Outputs     : N/A												      *
 * Return      : Void												      *
 * Description : Releases all the memory used to store the list.						      *
 *														      *
 **********************************************************************************************************************/
void freestrs(char **s, const int size) {
  int i;
  for(i = 0; i < size; i++) { /* For each element, release used memeory */
    freestr(s++);
  }
}

/**********************************************************************************************************************
 * Function    : mytolower											      *
 * Inputs      : const char cr. Value of a character								      *
 * Outputs     : N/A												      *
 * Return      : The lower case argument's matching character							      *
 * Description : If the received value is non-alphabetic-uppercase , it will return it as it is. Else it will return  *
 *		 the matching lowercase character.								      *
 *														      *
 **********************************************************************************************************************/
char mytolower(const char cr) {
  if(cr < 'A' || cr > 'Z')
    return cr;
  return cr + 'a' - 'A';
}

/**********************************************************************************************************************
 * Function    : istoken											      *
 * Inputs      : > const char *s. Reference of the first character of a string					      *
 *             : > const char *t. Reference of the first character of a token string				      *
 * Outputs     : N/A												      *
 * Return      : 1 if the lower case string referenced by s matches the token referenced by t, else it will return 0. *
 * Description : Compares the strings char by char, stopping at the first difference or at the first '\0' found.      *
 *														      *
 **********************************************************************************************************************/
int istoken(const char *s, const char *t) {
  while(mytolower(*s) == *t && *s && *t) {
    s++;
    t++;
  }
  if(*s || *t)
    return 0;
  return 1;
}

/**********************************************************************************************************************
 * Function    : readstr											      *
 * Inputs      : const int n. Index of the element referenced.							      *
 * Outputs     : char**s. Reference to the address where a element of the array list is stored.			      *
 * Return      : 4 if fails five consecutive times to read the same line from a string;				      *
 *             : 3 if called readln() fails to allocate memory for the input line;				      *
 *             : 2 if current size limit has been reached;							      *
 *             : 1 if current readed line is TEOS, which means that this strings needs no more lines;		      *
 *             : 0 if current readed line is TEOI, which means that no more input is needed.			      *
 * Description : Reads a whole string line by line, and writes it into the string list element pointed by s.          *
 *														      *
 **********************************************************************************************************************/
int readstr(char **s, const int n) {
  char string[MAXSTRLEN] = "\n", /* The string to append to the list              */
    *pstring = NULL,             /* Reference to the first char of above string   */
    *line = NULL;                /* Reference to the first char of the input line */
  int retuned,                   /* Storage for readln() returned value           */ 
    linecount = 0,               /* Readed lines counter for current string       */
    attempts = 0;                /* Failed read attempts counter                  */

  pstring = string;
  while(1) {
    printf("Enter line %d, of string %d>", linecount + 1, n);                  /* Prompt the user to enter a line     */
    retuned = readln(&line);                                                   /* Try to read current line            */
    if(retuned == 2) {                                                         /* Did readln falied to read it all?   */
      printf("Error! input line size exceeded. Please try again.\n");          /* Yes, so display errror message      */
      flushln();                                                               /*      clear remaining chars in stdin */
      attempts++;                                                              /*      increase the fails counter     */
      if(attempts == MAXATTEMPTS) {                                            /*      did we reach attempts limit?   */
	printf("Error! Maximum read line attempts reached.\n");
	return 4;                                                              /*      Yes, so finish and report to   */
      }else {                                                                  /*           the calling function.     */
	continue;                                                              /*      No, so try once again.         */
      }
    }
    if(retuned == 1) {                                                         /* Did readln failed to allocate mem?  */
      printf("Error! FAiled to allocate memory for the input line.\n");        /* Yes, so display error message       */
      return 3;                                                                /*      report this to the calling f.  */
    }
    if(istoken(line, TEOI)) {                                                  /* Is current line the TEOS token?     */
      freestr(&line);                                                          /* Yes, so release line resources,     */
	*s = (char *)malloc((mystrlen(string) + 1)*sizeof(char));              /*      allocate memory for the whole  */
	mystrcpy(*s, string);                                                  /*      copy that string to the one    */
      return 0;                                                                /*      and report to the calling f.   */
    }
    if(istoken(line, TEOS)) {                                                  /* Is current line the TEOS token?     */
      freestr(&line);                                                          /* Proceed as before.                  */
	*s = (char *)malloc((mystrlen(string) + 1)*sizeof(char));
	mystrcpy(*s, string);
      return 1;
    }
    if((pstring + mystrlen(line)) - string >= MAXSTRLEN) {                     /* Does current line fit in remaining  */               
                                                                               /* string space?                       */
      printf("Error! input string size exceeded.\n");                          /* No, so display error message,       */
      freestr(&line);                                                          /*     release line used resources,    */
      *s = (char *)malloc((mystrlen(string) + 1)*sizeof(char));                /*     allocate memory for the         */
                                                                               /*     for the previous string,        */
      mystrcpy(*s, string);                                                    /*     copy that string,               */
      return  2;                                                               /*     no more lines allowed for this  */
                                                                               /*     string, so report it and finish */
    }
    pstring += mystrcpy(pstring, line);                                        /* Copy current line into string       */
    freestr(&line);                                                            /* release line used resources         */
    *pstring++ = '\n';                                                         /* Append an EOL char                  */
    linecount++;                                                               /* Increase lines counter              */
    attempts = 0;                                                              /* Reset current line failed read      */
                                                                               /* attempts.                           */
  }
}
