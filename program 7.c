#include <stdio.h>
#include <stdlib.h>
typedef struct node

            {

                int data;

                struct node *left;

                struct node *right;

             

            }Node;


int * create()

{

 

 int x;

Node *newnode=(Node*)malloc(sizeof(Node));

 printf("Enter the data for the nodes(-1 for no data)");



 scanf("%d", &x);



 if(x==-1)

 {
     return NULL;
 }

      newnode->data=x;

      printf("Enter the left child data rooted at %d \n",newnode->data);

      newnode->left=create();

      printf("Enter the right child data rooted at %d\n",newnode->data);

      newnode->right=create();

      return newnode;

 

}
}	
int nodes(node* root)
{
    if (!root)
    return 0;
    return 1+nodes(root->left)+nodes(root->right);
}
int nonleafnodes(node* root)
{
    if (!root)
    return 0;
    if (!root->right && !root->left)
    return 0;
    return 1+nonleafnodes(root->left)+nonleafnodes(root->right);
}
int leafnodes(node* root)
{
    if (!root)
    return 0;
    if (!root->right && !root->left)
    return 1;
    return leafnodes(root->left)+leafnodes(root->right);
}

int main()

{

Node *root=create();

Node *t=root;

   printf ("No. of nodes = %d\n",nodes(root));
   printf ("No. of leaf nodes = %d\n",leafnodes(root));
   printf ("No. of non leaf nodes =%d\n",nonleafnodes(root));
    return 0;

}