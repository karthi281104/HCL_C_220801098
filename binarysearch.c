#include<stdio.h>
bs(int arr[],int key);

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int key;
    printf("enter the key value:=");
    scanf("%d",&key);
    int r = bs(arr,key);
    printf("Index: %d\n", r);
    return 0;
}

int bs(int arr[],int key)
{
        int l=0,h=9;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(key==arr[mid])
        {
            return mid;
        }
        else
        {
            if(key<arr[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    return -1;
}