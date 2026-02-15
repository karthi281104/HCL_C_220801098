#include<stdio.h>

int main()
{
    int a,b;
    printf("enter the value of a and b=");
    scanf("%d%d",&a,&b);
    b=a+b;
    a=b-a;
    b=b-a;
    printf("After swapping: a=%d, b=%d",a,b);
    return 0;
}