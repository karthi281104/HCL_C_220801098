#include<stdio.h>

int amstrong(int n);
int perfect(int n);
int main()
{
    int num,choice;
    printf("enter the number=");
    scanf("%d",&num);
    printf("enter 1 for amstrong and 2 for perfect=");
    scanf("%d",&choice);
    if(choice==1)
    {
        amstrong(num);
    }
    else if(choice==2)
    {
        perfect(num);
    }
    else
    {
        printf("invalid choice");
    }
}   

int amstrong(int n)
{
    int sum=0,temp=n;
    while(temp!=0)
    {
        int rem=temp%10;
        sum=sum+(rem*rem*rem);
        temp=temp/10;
    }
    if(sum==n)
    {
        printf("the number is amstrong");
    }
    else
    {
        printf("the number is not amstrong");
    }
}

int perfect(int n)
{
    int sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum==n)
    {
        printf("the number is perfect");
    }
    else
    {
        printf("the number is not perfect");
    }
}