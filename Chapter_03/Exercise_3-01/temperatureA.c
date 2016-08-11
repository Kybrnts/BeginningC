/* Exercise 3-1A, another way */
/* In this version we will aim to avoid using float types. To achieve this, we start by considering our "y = mx + n"
 * general conversion formula, where the author provides us with y = mx + n. In the case of c-to-f conversion, it
 * is easy to represent m and n with integers, but that is not what happens in the complementary case. The number that
 * is the hardest to represent w/an integers is m = 5/9 ~ 0.555. To get a 3 decimal digit integer representation of it,
 * we can use the figure of "55 thousandths" but we must not forget the "thousandths" part of it. Now if we use m =
 * "55 thousandths", we have actually multiplied "m" by a factor of 1000; hence in the need of maintaining the y =
 * mx + n formula we can also feed thousandths of degrees to it instead of degrees, and by multiplying n by 1000000 we
 * will get 1000m*1000x + 1000000n = 1000000(mx + n) = 1000000y. Therefore we must bare in mind that y will be in
 * millionths of degrees.
 */
#include <stdio.h>
#define MC 9/5    /* Value of m in y = mx + n for conversion from celsius to fahrenheit */
#define NC 32     /* Value of n in previous equation                                    */
#define MF 5/9    /* Value of m conversion formula from fahrenheit to celsius           */
#define NF -160/9 /* Value of n in same formula                                         */
int main(void) {

  char unit = 'c';    /* Stores an input character                                          */
  int goahead = 1,    /* Stops execution when input a wrong conversion type                 */
    udegs = 0, cdegs, /* Store input unit degrees and tenths of degrees respectively        */
    m = 0 , n = 0;    /* Storage for the values of 10m and 100n in mentioned formulas       */
  long temp = 0;      /* Converted temperature storage                                      */

  /* Prompt the user to choose the type of conversion */
  printf("Please enter the unit of the temperature you want to convert from\n"
         "Celsius (C) or Fahrenheit (F)?: ");
  scanf("%c", &unit);

  /* Try to change the input to lowercase              */
  if(unit <= 'a')
    unit += 'a' - 'A';
  /* Verify the selected conversion type               */
  switch(unit) {
  case 'c':
    printf("Converting from CELSIUS to FAHRENHEIT.\n");
    m = 1000*MC;
    n = 1000000*NC;
    break;
  case 'f':
    printf("Convertinf from FAHRENHEIT to CELSIUS.\n");
    /* Now Calculate, but with good enough aproximation */
    m = 1000*MF;
    n = 1000000*NF;
    break;
  default:        /* Wrong conversion type     */
    printf("Wrong conversion type! Try again.\n");
    goahead = 0;  /* Prevent further execution */
  }
  /* From now on when goahead is set tu true, if "unit" is not set to 'c', it is set to 'f'  */
  /* Continue with further calculations if possible                                          */
  if(goahead) {
    /* Prompt the user and read entered temperature in whole degrees                         */
    printf("Please enter the termperature in %s whole degrees: ",
	   unit == 'c' ? "CELSIUS" : "FAHRENHEIT");
    scanf("%d", &udegs);
    /* As above, but with hundredths of degress                                              */
    printf("                              %s...and tenths of degrees: ",
	   unit == 'c' ? "" : "   ");
    scanf("%2d", &cdegs);
    if(cdegs < 0) {
      printf("Wrong decimal value! Try again.\n");
    }else {
      printf("m: %d\n", m);
      printf("n: %d\n", n);
      /* Turn input into thousandths of degrees adding the cents of degrees w/the right sign */
      temp = udegs*1000 + (udegs < 0 ? -cdegs : cdegs)*10;
      printf("temp: %ld\n", temp);
      /* Convert the above to other unit (remember that output will be 1000000 times bigger) */
      temp = m*temp + n;
      printf("temp: %ld\n", temp);
      /* Get whole degrees from temperature                                                  */
      udegs = temp/1000000;
      printf("udegs: %d\n", udegs);
      /* Get the decimal part of the output w/the correct sign                               */
      cdegs = (udegs < 0 ? -temp%1000000 : temp%1000000);
      printf("cdegs: %d\n", cdegs);
      /* Round de decimal part of the output                                                 */
      cdegs = cdegs/100000 + (cdegs%100000/10000 < 5 ? 0 : 1);
      printf("cdegs: %d\n", cdegs);
      printf("Temperature in %s is %d.%d. degrees\n", 
	     unit == 'c' ? "FAHRENHEIT" : "CELSIUS",
	     udegs, cdegs);
    }
  }
  return 0;
}
