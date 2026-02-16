#include<stdio.h>
#include<limits.h>

int main()
{
    int n;
    printf("enter the integer=");
    scanf("%d",&n);

    long long temp=n;
    int sign=1;
    if(temp<0)
    {
        sign=-1;
        temp=-temp;
    }

    long long rev=0;
    while(temp>0)
    {
        int digit=(int)(temp%10);
        rev=rev*10 + digit;
        temp=temp/10;
    }

    long long result=rev*sign;
    printf("reversed= %lld",result);

    if(result>INT_MAX || result<INT_MIN)
    {
        printf("\nOverflow for 32-bit int");
    }
    else
    {
        printf("\nFits in 32-bit int");
    }

    return 0;
}
