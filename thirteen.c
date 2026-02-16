#include<stdio.h>

int main()
{
    char s[200];
    printf("enter the string=");

    if(fgets(s,sizeof(s),stdin)==NULL)
        return 0;

    int len=0;
    while(s[len]!='\0' && s[len]!='\n')
        len++;

    printf("length= %d",len);
    return 0;
}
