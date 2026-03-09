#include<iostream>

using namespace std;

class myexception
{
    string message;
    public:
    myexception(string msg): message(msg){}
    string what() { return message; }
};

class employee
{
    public:
    employee()
    {
        string name;
        float salary;
        cout<<"enter employee name\n";
        cin>>name;
        cout<<"enter salary\n";
        cin>>salary;
        try
        {
            if(salary<0) throw myexception("negative salary entered for "+name);
            cout<<"employee "<<name<<" salary "<<salary<<" added\n";
        }
        catch(myexception e)
        {
            cout<<"myexception: "<<e.what()<<"\n";
        }
    }
};

int main()
{
    employee e1;
}
