#include<iostream>

using namespace std;

class bad_const_cast
{
    const int value;

    public:
    bad_const_cast(int v): value(v)
    {
        cout<<"constructed with value="<<value<<"\n";
    }

    void setValue(int v)
    {
        cout<<"trying to setValue("<<v<<") using const_cast (WRONG)\n";
        int &ref=const_cast<int&>(value);
        ref=v; // undefined behavior
    }

    void display() const
    {
        cout<<"value="<<value<<"\n";
    }
};

int main()
{
    bad_const_cast b1(10);
    b1.display();
    b1.setValue(99);
    b1.display();

    cout<<"note: modifying a const member via const_cast is undefined behavior\n";
    cout<<"it may appear to work or may not, depending on compiler/optimization\n";
}
