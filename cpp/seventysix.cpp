#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>

using namespace std;

class condition_demo
{
    mutex m;
    condition_variable cv;
    bool ready;

    public:
    condition_demo(): ready(false)
    {
        thread waiter([&](){
            unique_lock<mutex> lock(m);
            cout<<"waiting for signal...\n";
            cv.wait(lock, [&](){ return ready; });
            cout<<"signal received\n";
        });

        thread notifier([&](){
            this_thread::sleep_for(chrono::seconds(2));
            {
                lock_guard<mutex> lock(m);
                ready=true;
            }
            cout<<"notifying after 2 seconds\n";
            cv.notify_one();
        });

        waiter.join();
        notifier.join();
    }
};

int main()
{
    condition_demo c1;
}
