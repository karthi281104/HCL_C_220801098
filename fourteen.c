#include<stdio.h>

int main()
{
    char s[200];
    char ch;

    printf("enter the string=");
    if(fgets(s,sizeof(s),stdin)==NULL)
        return 0;

    int len=0;
    while(s[len]!='\0' && s[len]!='\n')
        len++;
    s[len]='\0';

    printf("enter the character to remove=");
    scanf(" %c",&ch);

    int i=0,j=0;
    while(s[i]!='\0')
    {
        if(s[i]!=ch)
        {
            s[j]=s[i];
            j++;
        }
        i++;
    }
    s[j]='\0';

    printf("result= %s",s);
    return 0;
}
