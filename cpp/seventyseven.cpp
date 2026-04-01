#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

class sleep_yield_demo
{
    public:
    sleep_yield_demo()
    {
        thread t1([](){
            for(int i=1;i<=5;i++)
            {
                cout<<"t1 step "<<i<<"\n";
                this_thread::yield();
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        });

        thread t2([](){
            for(int i=1;i<=5;i++)
            {
                cout<<"t2 step "<<i<<"\n";
                this_thread::yield();
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        });

        t1.join();
        t2.join();
    }
};

int main()
{
    sleep_yield_demo s1;
}
