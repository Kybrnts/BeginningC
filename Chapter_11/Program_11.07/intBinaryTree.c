/* Program 11.7 Sorting integers using binary tree */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function prototypes */
struct Node *createnode(long value);                  /* Creates a tree node */
struct Node *addnode(long value, struct Node *pNode); /* Inserts a new node  */
void listnodes(struct Node *pNode);                   /* List all nodes      */
void freenodes(struct Node *pNode);                   /* Release memory      */

/* Define a node in a binary tree sorting integers */
struct Node {
  long item;          /* The data item            */
  int count;          /* Number of copies of item */
  struct Node *pLeft, /* Pointer to left node     */
    *pRight;          /* Pointer to right node    */
};

/* Functio main - execution starts here */
int main(void) {
  long newvalue = 0;
  struct Node *pRoot = NULL;
  char answer = 'n';
  
  do {
    printf("Enter the node value: ");
    scanf(" %ld", &newvalue);
    if(!pRoot)
      pRoot = createnode(newvalue);
    else
      addnode(newvalue, pRoot);
    printf("\nDo you want to enter another (y or n)? ");
    scanf(" %c", &answer);
  } while(tolower((unsigned)answer) == 'y');
  printf("The values in ascending sequence are: ");
  listnodes(pRoot); /* Output the contents of the tree */
  printf("\n");
  freenodes(pRoot); /* Release the heap memory         */
  return 0;
}

struct Node *createnode(long value) {
  struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
  pNode->item = value;                 /* Set the value              */
  pNode->count = 1;                    /* Set the count              */
  pNode->pLeft = pNode->pRight = NULL; /* No left or right nodes yet */
  return pNode;
}

/* Add a new node to the tree */
struct Node *addnode(long value, struct Node *pNode) {
  if(!pNode)                  /* If there's no node          */
    return createnode(value); /* ...create one and return it */
  if(value == pNode->item) {  /* Value equals current node?  */
    ++pNode->count;           /* ...so increment count and   */
    return pNode;             /* ...return the same node     */
  }
  if(value < pNode->item) {                /* If less than the current value */
    if(!pNode->pLeft) {                    /* And there is no left node      */
      pNode->pLeft = createnode(value);    /* create a new left node and     */
      return pNode->pLeft;                 /* return it.                     */
    }else                                  /* If there is no left node...    */
      return addnode(value, pNode->pLeft); /* add value via the left node    */
  }else {                                  /* Value is greater than current  */
    if(!pNode->pRight) {                   /* So, the same process with the  */
      pNode->pRight = createnode(value);   /* right node.                    */
      return pNode->pRight;
    }else
      return addnode(value, pNode->pRight);
  }
}

/* List the node values in ascending sequence */
void listnodes(struct Node *pNode) {
  int i;
  if(pNode->pLeft)
    listnodes(pNode->pLeft);
  for(i = 0; i < pNode->count; i++)
    printf("\n%10ld", pNode->item);
  if(pNode->pRight)
    listnodes(pNode->pRight);
}
/* Release memory allocated to ndes */
void freenodes(struct Node *pNode) {
  if(!pNode)                  /* If there's no node...        */
    return;                   /* we are done.                 */
  if(pNode->pLeft)            /* If there's a left sub-tree   */
    freenodes(pNode->pLeft);  /* free memory for those nodes. */
  if(pNode->pRight)           /* If there's a right sub-tree  */
    freenodes(pNode->pRight); /* free memory for those nodes. */
  free(pNode);                /* free current node memory     */
}
