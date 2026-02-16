#include <stdio.h>

int n;

void iter(int n)
{
    int k = 0, l = 1, m = 0;
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", m);
        m = k + l;
        k = l;
        l = m;
    }
}

int recc(int n)
{
    if (n <= 1)
        return n;
    return recc(n - 1) + recc(n - 2);
}

void febi(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", recc(i));
    }
}

int main()
{
    printf("enter the n=");
    scanf("%d", &n);
    printf("Iterative: ");
    iter(n);
    printf("\nRecursive: ");
    febi(n);
    return 0;
}