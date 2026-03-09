#include<iostream>

using namespace std;

struct point
{
    int x;
    int y;
};

using pt=point;

class alias_demo
{
    public:
    alias_demo()
    {
        pt p1;
        cout<<"enter x coordinate\n";
        cin>>p1.x;
        cout<<"enter y coordinate\n";
        cin>>p1.y;
        cout<<"point: ("<<p1.x<<","<<p1.y<<")\n";

        pt p2;
        cout<<"enter second x coordinate\n";
        cin>>p2.x;
        cout<<"enter second y coordinate\n";
        cin>>p2.y;
        cout<<"point: ("<<p2.x<<","<<p2.y<<")\n";

        cout<<"distance between points: "<<((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y))<<" (squared)\n";
    }
};

int main()
{
    alias_demo a1;
}
