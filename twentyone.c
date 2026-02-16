#include<stdio.h>

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }
int mul(int a,int b){ return a*b; }
int divideInt(int a,int b){ return a/b; }
int modInt(int a,int b){ return a%b; }

int main()
{
    int a,b;
    char op;
    printf("enter a and b=");
    scanf("%d%d",&a,&b);
    printf("enter operator(+ - * / %%)=");
    scanf(" %c",&op);

    int (*fp)(int,int)=NULL;

    if(op=='+') fp=add;
    else if(op=='-') fp=sub;
    else if(op=='*') fp=mul;
    else if(op=='/') fp=divideInt;
    else if(op=='%') fp=modInt;
    else
    {
        printf("invalid operator");
        return 0;
    }

    if((op=='/' || op=='%') && b==0)
    {
        printf("division by zero not allowed");
        return 0;
    }

    printf("result= %d",fp(a,b));
    return 0;
}
