#include<iostream>

using namespace std;

class negative_check
{
    public:
    negative_check()
    {
        int n;
        cout<<"enter a number\n";
        cin>>n;
        try
        {
            if(n<0) throw n;
            cout<<"number is "<<n<<"\n";
        }
        catch(int e)
        {
            cout<<"error: negative number entered: "<<e<<"\n";
        }
    }
};

int main()
{
    negative_check n1;
}
