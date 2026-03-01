#include<stdio.h>
#define num 10

int stack[num];

int top=-1;

int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==(num-1);
}

void push(int n)
{
    if(isfull())
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

int pop()
{
    if(isempty())
    {
        printf("stack is empty");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int peek()
{
    if(isempty())
    {
        printf("stack is empty");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Top element after popping: %d\n", peek());

    return 0;
}