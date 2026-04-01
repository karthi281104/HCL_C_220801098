#include<stdio.h>

int  main()
{
    char s[]="hello";
    char *p=s;
    p[0]='H';
    printf("%s",s);
}