/* Program 2.4 Simple calculations */
#include <stdio.h>

int main(void) {
  int total_pets;
  int cats;
  int dogs;
  int ponies;
  int others;

  /* Set the number of each kind of pet */
  cats = 2;
  dogs = 1;
  ponies = 1;
  others = 46;
  /* Above statements set values for each variable. So what were their values before they where executed? Well, they
   * could be anything. Previous declaration statements create the variables, but their values will be whatever was left
   * in memory from the last program that used this memory. This statements set initial values, but it would be better
   * to initialize variables when we declare them.
   * The statement "int cats = 2" declares cats as type INT and sets its initial value to 2. Initializing variables as
   * we declare them is very good practice. It avoids doubts about what the initial values are, and if the program
   * doesn’t work as it should, it can help you track down the errors. Avoid leaving spurious values for variables when
   * creating them, which reduces chances of your computer crashing when things do go wrong. Inadvertently working with
   * junk values can cause all kinds of problems. From now on, we’ll always initialize variables in the examples, even
   * if it’s just to 0.
   */

  /* Calculate the total number of pets */
  total_pets = cats + dogs + ponies + others;
  /* In this arithmetic statement, we calculate the sum of all our pets on the RHS of the operator by adding the values
   * of each of the variables together. This total value is then stored in the variable total_pets that appears on the
   * LHS. The new value replaces any old value that was stored in total_pets.
   */
  total_pets = total_pets + 2;
  /* The = symbol in C defines an action. It doesn’t specify that the two sides are equal, as it does in mathematics. It
   * specifies that the value that results from evaluating the RHS expression is to be stored in LHS variable.
   * After executing the first statement here, total_pets will contain the value 50. Then, in the second line, you
   * extract the value of total_pets, add 2 to that value, and store the results back in the variable total_pets. The
   * final total that will be displayed is therefore 52.
   * In an assignment operation, the ='s sign RHS expression is evaluated first, and the result is then stored in the
   * variable on the left. the new value replaces the value that was previously contained in the variable to the LHS.
   * The variable on assignment's LHS is called an lvalue , because it is a location that can store a value. The value
   * that results from executing the expression on the RHS is called an rvalue because it is a value that results from
   * evaluating, and is not an lvalue.
   */

  /* Output the result */
  printf("We have %d pets in total\n", total_pets); 
  return 0;
}
