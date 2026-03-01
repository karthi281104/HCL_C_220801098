#include<stdio.h>
#include<string.h>

struct Employee
{
    char name[20];
    int id;
    float salary;
};

int main()
{
    struct Employee employees[10];
    float total_salary=0;
    for(int i=0;i<10;i++)
    {
        printf("enter the name of employee %d \n",i);
        scanf("%s",&employees[i].name);
        printf("enter the id of employee %d \n",i);
        scanf("%d",&employees[i].id);
        printf("enter the salary of employee %d \n",i);
        scanf("%f",&employees[i].salary); 
        total_salary+=employees[i].salary;    
    }
    printf("total salary payout=%.2f\n",total_salary);

    float high=employees[0].salary;
    int k;
    for(int i=0;i<10;i++)
    {
        if(employees[i].salary>high)
        {
            high=employees[i].salary;
            k=i;
        }
    }
    printf("employee with highest salary is %s with salary %.2f",employees[k].name,employees[k].salary);
    return 0;
}