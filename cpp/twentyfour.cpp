#include<iostream>

using namespace std;

class pointer_strings
{
    public:
    pointer_strings()
    {
        const char* arr[]={"apple","banana","cherry","date","elderberry"};
        int n=5;
        cout<<"strings using pointer dereferencing\n";
        for(int i=0;i<n;i++)
        {
            cout<<*(arr+i)<<"\n";
        }
    }
};

int main()
{
    pointer_strings p1;
}
