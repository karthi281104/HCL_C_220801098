#include<stdio.h>
#include<string.h>


struct student{
    int roll;
    char name[100];
    float marks;
};

int main()
{
    int n;
    printf("enter the number of students");
    scanf("%d",&n);
    struct student students[n];

    int *p=students[0];
    
    for (int i = 0; i <n; i++)
    {
        char temp[100];
        printf("enter the name of the student %d \n",i);
        scanf("%s",&temp);
        strcpy(students[i].name,temp);
        printf("enter the roll of student %d \n",i);
        scanf("%d",&students[i].roll);
        printf("enter the marks of students %d \n",i);
        scanf("%f",&students[i].marks);     
    }
    
    for (int i = 0; i <n; i++)
        {
            printf("name of student %d is %s \n",i,students[i].name);
            printf("roll of student %d is %d \n",i,students[i].roll);
            printf("marks of student %d is %f \n",i,students[i].marks);
        }

    float high=students[0].marks;
    int k;
    for(int i=0;i<n;i++)
    {
        if(students[i].marks>high)
        {
            high=students[i].marks;
            k=i;
        }
    }
    printf("%d",k);
    printf("highest mark %s",students[k].name);

}