/* */
#include <stdio.h>

#define TYPE_CHAR 0
#define TYPE_SHORT 1
#define TYPE_INT 2
#define TYPE_FLOAT 3
#define TYPE_DOUBLE 4

/* Function prototypes */
struct Number *createnumber(char tsigned, char tlong, char type); /* Creates a number    */
struct Node *createnode(struct Number *num);                      /* Creates a tree node */
struct Node *addnode(struct Number *num, struct Node *pNode);     /* Inserts a new node  */
void listnodes(struct Node *pNode);                               /* List all nodes      */
void freenodes(struct Node *pNode);                               /* Release memory      */

/* Define a number of dynamic type */
struct Number {
  unsigned issigned : 1; /* Signed type flag */
  unsigned islong : 1;   /* Long type flag   */
  unsigned type : 3;     /* Type indicator   */
  union {
    char c;
    unsigned char uc;
    short s;
    unsigned short us;
    int i;
    unsigned int ui;
    long l;
    unsigned long ul;
    float f;
    double d;
    long double ld;
  }value;
};
/* Define a node in a binary tree sorting numbers */
struct node {
  struct Number num,
    *pLeft,
    *pRight;
}

int main(void) {
  struct Number *pnewnumber        /* Current number pointer             */
  struct Node *pRoot = NULL;       /* First node of the tree             */
  char answer = 'n',               /* Y|N Question answer storage        */
    sgnanswer = 'n',               /* Y|N Signed question answer storage */
    lnganswer = 'n',               /* Y|N Long question answer storage   */
    typanswer = 0,                 /* Type question answer storage       */
    *strval = "";                  /* Current num. string value   */
  
  do {
    printf("Select node values's signed type: 0(unsigned)/1(signed): ");
    scanf(" %d", &sgnanswer);
    if(sgnanswer > 1) sgnanswer = 1;
    printf("Select node value's long type: 1(long)/0(otherwise): ");
    scanf(" %d", &lnganswer);
    if(lnganswer > 1) sgnanswer = 1;
    printf("Select node value's type 0(char)/1(short)/2(integer)/3(single prec. float)/3(double prec. float): ");
    scanf(" %d", &typanswer);
    if(typanswer > 4) typanswer = TYPE_DOUBLE;
    pnewnumber = createnumber(sgneanswer, lnganswer, typanswer);
    if(pnewnumber->num.type == TYPE_FLOAT || pnewnumber->num.type == TYPE_DOUBLE) {
      
    }
    
    if(!pRoot)
      pRoot = createnode(pnewnumber);
    else
      addnode(pnewnumber, pRoot);
    printf("\nDo you want to enter another (y or n)? ");
    scanf(" %c", &answer);
  }while(tolower((unsigned)answer) != 'Y');

  return 0;
}
