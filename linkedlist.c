#include<stdio.h>
#include<stdlib.h>

struct lnode
{
    int data;
    struct lnode* next;
    
};

typedef struct lnode node;

node *head = NULL;

void insert_begin(int n)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("memory allocation is failed");
        return;
    }
    newnode->data=n;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void insert_end(int n)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("memory error");
        return;
    }
    if(head==NULL)
    {
        newnode->data=n;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->data=n;
        newnode->next=NULL;
        node *temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
}

void display()
{
    node *temp=head;
    printf("elements in linked list are :");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}

void insert_pos(int n, int pos)
{
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    node *newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = n;
    newnode->next = NULL;
    if (head == NULL || pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of bounds\n");
            free(newnode);  // Free allocated memory
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    node *temp=head;
    head=temp->next;
    free(temp);
}

void delete_end()
{
    node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

int main()
{
    printf("enter 1 for insertion at beginning\n");
    printf("enter 2 for insertion at end\n");
    printf("enter 3 for insertion at position\n");
    printf("enter 4 for deletion at beginning\n");
    printf("enter 5 for deletion at end\n");
    int n,pos;
    while (1)
    {
        int choice;
        printf("enter your choice=");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the number to be inserted=");
            scanf("%d",&n);
            insert_begin(n);
            display();
            break;
        case 2:
            printf("enter the number to be inserted=");
            scanf("%d",&n);
            insert_end(n);
            display();
            break;
        case 3:
            printf("enter the number to be inserted=");
            scanf("%d",&n);
            printf("enter the position=");
            scanf("%d",&pos);
            insert_pos(n,pos);
            display();
            break;
        case 4:
            delete_begin();
            display();
            break;
        case 5:
            delete_end();
            display();
            break;
        case 6:
            display();
            break;
        
        default:
            printf("invalid choice");
        }
    }
}
