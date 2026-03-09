#include<iostream>

using namespace std;

class factorial
{
    public:
    int recursive(int n)
    {
        if(n==0 || n==1) return 1;
        return n*recursive(n-1);
    }
    int iterative(int n)
    {
        int result=1;
        for(int i=1;i<=n;i++)
        {
            result*=i;
        }
        return result;
    }
    factorial()
    {
        int n;
        cout<<"enter a number\n";
        cin>>n;
        cout<<"recursive factorial: "<<recursive(n)<<"\n";
        cout<<"iterative factorial: "<<iterative(n)<<"\n";
    }
};

int main()
{
    factorial f1;
}
