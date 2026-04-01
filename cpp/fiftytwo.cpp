#include<iostream>
#include<string>
#include<regex>

using namespace std;

class apple_check
{
    public:
    apple_check()
    {
        string s;
        cout<<"enter a string\n";
        getline(cin,s);

        regex r("apple", regex_constants::icase);
        cout<<"contains 'apple' (case-insensitive)? "<<(regex_search(s,r) ? "yes" : "no")<<"\n";
    }
};

int main()
{
    apple_check a1;
}
