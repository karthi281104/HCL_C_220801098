#include<iostream>
#include<string>
#include<regex>

using namespace std;

class hashtag_extract
{
    public:
    hashtag_extract()
    {
        string post;
        cout<<"enter a social media post\n";
        getline(cin,post);

        regex r(R"(#(\w+))");
        sregex_iterator it(post.begin(), post.end(), r);
        sregex_iterator end;

        cout<<"hashtags\n";
        int count=0;
        for(; it!=end; ++it)
        {
            cout<<(*it)[0].str()<<"\n";
            count++;
        }
        if(count==0) cout<<"none\n";
    }
};

int main()
{
    hashtag_extract h1;
}
