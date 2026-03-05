#include<iostream>

using namespace std;

class string1
{
    string string2;
    public:
    string1(string p)
    {
        display(p);
    }
    void display(string p)
    {
        cout<<strlen(p.c_str())<<"\n";
        upper(p);
    }

    void upper(string p)
    {
        for(int i=0;i<strlen(p.c_str());i++)
        {
            if(p[i]>='a' && p[i]<='z')
            {
                p[i]=p[i]-32;
            }
        }
        cout<<p<<"\n";
    }
};

int main()
{
    string pass;
    cout<<"enter the string";
    cin>>pass;
    string1 s1(pass);
}