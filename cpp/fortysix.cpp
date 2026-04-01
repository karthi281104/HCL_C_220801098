#include<iostream>
#include<string>

using namespace std;

struct student
{
    int roll;
    string name;
};

class pointer_access
{
    public:
    pointer_access()
    {
        student s;
        cout<<"enter roll\n";
        cin>>s.roll;
        cout<<"enter name\n";
        cin>>s.name;

        student *p=&s;
        cout<<"\naccess using pointer and -> operator\n";
        cout<<"roll: "<<p->roll<<" name: "<<p->name<<"\n";
    }
};

int main()
{
    pointer_access p1;
}
