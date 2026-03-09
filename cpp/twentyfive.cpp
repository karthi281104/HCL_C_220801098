#include<iostream>

using namespace std;

class pointer_to_pointer
{
    public:
    pointer_to_pointer()
    {
        int val=10;
        int *ptr=&val;
        int **pptr=&ptr;

        cout<<"original value: "<<val<<"\n";
        cout<<"value via ptr: "<<*ptr<<"\n";
        cout<<"value via pptr: "<<**pptr<<"\n";

        **pptr=99;
        cout<<"after modifying via pptr\n";
        cout<<"value: "<<val<<"\n";
        cout<<"value via ptr: "<<*ptr<<"\n";
        cout<<"value via pptr: "<<**pptr<<"\n";
    }
};

int main()
{
    pointer_to_pointer p1;
}
