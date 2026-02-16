#include<stdio.h>

int isPrimeBasic(int n)
{
    if(n<=1)
        return 0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int isPrimeOptimized(int n)
{
    if(n<=1)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    printf("enter the number=");
    scanf("%d",&n);

    if(isPrimeBasic(n))
        printf("Basic: Prime");
    else
        printf("Basic: Not prime");

    if(isPrimeOptimized(n))
        printf("\nOptimized: Prime");
    else
        printf("\nOptimized: Not prime");

    return 0;
}
