#include<iostream>
#include<string>

using namespace std;

class password
{
    string pass;
    public:
    password(string p)
    {
        if(p.length()<8)
        {
            cout<<"password must be at least 8 characters long\n";
            pass="";
        }
        else
        {
            pass=p;
            cout<<"password set successfully\n";
        }
    }
};

int main()
{
    string pass;
    cout<<"enter the password";
    cin>>pass;
    password p1(pass);
    
}

