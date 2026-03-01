#include<stdio.h>
#include<stdlib.h>

#define num 10

char stack[num];
int top=-1;
int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==(num-1);
}

void push(char n)
{
    if(isfull())
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

char pop()
{
    if(isempty())
    {
        printf("stack is empty");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

char peek()
{
    if(isempty())
    {
        printf("stack is empty");
        return '\0';
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    char str[num];
    printf("Enter a string of parentheses: ");
    scanf("%s", str);  
    int balanced=1;
    for (int i = 0; str[i]!='\0'; i++)
    {
        if(str[i]=='{' || str[i]=='[' || str[i]=='(')
        {
            push(str[i]);
        }
        else
        {
            char top=peek();
            if((str[i]==')' && top=='(') ||
            (str[i]=='}' && top=='{') ||
            (str[i]==']' && top=='['))
            {
                pop();
            }
            else
            {
                balanced=0;
                break;
            }
        }
    }
    if(balanced && isempty())
    {
        printf("The parentheses are balanced.\n");
    }
    else
    {
        printf("The parentheses are not balanced.\n");
    }
    

}
