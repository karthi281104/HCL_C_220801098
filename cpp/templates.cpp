#include<iostream>
#include<string>

using namespace std;

template<typename T>
T add(T a, T b)
{
    return a+b;
}
template<typename s>
s sub(s a, s b)
{
    return a-b;
}



int main()
{
    cout<<sub(55,33)<<"\n";
    cout<<add(5,10.5)<<"\n";
    cout<<add('a','b')<<"\n";
}