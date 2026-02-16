#include<stdio.h>
#include<ctype.h>

int main()
{
    char s[300];
    printf("enter the string=");
    if(fgets(s,sizeof(s),stdin)==NULL)
        return 0;

    int len=0;
    while(s[len]!='\0' && s[len]!='\n')
        len++;
    s[len]='\0';

    int l=0;
    int r=len-1;
    int ok=1;

    while(l<r)
    {
        while(l<r && !isalnum((unsigned char)s[l]))
            l++;
        while(l<r && !isalnum((unsigned char)s[r]))
            r--;

        if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r]))
        {
            ok=0;
            break;
        }
        l++;
        r--;
    }

    if(ok)
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}
