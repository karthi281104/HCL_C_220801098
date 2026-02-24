#include<stdio.h>

enum statuscode{pending=2, shipped=1, delevered=0};



int main()
{
    enum statuscode a;
    a = pending;

    printf("Order status: %d\n", a);

    a = shipped;
    printf("Order status: %d\n", a);

    a = delevered;
    printf("Order status: %d\n", a);

    return 0;
}