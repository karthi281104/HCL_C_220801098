#include<stdio.h>

int main()
{
    int c;
    float f;
    printf("enter the temperature in C=");
    scanf("%d",&c);
    f= ((c*9)/5)+32;
    printf("\n fahrenheit= %.1f",f);
    return 0;
}