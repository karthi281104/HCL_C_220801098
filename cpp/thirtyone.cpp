#include<iostream>
#include<fstream>

using namespace std;

struct employee
{
    int id;
    char name[50];
    float salary;
};

class employee_file
{
    public:
    employee_file()
    {
        int n;
        cout<<"enter number of employees\n";
        cin>>n;

        employee *arr=new employee[n];
        for(int i=0;i<n;i++)
        {
            cout<<"enter id of employee "<<i+1<<"\n";
            cin>>arr[i].id;
            cout<<"enter name\n";
            cin>>arr[i].name;
            cout<<"enter salary\n";
            cin>>arr[i].salary;
        }

        ofstream fout("employees.bin",ios::binary);
        if(!fout.is_open())
        {
            cout<<"failed to open file for writing\n";
            delete[] arr;
            return;
        }
        for(int i=0;i<n;i++) fout.write((char*)&arr[i],sizeof(employee));
        fout.close();
        cout<<"employees written to binary file\n";
        delete[] arr;

        ifstream fin("employees.bin",ios::binary);
        if(!fin.is_open())
        {
            cout<<"failed to open file for reading\n";
            return;
        }
        cout<<"\nemployee details from file\n";
        employee e;
        while(fin.read((char*)&e,sizeof(employee)))
        {
            cout<<"id: "<<e.id<<" name: "<<e.name<<" salary: "<<e.salary<<"\n";
        }
        fin.close();
    }
};

int main()
{
    employee_file e1;
}
