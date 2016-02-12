/* Exercise 7.02 */
/*
 * Write a program that will read an arbitrary number of proverbs from the keyboard and store them in memory that's
 * allocated at runtime. The program should then output the proverbs ordered by their length, starting with the shortest
 * and ending with the longest.
 */


#include <stdio.h>
#include <wchar.h>   /* For wide character and function support */
#include <stdbool.h> /* For boolean data type                   */

#define LINESIZE 51   /* Size of input (at least long enough for quitword) */
#define EOL L'\n'     /* End of line character                             */
#define SPACE L' '    /* Space character                                   */
#define TAB L'\t'     /* Tab character                                     */
#define NULLCHR L'\0' /* String terminator                                 */

int main(void) {
  
  wchar_t **proverbs = NULL, /* List of proverbs to be read and sorted by size from input                  */
    **t_proverbs = NULL,     /* Temporal place to store the list of pointers to proverbs                   */
    *t_proverb = NULL,       /* Temporal place to store the already entered portion of a proverb           */
    *line = NULL;            /* Input buffer without unnecessary spaces/tabs                               */
  
  unsigned int i,            /* Indexes to be initialized by demand                                        */
    proverbs_i = 0,          /* Index of the next proverb in the proverb list                              */
    proverbs_len = 0,
    t_proverbs_len = 0;
  size_t t_proverb_len = 0;
  bool first_line = true;    /* Indicates if this is the first line of a proverb                           */

  const wchar_t quitword[] = L"quit**\n", /* Reserved word to finish the program                           */
    doneword[] = L"done**\n",             /* Reserved to stop the input process and go ahead w/the sorting */
    endproverbword[] = L"endp**\n";       /* Reserved word to specify that this proverb has no more lines  */


  /* Create the line to read */
  line = (wchar_t *)malloc((LINESIZE)*sizeof(wchar_t));
  if(!line) {
    printf("Error! Unable to allocate memory for \"line\". Finishing program..");
    return 1;
  }
  /* Now initialize it as the null string */
  *line = NULLCHR;
  printf("Enter a list of proverbs to be sorted by size (unnecessary spaces/tabs will be ignored).\n"
	 "Use the words \"quit**\"/\"done**\" in a single line to finish/proceed with the sorting respectively.\n"
	 "Use the word \"endp**\" in a single line to specify the end of a proverb:\n\n");

  while(1) {
    printf("Proverb's #%d %s? ",  proverbs_i + 1, first_line ? "first line" : "next line ");
    i = 0;  /* Will point tho the next index of line to be entered */

    /* Read an entire line */
    while(1) {
      while((*(line + i) = getwchar()) == SPACE || *(line + i) == TAB); /* Do not copy to line the leading space/tab  */
      if(*(line + i++) == EOL)                                          /* If we reach the end of the input stop      */
	break;                                                          /* Remember to step the index when used       */
      while(i < LINESIZE) {                                             /* Read an entire word to line                */
	*(line + i) = getwchar();                                       /* Step the index when used to enter char     */
	if(*(line + i) == SPACE || *(line + i) == TAB || *(line + i++) == EOL)
	  break;                                                        
      }
      if(i == LINESIZE && *(line + i - 1) != EOL) {                     /* If we run out of space in line             */
	printf("Input line is too long. Please split it in two or more lines and try again.\n");
	i = 0;                                                          /* Reset the line index                       */
	fflush(stdin);                                                  /* Flush remaining chars in stdin             */
	break;                                                          /* Stop reading this line                     */
      }
      if(*(line + i - 1) == EOL)                                        /* If last entered char was EOL stop          */
	break;
      *(line + i++) = SPACE;                                            /* Space entered, so stepping index           */
    }
    *(line + i) = NULLCHR;                                              /* Add the string terminator                  */

    /* Ignore empty lines */
    if(wcslen(line) < 2) {
      continue;
    }

    /* If we readed the quitword, finish the process */
    if(wcscmp(line, quitword) == 0) {
      printf("\nOk, bye then...");
      return 0;
    }
    
    /* If we readed the doneword, finish the reading process */
    if(wcscmp(line, doneword) == 0) {
      break;
    }
   
    /* If we readed the endproverbword, start a new reading process */
    if(wcscmp(line, endproverbword) == 0) {
      if(!first_line) {                       
	proverbs_i++;                         /* Skipt to the next proverb if necessary              */
	printf("\n"                           /* Append proverb separator                            */
	       "********** oO 00 Oo **********\n\n");
	first_line = true;                    /* Next line is going to be the first one of a proverb */
      }
      continue;
    }

    /* Is this the first line of a proverb ?*/
    if(first_line) {
      /* Next line is not the first one */
      first_line = false;
      
      /* Add a new element to the proverb list */
      t_proverbs_len = proverbs_len;                                     /* Save the current length of proverbs list */
      t_proverbs = (wchar_t **)malloc(t_proverbs_len*sizeof(wchar_t *)); /* Allocate enough memory to swap           */
      if(!t_proverbs) {                                                  /* If unable to allocate finish w/errors    */
	printf("Unable to allocate memory for \"t_proverbs\". Finishing program...\n");
	return 1;
      }
      for(i = 0; i < t_proverbs_len; i++)                                /* Swap the allocation of proverb list      */
	*(t_proverbs + i) = *(proverbs + i);
      free(proverbs);
      proverbs = NULL;
      proverbs_len++;                                                    /* Proverbs list will need extra element    */
      proverbs = (wchar_t **)malloc(proverbs_len*sizeof(wchar_t *));     /* Create new proverbs list w/extra element */
      if(!proverbs) {                                                    /* If unable to do so, finish w/errors      */
	printf("Unable to allocate memory for \"proverbs\". Finishing program...\n");
	return 1;
      }
      for(i = 0; i < t_proverbs_len; i++)                                /* Swap the allocation back                 */
	*(proverbs + i) = *(t_proverbs + i);
      free(t_proverbs);
      t_proverbs = NULL;
      *(proverbs + proverbs_i) = (wchar_t *)malloc(sizeof(wchar_t));     /* Add one element to the new element       */
      if(!*(proverbs + proverbs_i)) {
	printf("Unable to allocate memory for proverb %d. Finishing program...\n", proverbs_i);
	return 1;
      }
      **(proverbs + proverbs_i) = NULLCHR;                               /* and initialize it                        */
    }

    /* Add line to current elemento of proverbs list */
    t_proverb_len = wcslen(*(proverbs + proverbs_i)) + 1;
    t_proverb = (wchar_t *)malloc(t_proverb_len*sizeof(wchar_t));
    if(!t_proverb) {
      printf("Unable to allocate memory for \"t_proverb\". Finishing program...\n");
      return 1;
    }
    wcscpy(t_proverb, *(proverbs + proverbs_i));
    free(*(proverbs + proverbs_i));
    *(proverbs + proverbs_i) = NULL;
    *(proverbs + proverbs_i) = (wchar_t *)malloc((t_proverb_len + wcslen(line) + 1)*sizeof(wchar_t));
    if(!(*(proverbs + proverbs_i))) {
      printf("Unable add memory for proverb %d. Finishing program...\n", proverbs_i);
      return 1;
    }
    wcscpy(*(proverbs + proverbs_i), t_proverb);
    free(t_proverb);
    t_proverb = NULL;
    wcscat(*(proverbs + proverbs_i), line);
  }
  
  /* We no longer need line */
  free(line);
  line = NULL;


  /* Sort the proverb list elements by length */
  for(proverbs_i = 0; proverbs_i < proverbs_len - 1; proverbs_i++)
    for(i = proverbs_i + 1; i < proverbs_len; i++)
      if(wcslen(*(proverbs + proverbs_i)) > wcslen(*(proverbs + i))) {
	t_proverb = *(proverbs + i);
	*(proverbs + i) = *(proverbs + proverbs_i);
	*(proverbs + proverbs_i) = t_proverb;
      }

  printf("The following is the entered proverb list, sorted by length:");
  for(proverbs_i = 0; proverbs_i < proverbs_len; proverbs_i++)
    printf("\n\n**********[#%d] Begin proverb \n%S**************   End proverb",
	   proverbs_i + 1,
	   *(proverbs + proverbs_i));
  
  return 0;
}
