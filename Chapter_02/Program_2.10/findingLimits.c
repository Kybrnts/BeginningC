/* Program 2.11 Finding the limit */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
  printf("Variables ot the type \"char\" store values from %d to %d", CHAR_MIN, CHAR_MAX);
  printf("Variables ot the type \"unsigned char\" store values from 0 to %u", UCHAR_MAX);

  printf("Variables ot the type \"short\" store values from %d to %d", SHRT_MIN, SHRT_MAX);
  printf("Variables ot the type \"unsigned short\" store values from 0 to %u", USHRT_MAX);

  printf("Variables ot the type \"int\" store values from %d to %d", INT_MIN, INT_MAX);
  printf("Variables ot the type \"unsigned int\" store values from %d to %u", UINT_MAX);

  printf("Variables ot the type \"long\" store values from %ld to %ld", LONG_MIN, LONG_MAX);
  printf("Variables ot the type \"unsigned long\" store values from 0 to %lu", ULONG_MAX);
  
  /*  printf("Variables ot the type \"long long\" store values from %lld to %lld", LLONG_MIN, LLONG_MAX); */
  /* printf("Variables ot the type \"unsigned long long\" store values from 0 to %llu", ULLONG_MAX); */

  printf("The size of the smallest non-zero value of type \"float\" is %.3e", FLT_MIN);
  printf("The size of the largest value of type \"float\" is %.3e", FLT_MAX);

  printf("The size of the smallest non-zero value of type \"double\" is %.3e", DBL_MIN);
  printf("The size of the largest value of type \"double\" is %.3e", DBL_MAX);

  printf("The size of the smallest non-zero value of the type \"long double\" is %.3Le", LDBL_MIN);
  printf("The size of the largest value of the type \"long double\" is %.3Le\n", LDBL_MAX);

  printf("\nVariables of the type \"float\" provide %u decimal digits of precision.", FLT_DIG);
  printf("\nVariables of the type \"double\" provide %u decimal digits of precision.", DBL_DIG);
  printf("\nVariables of the type \"long double\" provide %u decimal digits of precision.", LDBL_DIG);

  return 0;
  
}
