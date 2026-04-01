#include<iostream>
#include<queue>

using namespace std;

template<class T>
class stack_costly_push
{
    queue<T> q1;
    queue<T> q2;

    public:
    void push(T x)
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    void pop()
    {
        if(q1.empty()) return;
        q1.pop();
    }

    T top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

template<class T>
class stack_costly_pop
{
    queue<T> q1;
    queue<T> q2;

    public:
    void push(T x)
    {
        q1.push(x);
    }

    void pop()
    {
        if(q1.empty()) return;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1,q2);
    }

    T top()
    {
        if(q1.empty()) return T();
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        T ans=q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return ans;
    }

    bool empty()
    {
        return q1.empty();
    }
};

class stack_two_queues_demo
{
    public:
    stack_two_queues_demo()
    {
        cout<<"costly push variant\n";
        stack_costly_push<int> s1;
        s1.push(10); s1.push(20); s1.push(30);
        cout<<"top: "<<s1.top()<<"\n";
        s1.pop();
        cout<<"top after pop: "<<s1.top()<<"\n";

        cout<<"\ncostly pop variant\n";
        stack_costly_pop<int> s2;
        s2.push(1); s2.push(2); s2.push(3);
        cout<<"top: "<<s2.top()<<"\n";
        s2.pop();
        cout<<"top after pop: "<<s2.top()<<"\n";
    }
};

int main()
{
    stack_two_queues_demo s1;
}
