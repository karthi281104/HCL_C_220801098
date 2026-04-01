#include<stdio.h>

    int sub(int a, float b, int c)
    {
        printf("%d %f %d \n",a,b,c);
        return a-b-c;
    }
    void main()
    {
        int (*fn)(int,int,int);
        fn=&sub;
        printf("the number is :%d",(*fn)(2,3,4));
    }
