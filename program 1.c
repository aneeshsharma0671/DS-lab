#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;
node* head=NULL,*last=NULL;
void remove()
{
    int k;
    node* temp=head;
    printf ("enter data to be removed\n");
    scanf("%d",&k);
    if (k==head->data)
    head=head->link;
    else
    {
        node *prev=head;
        while(prev->link && prev->link->data!=k)
        prev=prev->link;
        if (!prev->link)
        {
            printf ("Node not found\n");
            return;
        }
        temp=prev->link;
        prev->link=temp->link;
    }
    free(temp);
}
void printdata()
{
    node* temp=head;
    while(temp)
    {
        printf ("%d ",temp->data);
        temp=temp->link;
    }
    printf ("\n");
}
void create()
{
    if (!head)
    last=head=(node*)malloc(sizeof(node));
    else 
    last=last->link=(node*)malloc(sizeof(int));
    printf ("enter the data\n");
    scanf("%d",&last->data);
    last->link=NULL;
}
int main()
{
    int p;
    printf ("to insert node press 1 else 0\n");
    scanf("%d",&p);
    while(p)
    {
        if(p==1)create();
        printf ("to insert node press 1 else to continue press 0\n");
        scanf("%d",&p);
    }
    printf ("to remove a node press 1 else to continue press 0\n");
    scanf("%d",&p);
    while(p)
    {
        if(p==1)remove();
        printf ("to remove a node press 1 else to continue press 0\n");
        scanf("%d",&p);
    }
    printdata();
}
