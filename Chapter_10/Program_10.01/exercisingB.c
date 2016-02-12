/* Program 10.1B Exercising formatted input */
#include <stdio.h>
#include <wchar.h>

#define SIZE (size_t)20        /* Max characters in a word   */

int main(void) {
  int value_count = 0;         /* Count of input values read */
  float fp1 = 0.0;             /* Floating point value read  */
  int i = 0,                   /* First integer read         */
    j = 0;                     /* Second integer read        */
  wchar_t wword1[SIZE] = L" ", /* First wchar string read    */
    wword2[SIZE] = L" ";       /* Second wchar string read   */
  int byte_count = 0;          /* Count of input bytes read  */
  
  value_count = wscanf(L"%l[abcdefghijklmnopqrstuvwxyz] %*1d %ls%n",
		       &fp1, &i, &j, wword1, wword2, &byte_count);
  printf("\nCount of bytes read = %d\n", byte_count);
  printf("\nCount of values read = %d\n", value_count);
  printf("\nfp1 = %f  i = %d  j = %d\n", fp1, i, j);
  printf("\nwword1 = %ls   wword2 = %ls\n", wword1, wword2);
  /* Due to this, this needs to be compiled with gcc -std=c99 */
  /* Check http://www.gnu.org/software/libc/manual/html_node/Streams-and-I18N.html */
  return 0;
}
