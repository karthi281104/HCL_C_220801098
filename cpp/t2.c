#include<stdio.h>

int main()
{
    int *pc,c;
    c=5;
    pc=&c;
    c=1;
    printf("%d \n",c);
    printf("%d",*pc);
}