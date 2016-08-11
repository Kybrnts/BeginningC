/* Just playing around w/bitwise operators */
#include <stdio.h>

/* Define constant masks symbols  */
#define MALE 0x1u          /* 0000.0000.0000.0001 */
#define FRENCH 0x2u        /* 0000.0000.0000.0010 */
#define GERMAN 0X4u        /* 0000.0000.0000.0100 */
#define ITALIAN 0x8u       /* 0000.0000.0000.1000 */
#define PAYBRACKET 0x10u   /* 0000.0000.0001.0000 */

int main(void) {
  unsigned personal_data = MALE; /* Bit based personal data record */
  
  /* Set second bit to 1 */
  personal_data |= FRENCH;
  /* personal_data          = 0000.0000.0000.0001
   * FRENCH                 = 0000.0000.0000.0010
   * --------------------------------------------
   * personal_data | FRENCH = 0000.0000.0000.0011
   */
  /* Set third bit to 1 */
  personal_data |= ITALIAN;
  /* personal_data          = 0000.0000.0000.0011
   * FRENCH                 = 0000.0000.0000.1000
   * --------------------------------------------
   * personal_data | FRENCH = 0000.0000.0000.1011
   */  
  /* Get 4th bit (german citizenship) status */
  if(personal_data & ITALIAN)
  /* personal_data          = 0000.0000.0000.1011
   * GERMAN                 = 0000.0000.0000.0100
   * --------------------------------------------
   * personal_data & GERMAN = 0000.0000.0000.0100
   */      
    printf("This is an Italian citizen.\n");
  /* Get 3rd bit (german citizenship) status */
  if(!(personal_data & GERMAN))
  /* personal_data          = 0000.0000.0000.1011
   * GERMAN                 = 0000.0000.0000.0100
   * --------------------------------------------
   * personal_data & GERMAN = 0000.0000.0000.0000
   */      
    printf("This is not a german citizen.\n");
  /* Get 1st bit (gender) */

  /* Set a german and french woman personal data record */
  personal_data = 0x0u | FRENCH | GERMAN;
  /* And then check for this condition */
  if(!(personal_data & MALE) && (personal_data & FRENCH) && (personal_data && GERMAN))
    printf("This is a female, franco-german citizen\n");

  return 0;
}
