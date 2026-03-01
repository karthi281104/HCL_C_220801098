#include<stdio.h>
#include<stdlib.h>

struct cnode
{
    int data;
    struct cnode* next;
};

typedef struct cnode node;

node *head = NULL;

void insert_begin(int n)
{
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = n;

    if(head == NULL)
    {
        newnode->next = newnode;   // self loop
        head = newnode;
    }
    else
    {
        node *temp = head;

        while(temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_end(int n)
{
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = n;

    if(head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        node *temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void insert_pos(int n, int pos)
{
    if(pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        insert_begin(n);
        return;
    }

    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = n;

    node *temp = head;

    for(int i = 1; i < pos - 1; i++)
    {
        if(temp->next == head)
        {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head;

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *last = head;

        while(last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;

        free(temp);
    }
}

void delete_end()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;

    while(temp->next->next != head)
        temp = temp->next;

    node *last = temp->next;
    temp->next = head;
    free(last);
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head;

    printf("Elements in circular linked list: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while(temp != head);

    printf("\n");
}

int main()
{
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete at beginning\n");
    printf("5. Delete at end\n");
    printf("6. Display\n");

    int n, pos, choice;

    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                insert_begin(n);
                display();
                break;

            case 2:
                printf("Enter number: ");
                scanf("%d", &n);
                insert_end(n);
                display();
                break;

            case 3:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_pos(n, pos);
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
                printf("Invalid choice\n");
        }
    }
}