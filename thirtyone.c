#include<stdio.h>

typedef struct custumer
{
    int id;
    char name[20];
    char city[20];
}c;

int main()
{
    c c1;
    c1.id=1;
    strcpy(c1.name,"karthi");   
    strcpy(c1.city,"chennai");
    printf("custumer id=%d\n",c1.id);
    printf("custumer name=%s\n",c1.name);
    printf("custumer city=%s\n",c1.city);
    return 0;
}
