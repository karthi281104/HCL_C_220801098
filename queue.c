#include<stdio.h>
#define num 10
int queue[num];

int front=-1,rear=-1;

int isempty()
{
    return front==-1;
}

int isfull()
{
    return rear==num-1;
}

void enqueue(int n)
{
    if(isfull)
    {
        printf("queue is overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=n;
    }
}

int dequeue()
{
    if(isempty)
    {
        printf("queue is underflow");
        return -1;
    }
    else
    {
        int item=queue[front];
        if(rear==front)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
        return item;

    }
}

int peek()
{
    if (isempty)
    {
        printf("queue is full");
        return -1;
    }
    else
    {
        return queue[front];
    }
    
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element: %d\n", peek());

    printf("Dequeue element: %d\n", dequeue());
    printf("Dequeue element: %d\n", dequeue());

    printf("Front element after dequeue: %d\n", peek());

    return 0;
}


