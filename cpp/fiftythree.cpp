#include<iostream>
#include<string>
#include<regex>

using namespace std;

class ipv4_check
{
    public:
    ipv4_check()
    {
        string ip;
        cout<<"enter ipv4 address\n";
        getline(cin,ip);

        regex r(R"(^((25[0-5]|2[0-4]\d|1?\d?\d)\.){3}(25[0-5]|2[0-4]\d|1?\d?\d)$)");
        cout<<"valid ipv4? "<<(regex_match(ip,r) ? "yes" : "no")<<"\n";
    }
};

int main()
{
    ipv4_check i1;
}
