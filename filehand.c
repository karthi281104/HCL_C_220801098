#include<stdio.h>

void bubbleSort(int arr[], int n);

int main()
{
    FILE *ptr;
    ptr=fopen("sample.txt","w");
    if(ptr==NULL)
    {
        return 1;
    }
    fprintf(ptr,"%d %d %d %d %d %d",5,4,3,5,6,8);
    fclose(ptr);

    ptr=fopen("sample.txt","r");
    int nums[100], count = 0;
    while (fscanf(ptr, "%d", &nums[count]) == 1) {
        count++;
    }
    fclose(ptr);

    bubbleSort(nums, count);

    ptr = fopen("sorted.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(ptr, "%d ",nums[i]);
    }
    fclose(ptr);

}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}