/* Exercise 4-3 */
/* Extend the previous program to output the appropriate name, such as "newline", "space", "tab" and so on, for each
 * character.
 */
#include <stdio.h>
#include <ctype.h> /* Provides isgraph() */

int main(void) {
  unsigned char c; /* Stores the current character to be printed */

  /* Print the table header */
  printf("\nASCII character code values\n"
	 "---------------------------\n\n"
	 "+---------+-------------+-----------+----------------------+\n"
         "| Decimal | Hexadecimal | Character | Control              |\n"
         "+---------+-------------+-----------+----------------------+\n");

  for(c = 0U; c < 128U; c++) {
    /* Print decimal code */
    printf("| %s%u |",  c < 10 ?
	   "    00" : c < 100 ? 
	   "    0" :
	   "    ",
	   c);
    /* Print hexadecimal code */
    printf(" %s%X |", c < 16 ?
	   "        0x" : 
	   "       0x",
	   c);
    /* Print character or control */
    if(isgraph(c))
      printf("         %c |                  N/A |\n", c);
    else
      printf("       N/A | %s |\n", c == 0 ?
	     "                 NUL" : c == 1 ?
	     "                 SOH" : c == 2 ?
	     "                 STX" : c == 3 ?
	     "                 ETX" : c == 4 ?
	     "                 EOT" : c == 5 ?
	     "                 ENQ" : c == 6 ?
	     "                 ACK" : c == 7 ?
	     "  BEL (audible bell)" : c == 8 ?
	     "           Backspace" : c == 9 ?
	     "                  HT" : c == 10 ?
	     "      LF (line feed)" : c == 11?
	     "   VT (vertical tab)" : c == 12 ?
	     "      FF (from feed)" : c == 13 ?
	     "CR (carriage return)" : c == 14 ?
	     "                  SO" : c == 15 ?
	     "                  SI" : c == 16 ?
	     "                 DLE" : c == 17 ?
	     "                 DC1" : c == 18 ?
	     "                 DC2" : c == 19 ?
	     "                 DC3" : c == 20 ?
	     "                 DC4" : c == 21 ?
	     "                 NAK" : c == 22 ?
	     "                 SYN" : c == 23 ?
	     "                 ETB" : c == 24 ?
	     "                 CAN" : c == 25 ?
	     "                  EM"  : c == 26 ?
	     "                 SUB" : c == 27 ?
	     "        ESC (escape)" : c == 28 ?
	     "                  FS" : c == 29 ?
	     "                  GS" : c == 30 ?
	     "                  RS" : c == 31 ?
	     "                  US" : c == 32 ?
	     "               Space" :
	     "                 N/A");
  }
  /* Print the foot of the table */
  printf("+---------+-------------+-----------+----------------------+\n\n");
  return 0;
}
