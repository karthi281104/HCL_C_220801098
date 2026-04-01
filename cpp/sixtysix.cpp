#include<iostream>
#include<string>

using namespace std;

namespace Errors
{
    class MyException
    {
        string msg;

        public:
        MyException(string m): msg(m) {}
        string what() { return msg; }
    };
}

int main()
{
    try
    {
        int n;
        cout<<"enter a number\n";
        cin>>n;
        if(n<0) throw Errors::MyException("negative number not allowed");
        cout<<"number: "<<n<<"\n";
    }
    catch(Errors::MyException e)
    {
        cout<<"caught: "<<e.what()<<"\n";
    }
}
