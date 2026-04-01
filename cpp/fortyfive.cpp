#include<iostream>
#include<string>

using namespace std;

struct Employee
{
    struct Address
    {
        string house;
        string street;
        string city;
        int pincode;
    } addr;

    int id;
    string name;
    float salary;
};

class employee_details
{
    public:
    employee_details()
    {
        Employee e;

        cout<<"enter employee id\n";
        cin>>e.id;
        cout<<"enter employee name\n";
        cin>>e.name;
        cout<<"enter salary\n";
        cin>>e.salary;

        cout<<"enter house\n";
        cin>>e.addr.house;
        cout<<"enter street\n";
        cin>>e.addr.street;
        cout<<"enter city\n";
        cin>>e.addr.city;
        cout<<"enter pincode\n";
        cin>>e.addr.pincode;

        cout<<"\nemployee details\n";
        cout<<"id: "<<e.id<<" name: "<<e.name<<" salary: "<<e.salary<<"\n";
        cout<<"address: "<<e.addr.house<<", "<<e.addr.street<<", "<<e.addr.city<<" - "<<e.addr.pincode<<"\n";
    }
};

int main()
{
    employee_details e1;
}
