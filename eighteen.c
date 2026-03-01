#include<stdio.h>

int check_sub(char s1[],char s2[])
{
    int i=0,j=0;
    for(i=0;s1[i]!='\0';i++)
    {
        for(j=0;s2[j]!='\0';j++)
        {
            if(s1[i+j]!=s2[j])
            {
                break;
            }
        }
        if(s2[j]=='\0')
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char s1[] = "embedded systems";
    char s2[] = "system";

    int index = check_sub(s1, ss2);

    if (index != -1)
        printf("Substring found at index %d\n", index);
    else
        printf("Substring not found\n");

    return 0;
}