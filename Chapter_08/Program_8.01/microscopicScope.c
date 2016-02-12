/* Program 8.1 A microscopic program about scope */
#include <stdio.h>

int main(void) {
  int count1 = 1; /* Declared in the outer block */
  
  do { /* This is a inner block */
    int count2 = 0; /* Declared in the inner block */
    ++count2;
    printf("\ncount1 = %d    count2 = %d", count1, count2);
  }while(++count1 <= 8);
  /* 
   * As a result, the value of count2 is never more than 1. During each iteration of the loop, the variable count2 is
   * created, initialized, incremented, and destroyed. It only exists from the statement that declares it down to the
   * closing brace for the loop. The variable count1, on the other hand, exists at the main() block level. It continues
   * to exist while it is incremented, so the last printf() produces the value 9.
   * Try modifying the program to make the last printf() output the value of count2. It won't compile. You'll get an
   * error because, at the point where the last printf() is, count2 no longer exists. From this you may guess,
   * correctly, that failing to initialize automatic variables before you use them can cause untold chaos, because the
   * memory that they occupy may be reallocated to something else at the end of their existence. As a consequence, next
   * time around, your uninitialized variables may contain anything but what you expect.
   */
  
  /* count2 no longer exists */
  printf("\ncount1 = %d\n", count1);
  
  return 0;
}
