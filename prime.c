#include<stdio.h>

int prime(int n);

int optimised_prime_sqrt(int n);

int main()
{
    int num,choice;
    printf("enter the number=");
    scanf("%d",&num);
    printf("enter 1 for normal method and 2 for optimised method=");
    scanf("%d",&choice);
    if(choice==1)
    {
        prime(num);
    }
    else if(choice==2)
    {
        optimised_prime_sqrt(num);
    }
    else
    {
        printf("invalid choice");
    }
}

int prime(int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        printf("the number is prime");
    }
    else
    {
        printf("the number is not prime");
    }
}

int optimised_prime_sqrt(int n)
{
    if(n<=1)
    {
        printf("the number is not prime");
        return 0;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            printf("the number is not prime");
            return 0;
        }
    }
    printf("the number is prime");
}

