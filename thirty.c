#include<stdio.h>

struct product
{
    int price;
    int discount;
};

int cal_dis(struct product p)
{
    return (p.price*p.discount)/100;
}

int update_price(struct product* p)
{
    p->price=p->price-cal_dis(*p);
    return p->price;
}

int main()
{
    struct product p1;
    p1.price=1000;
    p1.discount=10;
    printf("price after discount=%d\n",update_price(&p1));
    return 0;
}
