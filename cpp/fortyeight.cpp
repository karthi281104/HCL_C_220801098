#include<iostream>
#include<fstream>

using namespace std;

struct Student
{
    int roll;
    char name[50];
    int age;
};

class student_file
{
    public:
    student_file()
    {
        int n;
        cout<<"enter number of students\n";
        cin>>n;

        Student *arr=new Student[n];
        for(int i=0;i<n;i++)
        {
            cout<<"enter roll\n";
            cin>>arr[i].roll;
            cout<<"enter name\n";
            cin>>arr[i].name;
            cout<<"enter age\n";
            cin>>arr[i].age;
        }

        ofstream fout("students.bin", ios::binary);
        if(!fout.is_open())
        {
            cout<<"failed to open file for writing\n";
            delete[] arr;
            return;
        }
        for(int i=0;i<n;i++) fout.write((char*)&arr[i], sizeof(Student));
        fout.close();
        delete[] arr;
        cout<<"students written to file\n";

        ifstream fin("students.bin", ios::binary);
        if(!fin.is_open())
        {
            cout<<"failed to open file for reading\n";
            return;
        }
        cout<<"\nreading students from file\n";
        Student s;
        while(fin.read((char*)&s, sizeof(Student)))
        {
            cout<<"roll: "<<s.roll<<" name: "<<s.name<<" age: "<<s.age<<"\n";
        }
        fin.close();
    }
};

int main()
{
    student_file s1;
}
