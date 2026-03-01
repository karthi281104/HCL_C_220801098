#include<stdio.h>

struct items
{
    int id;
    char name[20];
    float price;
};

struct custumer
{
    int id;
    char name[20];
    char city[20];
    struct items item;
    
};

int main()
{
    struct custumer c1;
    c1.id=1;
    strcpy(c1.name,"karthi");
    strcpy(c1.city,"chennai");
    c1.item.id=101;
    strcpy(c1.item.name,"mobile");
    c1.item.price=15000.00; 
    printf("custumer id=%d\n",c1.id);
    printf("custumer name=%s\n",c1.name);
    printf("custumer city=%s\n",c1.city);
    printf("item id=%d\n",c1.item.id);
    printf("item name=%s\n",c1.item.name);
    printf("item price=%.2f\n",c1.item.price);
    return 0;
}



