#include<iostream>
#include<stack>

using namespace std;

template<class T>
class queue_two_stacks
{
    stack<T> in;
    stack<T> out;

    void move()
    {
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
    }

    public:
    void push(T x)
    {
        in.push(x);
    }

    void pop()
    {
        if(out.empty()) move();
        if(out.empty()) return;
        out.pop();
    }

    T front()
    {
        if(out.empty()) move();
        if(out.empty()) return T();
        return out.top();
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};

class queue_demo
{
    public:
    queue_demo()
    {
        queue_two_stacks<int> q;
        q.push(10);
        q.push(20);
        q.push(30);
        cout<<"front: "<<q.front()<<"\n";
        q.pop();
        cout<<"front after pop: "<<q.front()<<"\n";
        q.pop();
        cout<<"front after pop: "<<q.front()<<"\n";
    }
};

int main()
{
    queue_demo q1;
}
