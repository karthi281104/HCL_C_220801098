#include<iostream>

using namespace std;

class swap_integers
{
    public:
    void swap(int *a, int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    swap_integers()
    {
        int a,b;
        cout<<"enter two integers\n";
        cin>>a>>b;
        cout<<"before swap: a="<<a<<" b="<<b<<"\n";
        swap(&a,&b);
        cout<<"after swap: a="<<a<<" b="<<b<<"\n";
    }
};

int main()
{
    swap_integers s1;
}
