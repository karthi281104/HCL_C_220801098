#include<iostream>

using namespace std;

enum Color
{
    RED,
    GREEN,
    BLUE
};

class enum_demo
{
    public:
    enum_demo()
    {
        Color c=GREEN;
        int value=static_cast<int>(c);
        cout<<"Color GREEN as int: "<<value<<"\n";

        c=BLUE;
        value=static_cast<int>(c);
        cout<<"Color BLUE as int: "<<value<<"\n";
    }
};

int main()
{
    enum_demo e1;
}
