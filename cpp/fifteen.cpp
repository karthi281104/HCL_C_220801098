#include<iostream>

using namespace std;

class cryptobox
{
    string private_key;
    string owner;
    friend void dumpforaudit(const cryptobox &c);
    public:
    cryptobox(string key, string own)
    {
        private_key=key;
        owner=own;
        cout<<"cryptobox created for "<<owner<<"\n";
    }
};

void dumpforaudit(const cryptobox &c)
{
    cout<<"\naudit report\n";
    cout<<"owner: "<<c.owner<<"\n";
    cout<<"private key: "<<c.private_key<<"\n";
}

// void regularfunction(const cryptobox &c)
// {
//     cout<<c.private_key; // error: private_key is private - does not compile
//     cout<<c.owner;       // error: owner is private - does not compile
// }

int main()
{
    cryptobox c1("abc123xyz","alice");
    cryptobox c2("qwerty987","bob");
    dumpforaudit(c1);
    dumpforaudit(c2);
}
