#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template<class T>
string to_string_custom(const T& v)
{
    ostringstream oss;
    oss<<v;
    return oss.str();
}

template<>
string to_string_custom<string>(const string& v)
{
    return string("\"") + v + "\"";
}

class format_demo
{
    public:
    format_demo()
    {
        int a=10;
        double b=3.1415;
        string c="hello";

        cout<<"int: "<<to_string_custom(a)<<"\n";
        cout<<"double: "<<to_string_custom(b)<<"\n";
        cout<<"string: "<<to_string_custom(c)<<"\n";
    }
};

int main()
{
    format_demo f1;
}
