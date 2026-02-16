#include<stdio.h>

int main()
{
    int n;
    double a[100];
    printf("enter the size=");
    scanf("%d",&n);

    if(n<=0 || n>100)
    {
        printf("invalid size");
        return 0;
    }

    double *p=a;
    printf("enter the elements=");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",p);
        p++;
    }

    double sum=0;
    p=a;
    for(int i=0;i<n;i++)
    {
        sum=sum + (*p);
        p++;
    }

    printf("average= %.2f",(float)(sum/n));
    return 0;
}
