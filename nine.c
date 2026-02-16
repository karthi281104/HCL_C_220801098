#include<stdio.h>

long long fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    printf("enter N=");
    scanf("%d",&n);

    if(n<=0)
    {
        printf("enter a positive number");
        return 0;
    }

    long long a=0,b=1;
    printf("Iterative: ");
    for(int i=0;i<n;i++)
    {
        printf("%lld ",a);
        long long next=a+b;
        a=b;
        b=next;
    }

    printf("\nRecursive: ");
    for(int i=0;i<n;i++)
    {
        printf("%lld ",fib(i));
    }

    return 0;
}
