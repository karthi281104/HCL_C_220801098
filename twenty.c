#include<stdio.h>

int main()
{
    int n1,n2;
    int a[100],b[100],c[200];
    printf("enter size of first array=");
    scanf("%d",&n1);
    printf("enter size of second array=");
    scanf("%d",&n2);

    if(n1<0 || n1>100 || n2<0 || n2>100)
    {
        printf("invalid size");
        return 0;
    }

    printf("enter first sorted array elements=");
    for(int i=0;i<n1;i++)
        scanf("%d",&a[i]);

    printf("enter second sorted array elements=");
    for(int i=0;i<n2;i++)
        scanf("%d",&b[i]);

    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<n1)
        c[k++]=a[i++];
    while(j<n2)
        c[k++]=b[j++];

    printf("merged array= ");
    for(int x=0;x<k;x++)
        printf("%d ",c[x]);

    return 0;
}
