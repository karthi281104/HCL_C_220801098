#include<stdio.h>

int main()
{
    int a,b;
    printf("enter the value of a and b=");      
    scanf("%d%d",&a,&b);
    int *ptr1=&a;
    int *ptr2=&b;
    int temp=*ptr1;
    *ptr1=*ptr2;    
    *ptr2=temp;
    printf("After swapping: a=%d, b=%d",a,b);
}