#include<stdio.h>

int main()
{
    int year;
    printf("enter the year=");
    scanf("%d",&year);

    int leap = (year%400==0) ? 1 : (year%100==0) ? 0 : (year%4==0) ? 1 : 0;

    printf("%d",leap);

    if(leap)
        printf("Leap year");
    else
        printf("Not a leap year");

    return 0;
}
