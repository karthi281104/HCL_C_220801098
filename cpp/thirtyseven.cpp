#include<iostream>

using namespace std;

class tracker
{
    string name;
    public:
    tracker(string n): name(n)
    {
        cout<<"created: "<<name<<"\n";
    }
    ~tracker()
    {
        cout<<"destroyed: "<<name<<"\n";
    }
};

class scope_demo
{
    public:
    scope_demo()
    {
        try
        {
            tracker t1("outer");
            {
                tracker t2("middle");
                {
                    tracker t3("inner");
                    cout<<"throwing exception from innermost scope\n";
                    throw "exception thrown";
                }
            }
        }
        catch(const char* e)
        {
            cout<<"caught: "<<e<<"\n";
        }
        cout<<"after catch block\n";
    }
};

int main()
{
    scope_demo s1;
}
