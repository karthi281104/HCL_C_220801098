#include<stdio.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);

int main()
{
    int (*ptr1)(int,int)=add;
    int (*ptr2)(int,int)=sub;
    int (*ptr3)(int,int)=mul;
    int (*ptr4)(int,int)=div;
    int n=1;
    while (n!=0)
    {
        int a,b;
        printf("enter the numbers=");
        scanf("%d%d",&a,&b);
        printf("addition=%d\n",ptr1(a,b));
        printf("subtraction=%d\n",ptr2(a,b));
        printf("multiplication=%d\n",ptr3(a,b));
        printf("division=%d\n",ptr4(a,b));
        printf("enter 0 to exit=");
        scanf("%d",&n);
    }
    
}

int add(int a ,int b)
{
    return a+b;
}

int sub(int a ,int b)
{
    return a-b;
}
int mul(int a ,int b)
{
    return a*b;
}
int div(int a ,int b)
{
    return a/b;
}