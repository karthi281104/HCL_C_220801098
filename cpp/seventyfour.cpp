#include<iostream>
#include<thread>

using namespace std;

class race_demo
{
    long long counter;

    public:
    race_demo(): counter(0)
    {
        const int loops=1000000;

        thread t1([&](){
            for(int i=0;i<loops;i++) counter++;
        });

        thread t2([&](){
            for(int i=0;i<loops;i++) counter++;
        });

        t1.join();
        t2.join();

        cout<<"expected: "<<(2LL*loops)<<"\n";
        cout<<"actual  : "<<counter<<"\n";
        cout<<"note: without synchronization, result can be wrong due to data race\n";
    }
};

int main()
{
    race_demo r1;
}
