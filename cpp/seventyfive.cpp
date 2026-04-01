#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

class mutex_demo
{
    long long counter;
    mutex m;

    void add_many(int loops)
    {
        for(int i=0;i<loops;i++)
        {
            lock_guard<mutex> lock(m);
            counter++;
        }
    }

    public:
    mutex_demo(): counter(0)
    {
        const int loops=500000;

        thread t1(&mutex_demo::add_many, this, loops);
        thread t2(&mutex_demo::add_many, this, loops);

        t1.join();
        t2.join();

        cout<<"expected: "<<(2LL*loops)<<"\n";
        cout<<"actual  : "<<counter<<"\n";
    }
};

int main()
{
    mutex_demo m1;
}
