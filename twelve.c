#include<stdio.h>

int countDigits(int n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n=n/10;
    }
    return c;
}

int ipow(int base,int exp)
{
    int r=1;
    for(int i=0;i<exp;i++)
        r=r*base;
    return r;
}

int isArmstrong(int n)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;

    int digits=countDigits(n);
    int temp=n;
    int sum=0;
    while(temp>0)
    {
        int d=temp%10;
        sum=sum + ipow(d,digits);
        temp=temp/10;
    }
    return sum==n;
}

int isPerfect(int n)
{
    if(n<=1)
        return 0;

    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
            sum=sum+i;
    }
    return sum==n;
}

int main()
{
    int n;
    printf("enter the number=");
    scanf("%d",&n);

    if(isArmstrong(n))
        printf("Armstrong number");
    else
        printf("Not an Armstrong number");

    if(isPerfect(n))
        printf("\nPerfect number");
    else
        printf("\nNot a Perfect number");

    return 0;
}
