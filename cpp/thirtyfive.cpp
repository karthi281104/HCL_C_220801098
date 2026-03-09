#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

class string_converter
{
    public:
    int converttoint(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<'0' || s[i]>'9')
            {
                if(i==0 && s[i]=='-') continue;
                throw invalid_argument("non-numeric string: "+s);
            }
        }
        return stoi(s);
    }
    string_converter()
    {
        string inputs[]={"123","45abc","67","hello","89"};
        int n=5;
        for(int i=0;i<n;i++)
        {
            try
            {
                int val=converttoint(inputs[i]);
                cout<<"converted "<<inputs[i]<<" to "<<val<<"\n";
            }
            catch(invalid_argument &e)
            {
                cout<<"error: "<<e.what()<<"\n";
            }
        }
    }
};

int main()
{
    string_converter s1;
}
