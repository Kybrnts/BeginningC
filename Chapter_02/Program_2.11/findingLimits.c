/* Program 2.11 Finding the limits */
#include <stdio.h>  /* For command line input and output */
#include <limits.h> /* For limits on integer types */
#include <float.h>  /* For limits on floating-point types */

int main(void) {

  printf("Variables of type \"char\" store values from %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("Variables of type \"unsigned char\" store values from 0 to %u\n\n", UCHAR_MAX);

  printf("Variables of type \"short\" store values from %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Variables of type \"unsigned short\" store values from 0 to %u\n", USHRT_MAX);

  printf("Variables of type \"int\" store values from %d to %d\n", INT_MIN, INT_MAX);
  printf("Variables of type \"unsigned int\" store values from 0 to %u\n\n", UINT_MAX);

  printf("Variables of type \"long\" store values from %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("Variables of type \"unsigned long\" store values from 0 to %lu\n\n", ULONG_MAX);

  /* printf("Variables of type \"long long\" store values from %lld to %lld\n", LLONG_MIN, LLONG_MAX);                */
  /* printf("Variables of type \"unsigned long long\" store values from 0 to %llu\n\n", ULLONG_MAX);                  */
  /* NOTE: It seems that "long long" is not supported by C89 standard (gcc option -std=c89).                          */
  /*       However, we can compile this using C99 standard (gcc option -std=c99) and it also seems that lon long is   */
  /*       the same as long long is the same as long                                                                  */

  printf("The size of the smallest non-zero value of type \"float\" is %.3e\n", FLT_MIN);
  printf("The size of the largest value of type \"float\" is %.3e\n\n", FLT_MAX);

  printf("The size of the smallest non-zero value of type \"double\" is %.3e\n", DBL_MIN);
  printf("The size of the largest value of type \"double\" is %.3e\n\n", DBL_MAX);

  printf("The size of the smallest non-zero value of type \"long double\" is %.3Le\n", LDBL_MIN);
  printf("The size of the largest value of type \"long double\" is %.3Le\n\n", LDBL_MAX);

  printf("Variables of type \"float\" provide %u decimal digits precision.\n", FLT_DIG);
  printf("Variables of type \"double\" provide %u decimal digits precision.\n", DBL_DIG);
  printf("Variables of type \"long double\" provide %u decimal digits precision.\n\n", LDBL_DIG);

  return 0;
}
