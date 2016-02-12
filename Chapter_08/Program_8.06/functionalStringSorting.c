/* Program 8.6 The functional approach to string sorting */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
 * At the beginning of the program source file, before you define main(), you have your #include statements for the
 * libraries that you're using and your function prototypes. Each of these is effective from the point of their
 * occurrence to the end of your file, because they're defined outside of all of the functions. They are therefore
 * effective in all of your functions.
 */
bool str_in(char **);               /* Function prototype for str_in   */
void str_sort(const char *[], int); /* Function prototype for str_sort */
/*
 * The first parameter for the str_sort() function has been specified as const, so the compiler will verify that the
 * function body does not attempt to change the values pointed to. Of course, the parameter in the function definition
 * must also be specified as const, otherwise the code won't compile.
 */
void swap(void **p1, void **p2);    /* Swap two pointers               */
void str_out(char *[], int);        /* Function prototype for str_out  */
/*
 * You can see that the parameter names aren't specified here. You aren't obliged to put the parameter names in a
 * function prototype, but it's usually better if you do. I omitted them in this example to demonstrate that you can
 * leave them out but I recommend that you include them in your programs. You can also use different parameter names in
 * the function prototype from those in the function definition. Each function prototype declares the types of the
 * parameters and the return value type for that function.
 * Tip: It can be useful to use longer, more explanatory names in the prototype and shorter names in the function
 * ---- definition to keep the code more concise.
 */

#define BUFFER_LEN 256
#define  NUM_P 50

/* Function main */
int main(void) {

  char *pS[NUM_P]; /* Array of string pointers */
  int count = 0;   /* Number of strings read   */


  printf("\nEnter succesive lines, pressing Enter at the end of"
	 " each line.\nJust press Enter to end.\n");

  for(count = 0; count < NUM_P; count++) /* Max  of NUM_P strings  */
    if(!str_in(&pS[count]))              /* Read a string          */
      break;                             /* Stop input on 0 return */
  /*
   * The argument to the function str_in is &pS[i]. This is the address of pS[i] - in other words, a pointer to pS[i].
   * And pS[i] is a pointer to char. Hence the argument type for that function is to be declared as char**.
   * In this case we want to modify the contents of the elements of pS, so if we used one "*" in the parameter type
   * definition, instead and just used pS[i] as the argument, the function receives whatever is contained in pS[i]
   * which is a memory address.
   *
   * Because all the work is done in the str_in() function, all that's necessary here is to continue the loop until you
   * get false returned from the function, which will cause the break to be executed, or until you fill up the pointer
   * array pS, which is indicated by count reaching the value NUM_P, thus ending the loop. The loop also counts how many
   * strings are entered in count.
   */

  str_sort(pS, count);
  /*
   * Having safely stored all the strings, main() then calls the function str_sort() to sort the strings. The first
   * argument is the array name, pS, so the address of the first location of the array is transferred to the function.
   * The second argument is the count of the number of strings so the function will know how many there are to be
   * sorted.
   */
  
  str_out(pS, count);
  return 0;
}

/*******************************************************
 * String input routine                                *
 * Argument is a pointer to a pointer to a constant    *
 * string which is const char**                        *
 * Returns false for empty string and returns true     *
 * otherwise. If no memory is obtained or if there     *
 * is an error reading from the keyboard, the program  *
 * is terminated by calling exit().                    *
 *******************************************************/
bool str_in(char **pString) {
  /*
   * Here, type char ** and char *[] are the same, which is an array of elements of the type char *
   */
  
  char buffer[BUFFER_LEN];               /* Space to store input string  */

  if(gets(buffer) == NULL) {             /* NULL returned from gets()?   */
    printf("\nError reading string.\n"); 
    exit(1);                             /* Error on input so exit       */
  }
  
  if(buffer[0] == '\0') {                /* Empty string read ?          */
    return false;
  }

  *pString = (char *)malloc(strlen(buffer) + 1);
  
  if(*pString == NULL) {                 /* Check memory allocation      */
    printf("\nOut of memory");
    exit(1);                             /* No memory allocated so exit  */
  }

  strcpy(*pString, buffer);              /* Copy string read to argument */
  return true;
  
}
/*
 * When this function is called from main, the address of pS[i] is passed as the argument. This is the address of the
 * current free array element in which the address of the next string that's entered should be stored. Whithin the
 * function this is referred to as the parameter "pString".
 * The input string is stored in buffer by the function gets(). This function returns NULL if an error occurs while
 * reading the input, so you first check for that. If input fails, you terminate the program by calling to exit(), which
 * is declared in stdlib.h.
 * The exit() function terminates the program and returns a status value to the operating system that depends on the
 * value of the integer argument you pass. A zero argument will result in a value passed to the operating system that
 * indicates a successful end to the program. A nonzero value will indicate that the program failed in some way.
 * You check the first character in the string obtained by gets() against '\0'. The function replaces the newline
 * character that results from pressing the Enter key with '\0'; so if you just press the Enter key, the first character
 * of the string will be '\0'. If you get an empty string entered, you return the value false to main().
 * Once you've read a string, you allocate space for it using the malloc() function and store its address in *pString.
 * After checking that you did actually get some memory, you copy the contents of buffer to the memory that was
 * allocated. If malloc() fails to allocate memory, you simply display a message and call exit().
 */


/****************************************************
 * String sort routine                              *
 * First argument is array of pointers to constant  *
 * strings which is of type const char*[].          *
 * Second argument is the number of elements in the *
 * pointer array - i.e. the number of strings       *
 ***************************************************/
void str_sort(const char *p[], int n) {

  bool sorted = false;                 /* Strings sorted indicator      */
  int i;
  
  while(!sorted) {                     /* Loop until there are no swaps */
    sorted = true;
    for(i = 0; i < n - 1; i++)
      if(strcmp(p[i], p[i+1]) > 0) {
	sorted = false;                /* Indicate we are out of order  */
	swap(&p[i], &p[i + 1]);        /* Swap the pointers             */
      }
  }
}
/* 
 * Within the function, the parameter variable p has been defined as an array of pointers. This will be replaced, when
 * the function is called, by the address for pS that's transferred as an argument. You haven't specified the dimension
 * for p. This isn't necessary (http://www.eskimo.com/~scs/cclass/notes/sx10f.html). The first parameter is const
 * because the function does not change the strings, it simply rearranges their addresses (See pag. 250).
 * You declare the second parameter, n, as type int, and this will have the value of the argument count when the
 * function is called. Also a variable named sorted that will have the value true or false to indicate whether or not
 * the strings have been sorted. Remember that all the variables declared within the function body are local to that
 * function.
 * The strings are sorted in the for loop using the swap() function that interchanges the addresses in two pointers.
 * Notice that only the pointers are altered and that there is no return statement; coming to the end of the function
 * body during execution is equivalent of executing a return statement without a return expression.
 */


/*******************************************
 * Swap two pointers                       *
 * The arguments are type pointer to void* *
 * so pointers can be any type*.           *
 *******************************************/
void swap(void **p1, void **p2) {
  void *pt = *p1;
  
  *p1 = *p2;
  *p2 = pt;
}
/*
 * As you know, pointers are passed by value, just like any other type of argument so to be able to change a pointer,
 * you must pass a pointer to a pointer as the function argument. The parameters here are of type void**, which is
 * "pointer to void*". Any pointer of the form type* will convert to type void* so this function can swap two pointers
 * of any given type. Anyway you could've used char **, as far as you also change it in the function prototype.
 * The swapping process is simple. The address stored at the location specified by p1 is stored in
 * pt. The address stored in p2 is transferred to p1. Finally p2 is set to the original address from p1, now in pt.
 */

/******************************************************
 * String output routine                              *
 * First argument is an array of pointers to strings  *
 * which is the same as char**                        *
 * The second argument is a count of the number of    *
 * pointers in the array i.e. the number of strings   *
 ******************************************************/
void  str_out(char *p[], int n) {
  int i;
  
  printf("\nYour input sorted in order is:\n\n");
  for(i = 0; i < n; i++) {
    printf("%s\n", p[i]);
    free(p[i]);
    p[i] = NULL;
  }
  return;
}
