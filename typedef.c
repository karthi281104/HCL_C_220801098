#include<stdio.h>

typedef unsigned long int ul;

typedef struct persons
{
    ul rate;
    float amount;
}p;

int main()
{
    int n;
    printf("enter the number of persons");
    scanf("%d",&n);
    p person[n];
    for(int i=0;i<n;i++)
    {
        printf("enter the rate of person %d \n",i);
        scanf("%lu",&person[i].rate);
        printf("enter the amount of person %d \n",i);
        scanf("%f",&person[i].amount);
        printf("persons total amount is %f \n",person[i].rate*person[i].amount);
    }
    return 0;
}