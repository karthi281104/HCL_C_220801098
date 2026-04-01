#include<iostream>
#include<string>
#include<regex>

using namespace std;

class digit_check
{
    public:
    digit_check()
    {
        string s;
        cout<<"enter a string\n";
        getline(cin,s);

        regex r(R"(\d)");
        if(regex_search(s,r))
            cout<<"string contains digits\n";
        else
            cout<<"string does not contain digits\n";
    }
};

int main()
{
    digit_check d1;
}
