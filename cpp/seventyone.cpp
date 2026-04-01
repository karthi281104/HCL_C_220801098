#include<iostream>
#include<type_traits>
#include<string>

using namespace std;

template<class T>
struct numeric_only
{
    static_assert(is_arithmetic<T>::value, "T must be numeric");

    static T add(T a, T b)
    {
        return a+b;
    }

    static T mul(T a, T b)
    {
        return a*b;
    }
};

class numeric_demo
{
    public:
    numeric_demo()
    {
        cout<<"int add: "<<numeric_only<int>::add(2,3)<<"\n";
        cout<<"double mul: "<<numeric_only<double>::mul(2.5,4.0)<<"\n";

#if 0
        // enable this to see friendly diagnostic from static_assert
        cout<<numeric_only<string>::add("a","b")<<"\n";
#endif
    }
};

int main()
{
    numeric_demo n1;
}
