#include<stdio.h>
#include<stdlib.h>


void merge(int arr[],int left,int right,int mid)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int *arr1 = (int*)malloc(n1 * sizeof(int));
    int *arr2 = (int*)malloc(n2 * sizeof(int));

    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        arr2[j]=arr[mid+j+1];
    }

    int i=0,j=0,k=left;

    while (i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
    
    
}

void mergesort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid =left+(right-left)/2;

        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);

        merge(arr,left,right,mid);
    }


}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
	
    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}