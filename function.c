#include<stdio.h>

int intrest(int p,int t,int r);

int main()
{
    int priciple,years,rate;
    printf("enter the priciple,years and rate=");
    scanf("%d%d%d",&priciple,&years,&rate);
    int result=intrest(priciple,years,rate);
    printf("the simple intrest is %d",result);
    return 0;
}

int intrest(int p,int t,int r)
{
    int si=(p*t*r)/100;
    return si;
}
