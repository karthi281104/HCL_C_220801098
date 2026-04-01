#include<iostream>
#include<future>

using namespace std;

long long factorial(int n)
{
    long long ans=1;
    for(int i=2;i<=n;i++) ans*=i;
    return ans;
}

class async_demo
{
    public:
    async_demo()
    {
        int n;
        cout<<"enter n\n";
        cin>>n;

        future<long long> f=async(launch::async, factorial, n);
        cout<<"computing factorial asynchronously...\n";

        long long result=f.get();
        cout<<"factorial("<<n<<") = "<<result<<"\n";
    }
};

int main()
{
    async_demo a1;
}
