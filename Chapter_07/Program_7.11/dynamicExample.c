/* Program 7.11 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
  
  unsigned long *primes = NULL, /* Pointer to primes storage area */
    trial = 0;                  /* Integer to be tested           */
  bool found = false;           /* Indicates when we find a prime */
  size_t total = 0,             /* Number of primes required      */
    count = 0,                  /* Number of primes found         */
    i;
  /* 
   * With this example, you can enter the number of prime numbers you want the program to generate. The pointer variable
   * primes refers to a memory area that will be used to store the prime numbers as they're calculated. However, no
   * memory is defined initially in the program.
   */


  /* Promt the user for the the required primes */
  printf("How many primes would you like - you'll get at least 4? ");
  scanf("%u", &total);             /* Total is how many we need to find */
  total = total < 4U ? 4U : total; /* Make sure it ist at least four    */
  /*
   * The space in memory required is allocated after the user's entered the number of primes that wants.
   * After the prompt, the number that you enter is stored in total. The next statement then ensures that total is at
   * least 4. This is because you'll define and store the three primes that you know (2, 3, and 5) by default.
   */
  
  /* Allocate sufficient memory to store the number of primes required */
  primes = (unsigned long *)malloc(total*sizeof(unsigned long));
  if(primes == NULL) { /* Check for malloc failing to allocate the required memory */
    printf("\nNot enough memory. Hasta la vista, baby\n");
    return 1;
  }
  /*
   * You used the value in total to allocate teh appropriate amount of memory to store the primes.
   * Primes grow in size faster than the count so you store them as type unsigned long although if you want to maximize
   * the range you can deal with you could use unsigned long long.
   * You're going to store each prime as type long then, the number of bytes you require is total*sizeof(unsigned long).
   * If the malloc() function returns NULL, no memory was allocated, so you display a message and end the program.
   * The maximum number of primes that you can specify depends on two things: the memory available on your
   * computer, and the amount of memory that your compiler's implementation of malloc() can allocate at one time. The
   * former is probably the major constraint.
   * The argument to malloc() is of type size_t so the integer type that corresponds to size_t will limit the number of
   * bytes you can specify. If size_t corresponds to a 4-byte unsigned integer, you will be able to allocate up to
   * 4294967295 bytes at one time.
   */

  /* We know the first three primes, so let's guive the program a start */
  *primes = 2UL;         /* First prime (indirect assignment) */
  *(primes + 1) = 3UL;   /* Second prime                      */
  *(primes + 2) = 5UL;   /* Third prime                       */
  count = 3U;            /* Number of primes stored           */
  trial = 5U;            /* Set to the last prime we have     */
  /*
   * Once you have the memory allocated for the primes, you define the first three primes and store them in the first
   * three positions in the memory area pointed to by primes.
   * As you can see, referencing successive memory locations is simple. Because primes is of type "pointer to unsigned
   * long", primes+1 refers to the address of the second location -the address being primes plus the number of bytes
   * required to store one data item of type unsigned long. To store each value, you use the indirection operator;
   * otherwise, you would be modifying the address itself.
   * Also you set the variable count to 3 and initialize the variable trial with the last prime you stored.
   * The value in trial will be incremented by 2 to get the next value to be tested when you start searching for the
   * next prime.
   */

  /* Find all the primes required */
  while(count < total) {
    trial += 2UL;                  /* Next value for checking       */
    /* Try dividing by each of the primes we have     */
    /* If any divide exactly, the number is not prime */
    for(i = 0; i < count; i++)
      if(!(found = (trial % *(primes + i))))
	break;                     /* Exit if no reminder           */

    if(found)                      /* We got one - if found is true */
      *(primes + count++) = trial; /* Store it and increment count  */
  }
  /*
   * The variable count is incremented within the loop as each prime is found, and when it reaches the value total, the
   * loop ends.
   * Within the while loop, you first increase the value in trial by 2UL, and then you test whether the value is prime.
   * The for loop does the testing. Within this loop the remainder after dividing trial by each of the primes that you 
   * have so far is stored in found. If the division is exact, the remainder will be 0, and therefore found will be set
   * to false. If you find any remainder is 0, this means that the value in trial isn't a prime and you can continue
   * with the next candidate.
   * The value of an assignment expression is the value that's stored in the variable on the left of the assignment
   * operator. Thus, the value of the expression (found = (trial % *(primes+i))) will be the value that's stored in
   * found as a result of this. This will be false for an exact division, so the expression
   * !(found = (trial % *(primes+i))) will be true in this case, and the break statement will be executed. Therefore,
   * the for loop will end if any previously stored prime divides into trial with no remainder.
   * If none of the primes divides into trial exactly, the for loop will end when all the primes have been tried,
   * and found will contain the result of converting the last remainder value, which will be some positive integer, to
   * type bool. If trial had a factor, the loop will have ended via the break statement and found will contain false.
   * If found is true, you store the value of trial in the next available slot in the memory area. The address of
   * the next available slot is primes+count. Remember that the first slot is primes, so when you have count number of
   * primes, the last prime occupies the location primes+count-1. The statement storing the new prime also increments
   * the value of count after the new prime has been stored. The while loop just repeats the process until you have all
   * the primes requested.
   */

  /* Display primes 5-up */
  for(i = 0; i < total; i++) {
    if(!(i%5U))     
      printf("\n"); /* Newline after every 5 outputs */
    printf("%12lu", *(primes + i));
  }
  printf("\n");     /* Newline for any stragglers     */
  /* 
   * Finally you output the primes five on a line. The for loop will output total number of primes. The printf() that
   * displays each prime value just appends the output to the current line, but the if statement outputs a newline
   * character after every fifth iteration, so there will be five primes displayed on each line. Because the number of
   * primes may not be an exact multiple of five, you output a newline after the loop ends to ensure that there's always
   * at least one newline character at the end of the output.
   */

  return 0;
}
