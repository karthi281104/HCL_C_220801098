#include<stdio.h>

int main()
{
    int x=10;
    int *ptr=&x;
    printf("the value of x is %d\n",x);

    *ptr=20;
    printf("the value of x is %d\n",x);
}