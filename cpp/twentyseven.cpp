#include<iostream>

using namespace std;

class student
{
    public:
    string name;
    int age;
    float grade;
    student()
    {
        name="";
        age=0;
        grade=0;
    }
    void input(int roll)
    {
        cout<<"enter name of student "<<roll<<"\n";
        cin>>name;
        cout<<"enter age\n";
        cin>>age;
        cout<<"enter grade\n";
        cin>>grade;
    }
    void display(int roll)
    {
        cout<<"student "<<roll<<": name="<<name<<" age="<<age<<" grade="<<grade<<"\n";
    }
};

class student_array
{
    public:
    student_array()
    {
        int n;
        cout<<"enter number of students\n";
        cin>>n;
        student *arr=new student[n];
        for(int i=0;i<n;i++) arr[i].input(i+1);
        cout<<"\nstudent details\n";
        for(int i=0;i<n;i++) arr[i].display(i+1);
        delete[] arr;
    }
};

int main()
{
    student_array s1;
}
