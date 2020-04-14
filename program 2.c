#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL,*last=NULL;
void remove()
{
    int k;node* temp=head;
    printf ("enter data to be removed\n");
    scanf("%d",&k);
    if (k==head->data)
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
    }
    else
    {
        node* prev=head;
        while(prev->next && prev->next->data!=k)
        prev=prev->next;
        temp=prev->next;
        if (temp->next)
        temp->next->prev=prev;
        prev->next=temp->next;
    }
    free(temp);
}
void printdata()
{
    node* temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void create()
{
    if (!head)
    {
        last=head=(node*)malloc(sizeof(node));
        last->prev=NULL;
    }
    else
    {
        last->next=(node*)malloc(sizeof(node));
        last->next->prev=last;
        last=last->next;
    }
    last->next=NULL;
    printf ("enter the data");
    scanf("%d",&last->data);
    last->next=NULL;  
}
int main()
{
    int p;
    printf ("to insert node enter 1 else 0\n");
    scanf("%d",&p);
    while(p)
    {
        if (p==1)create();
        printf ("to insert a node press 1 else 0\n");
        scanf("%d",&p);
    }
    printf ("to insert a node press 1 else 0\n");
    scanf("%d",&p);
    while(p)
    {
        if (p==1)remove();
        printf ("to remove a node press 1 else 0\n");
        scanf("%d",&p);
    }
    printdata();
}