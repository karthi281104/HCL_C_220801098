#include<stdio.h>
#include<stdlib.h>

struct item
{
    int id;
    char name[20];
    float price;
};

int main()
{
    int n;
    printf("enter the number of items");
    scanf("%d",&n);
    struct item* items = (struct item*)malloc(n * sizeof(struct item));

    for (int i = 0; i < n; i++)
    {
        printf("enter the id of item %d \n",i);
        scanf("%d",&items[i].id);
        printf("enter the name of item %d \n",i);
        scanf("%s",&items[i].name);
        printf("enter the price of item %d \n",i);
        scanf("%f",&items[i].price);     
    }
    
    for (int i = 0; i < n; i++)
        {
            printf("id of item %d is %d \n",i,items[i].id);
            printf("name of item %d is %s \n",i,items[i].name);
            printf("price of item %d is %.2f \n",i,items[i].price);
        }

    free(items);
    return 0;
}