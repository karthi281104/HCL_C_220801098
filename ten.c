#include<stdio.h>
#include<math.h>
#include<limits.h>

int main()
{
    int n,rem,result=0;
    printf("enter the n value=");
    scanf("%d",&n);

    while(n!=0)
    {
        rem=n%10;
        result=result*10+rem;
        n=n/10;
        
    }
    printf("%d",result);

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
