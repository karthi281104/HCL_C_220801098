#include<iostream>
#include<string>
#include<regex>

using namespace std;

class repeated_words
{
    public:
    repeated_words()
    {
        string s;
        cout<<"enter a sentence\n";
        getline(cin,s);

        regex r(R"(\b(\w+)\s+\1\b)", regex_constants::icase);
        smatch m;
        if(regex_search(s,m,r))
        {
            cout<<"repeated word found: "<<m[1].str()<<"\n";
            cout<<"match: "<<m[0].str()<<"\n";
        }
        else
        {
            cout<<"no repeated consecutive words\n";
        }
    }
};

int main()
{
    repeated_words r1;
}
