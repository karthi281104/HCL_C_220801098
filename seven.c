#include<stdio.h>

int main()
{
    int n,fact=1;
    printf("enter the number=");
    scanf("%d",&n);
    if(n==0)
    {
        printf("the factorial is 1");
    }
    else if(n>0)
    {
        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
        }
        printf("the factorial is %d",fact);
    }
    else
    {
        printf("enter a positive number");
    }
}