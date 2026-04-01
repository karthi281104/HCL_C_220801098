#include<iostream>
#include<chrono>

using namespace std;

class optimize_demo
{
    public:
    optimize_demo()
    {
        const long long n=200000000; // 2e8
        volatile double x=1.000001;
        volatile double sum=0.0;

        auto start=chrono::high_resolution_clock::now();
        for(long long i=1;i<=n;i++)
        {
            sum += (x*i) / (i+1);
            x = x*1.0000001 + 0.0000001;
        }
        auto end=chrono::high_resolution_clock::now();
        auto ms=chrono::duration_cast<chrono::milliseconds>(end-start).count();

        cout<<"sum="<<sum<<"\n";
        cout<<"time(ms)="<<ms<<"\n";

        cout<<"\ncompile and compare\n";
        cout<<"MSVC: /Od, /O1, /O2, /Ox (and compare size of .exe)\n";
        cout<<"example: cl /O2 /EHsc seventynine.cpp\n";
    }
};

int main()
{
    optimize_demo o1;
}
