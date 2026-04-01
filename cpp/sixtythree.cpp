#include<iostream>

using namespace std;

namespace MathOps
{
    int add(int a, int b)
    {
        return a+b;
    }

    int subtract(int a, int b)
    {
        return a-b;
    }
}

int main()
{
    int a=10;
    int b=4;
    cout<<"add: "<<MathOps::add(a,b)<<"\n";
    cout<<"subtract: "<<MathOps::subtract(a,b)<<"\n";
}
