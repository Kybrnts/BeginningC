/* Program 3.10 Exercising bitwise operators */
#include <stdio.h>

int main(void) {
  unsigned int original = 0xABC,
    result = 0,
    mask = 0xF; /* Rightmost foru bits (last hexadecimal digit) */

  printf("\nOriginal = %X", original);  /* %X is the required control string */
  
  /* Insert first digit in result */
  result |= original & mask; /* Put right 4 bits from original in result */
  /*
   * Because of the value of the mask, the operation original & mask will result
   * in a 0 bit value except for the last four bits i.e. last digit (C).
   * original & mask = 0000.0000.0000.C
   * Now result holds the same four bits as original, and 0s in the rest of them.
   * result = result | 0000.0000.0000.C = 0000.0000.0000.C
   */
  
  /* Get second digit */
  original >>= 4;  /* Shift original right 4 positions*/
  result <<= 4;    /* Make room for next digit */
  /*
   * This will strip the last 4 bits, i.e. the rightmost hexadecimal digit
   * from "original", and then shift to left the 4 rightmost bits of result.
   * original = 0000.0000.A.B
   * result = 0000.0000.C.0000
   */
  result |= original & mask; /* Put right 4 bits from original in result */
  /*
   * Again like before, result will hold the same last four bits as original,
   * but now original holds the bits of the digit B instead.
   * original & mask = 0000.0000.0000.B
   * result = result | 0000.0000.0000.B = 0000.0000.C.B
   */
  
  /* Get third digit */
  original >>= 4;
  result >>= 4;
  result |= original & mask;
  /* By repeating the same once more we get:
   * original = 0000.0000.0000.A
   * result = 0000.C.B.0000
   * original & mask = 0000.0000.0000.A
   * result = result | 0000.0000.0000.A = 000.C.B.A
   */

  printf("\t result = %X\n", result);
  return 0;
}
