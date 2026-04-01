#include<iostream>
#include<string>

using namespace std;

namespace School
{
    struct Student
    {
        int roll;
        string name;
    };
}

int main()
{
    School::Student s;
    cout<<"enter roll\n";
    cin>>s.roll;
    cout<<"enter name\n";
    cin>>s.name;

    cout<<"roll: "<<s.roll<<" name: "<<s.name<<"\n";
}
