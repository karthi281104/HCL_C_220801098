#include<stdio.h>

int main()
{
    char s[200];
    printf("enter the lowercase string=");
    if(fgets(s,sizeof(s),stdin)==NULL)
        return 0;

    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='a' && s[i]<='z')
            s[i]=s[i]-('a'-'A');
        i++;
    }

    printf("uppercase= %s",s);
    return 0;
}
