#include<stdio.h>
#include<stdlib.h>

struct dnode
{
    int data;
    struct dnode* prev;
    struct dnode* next;
};

typedef struct dnode node;

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
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;

    head = newnode;
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
    newnode->next = NULL;
    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}
void insert_pos(int n, int pos)
{
    if(pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = n;
    if(pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = head;

        if(head != NULL)
            head->prev = newnode;

        head = newnode;
        return;
    }
    node *temp = head;
    for(int i = 1; i < pos - 1; i++)
    {
        if(temp == NULL || temp->next == NULL)
        {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

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
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

void delete_end()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    if(temp->next == NULL)
    {
        free(temp);
        head = NULL;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}
void display()
{
    node *temp = head;
    printf("Elements in doubly linked list: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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