#include<iostream>

using namespace std;

template<class T>
class Box
{
    T value;

    public:
    Box(T v=T()): value(v) {}

    T get() const
    {
        return value;
    }

    void set(T v)
    {
        value=v;
    }
};

template<class T>
class Box<T*>
{
    T* ptr;

    public:
    Box(T* p=NULL): ptr(p) {}

    T* get() const
    {
        return ptr;
    }

    void set(T* p)
    {
        ptr=p;
    }
};

class box_demo
{
    public:
    box_demo()
    {
        Box<int> b1(10);
        cout<<"Box<int> get: "<<b1.get()<<"\n";
        b1.set(25);
        cout<<"Box<int> get: "<<b1.get()<<"\n";

        int x=99;
        Box<int*> b2(&x);
        cout<<"Box<int*> points to: "<<*(b2.get())<<"\n";

        int y=50;
        b2.set(&y);
        cout<<"Box<int*> points to: "<<*(b2.get())<<"\n";
    }
};

int main()
{
    box_demo b1;
}
