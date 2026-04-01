#include<iostream>
#include<thread>

using namespace std;

class thread_id_demo
{
    public:
    thread_id_demo()
    {
        thread t([](){
            cout<<"inside thread, id: "<<this_thread::get_id()<<"\n";
        });

        cout<<"main thread id: "<<this_thread::get_id()<<"\n";
        t.join();
    }
};

int main()
{
    thread_id_demo t1;
}
