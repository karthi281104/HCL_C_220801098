#include<stdio.h>
#include<stdlib.h>

struct  lnode
{
    int data;
    struct lnode *next;
    struct lnode *prev;
};
typedef struct lnode node;

node* head = NULL;

void insert_beg(int n)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->prev=NULL;
    if(head==NULL)
    {
        newnode->next= NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;

    }
}

void display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insert_pos(int n)
{
    
    for()
}

int main()
{
    insert_beg(5);
    insert_beg(6);
    display();
    return 0;
}


