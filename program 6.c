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

int main()

{

Node *root=create();

Node *t=root;

   printf ("No. of nodes = %d",nodes(root));
    return 0;

}