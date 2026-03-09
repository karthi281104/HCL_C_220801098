#include<iostream>

using namespace std;

class counter
{
    int count;
    public:
    counter(int c=0): count(c){}
    counter& operator++()
    {
        ++count;
        return *this;
    }
    counter operator++(int)
    {
        counter temp=*this;
        count++;
        return temp;
    }
    int get() { return count; }
};

class counter_demo
{
    public:
    counter_demo()
    {
        counter c(0);
        cout<<"initial count: "<<c.get()<<"\n";

        ++c;
        cout<<"after ++c: "<<c.get()<<"\n";

        c++;
        cout<<"after c++: "<<c.get()<<"\n";

        counter a(5);
        int x=a.get();
        a++;
        cout<<"x = c++ (x captured before increment): x="<<x<<" a="<<a.get()<<"\n";

        counter b(5);
        ++b;
        int y=b.get();
        cout<<"y = ++c (y captured after increment): y="<<y<<" b="<<b.get()<<"\n";

        counter d(10);
        cout<<"chained pre-increment ++++(d) result: "<<(++(++d)).get()<<"\n";
    }
};

int main()
{
    counter_demo c1;
}
