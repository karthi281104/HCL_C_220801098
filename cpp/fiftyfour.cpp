#include<iostream>
#include<string>
#include<regex>

using namespace std;

class url_check
{
    public:
    url_check()
    {
        string url;
        cout<<"enter url (http/https)\n";
        getline(cin,url);

        regex r(R"(^https?://[A-Za-z0-9.-]+(:\d+)?(/\S*)?$)");
        cout<<"valid http/https url? "<<(regex_match(url,r) ? "yes" : "no")<<"\n";
    }
};

int main()
{
    url_check u1;
}
