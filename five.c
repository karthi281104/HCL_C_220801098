#include<stdio.h>

int main()
{
    char c;
    printf("enter the character=");
    scanf("%c",&c);
    if(c>=65 && c<=122)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            printf("the character is vowel");
        }
        else
        {
            printf("the character is consonant");
        }
    }
    else if (c>='0' && c<='9')
    {
        printf("The character is a digit");
    }
    else
    {
        printf("Special character");
    }
    
    
}