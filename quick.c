#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quick(int arr[],int low,int high)
{
    if(low<high)
    {
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    int pi=i+1;

    quick(arr,low,pi-1);
    quick(arr,pi+1,high);
    }
}

int main()
{
    int arr[10]={5,3,6,1,7,8,4,3,6,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,n-1);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
    
}