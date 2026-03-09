#include<iostream>

using namespace std;

class operations
{
    public:
    int and(int a,int b)
    {
        return a&b;
    }
    int or(int a,int b)
    {
        return a|b;
    }
    int xor(int a,int b)
    {
        return a^b;
    }
    int leftshift(int a,int b)
    {
        return a<<b;
    }
    int rightshift(int a,int b)
    {
        return a>>b;
    }
};

int main()
{
    int a,b;
    cout<<"enter the two numbers\n";
    cin>>a>>b;
    operations op;
    cout<<"the and of the two numbers is "<<op.and(a,b)<<endl;
    cout<<"the or of the two numbers is "<<op.or(a,b)<<endl;
    cout<<"the xor of the two numbers is "<<op.xor(a,b)<<endl;
    cout<<"the left shift of the first number by the second number is "<<op.leftshift(a,b)<<endl;
    cout<<"the right shift of the first number by the second number is "<<op.rightshift(a,b)<<endl;
}