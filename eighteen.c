#include<stdio.h>

int indexOf(const char *s,const char *pat)
{
    int i=0;
    int j=0;
    if(pat[0]=='\0')
        return 0;

    for(i=0;s[i]!='\0';i++)
    {
        j=0;
        while(s[i+j]!='\0' && pat[j]!='\0' && s[i+j]==pat[j])
            j++;
        if(pat[j]=='\0')
            return i;
    }
    return -1;
}

int main()
{
    char s[300];
    char pat[100];
    printf("enter the string=");
    if(fgets(s,sizeof(s),stdin)==NULL)
        return 0;

    printf("enter the substring=");
    if(fgets(pat,sizeof(pat),stdin)==NULL)
        return 0;

    int i=0;
    while(s[i]!='\0' && s[i]!='\n')
        i++;
    s[i]='\0';

    i=0;
    while(pat[i]!='\0' && pat[i]!='\n')
        i++;
    pat[i]='\0';

    int idx=indexOf(s,pat);
    printf("index= %d",idx);
    return 0;
}
