#include<iostream>
#include<string>
#include<regex>

using namespace std;

class phone_format
{
    public:
    phone_format()
    {
        string num;
        cout<<"enter 10-digit number (1234567890)\n";
        getline(cin,num);

        regex r(R"(^(\d{3})(\d{3})(\d{4})$)");
        if(!regex_match(num,r))
        {
            cout<<"invalid input\n";
            return;
        }
        string out=regex_replace(num,r,"($1)$2-$3");
        cout<<"formatted: "<<out<<"\n";
    }
};

int main()
{
    phone_format p1;
}
