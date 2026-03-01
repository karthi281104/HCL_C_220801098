#include<stdio.h>

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int key;
    printf("enter the key=");
    scanf("%d",&key);
    for(int i=0;i<10;i++)
    {
        if(arr[i]==key)
        {
            printf("key found at index %d",i);
            return 0;
        }
    }
}