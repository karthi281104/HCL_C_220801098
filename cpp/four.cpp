#include<iostream>

using namespace std;

class pallendrome
{
    public:
    pallendrome(string s)
    {
        string rev="";
        for(int i=s.length()-1;i>=0;i--)
        {
            rev+=s[i];
        }
        if(s==rev)
        {
            cout<<"the string is a pallendrome\n";
        }
        else
        {
            cout<<"the string is not a pallendrome\n";
        }
    }
};

int main()
{
    string s;
    cout<<"enter the string\n";
    cin>>s;
    pallendrome p1(s);
}
