#include<stdio.h>

int strcpy_bounded(char *dest,int destSize,const char *src)
{
    int i=0;
    if(destSize<=0)
        return 1;

    while(i<destSize-1 && src[i]!='\0')
    {
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';

    if(src[i]!='\0')
        return 1;
    return 0;
}

int main()
{
    char src[300];
    char dest[20];

    printf("enter the source string=");
    if(fgets(src,sizeof(src),stdin)==NULL)
        return 0;

    int i=0;
    while(src[i]!='\0' && src[i]!='\n')
        i++;
    src[i]='\0';

    int truncated=strcpy_bounded(dest,(int)sizeof(dest),src);
    printf("copied= %s",dest);
    if(truncated)
        printf("\ntruncated: destination buffer too small");
    else
        printf("\nnot truncated");

    return 0;
}
