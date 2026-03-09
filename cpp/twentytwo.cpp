#include<iostream>

using namespace std;

class rectangle
{
    float width;
    float height;
    public:
    rectangle(): width(1), height(1){}
    void setwidth(float w)
    {
        if(w<=0) throw "width must be greater than 0";
        width=w;
    }
    void setheight(float h)
    {
        if(h<=0) throw "height must be greater than 0";
        height=h;
    }
    float area() { return width*height; }
    float getwidth() { return width; }
    float getheight() { return height; }
};

class rectangle_demo
{
    public:
    rectangle_demo()
    {
        rectangle r1;
        float w,h;
        cout<<"enter width\n";
        cin>>w;
        try
        {
            r1.setwidth(w);
            cout<<"width set to "<<r1.getwidth()<<"\n";
        }
        catch(const char* e) { cout<<"error: "<<e<<"\n"; }

        cout<<"enter height\n";
        cin>>h;
        try
        {
            r1.setheight(h);
            cout<<"height set to "<<r1.getheight()<<"\n";
        }
        catch(const char* e) { cout<<"error: "<<e<<"\n"; }

        cout<<"area: "<<r1.area()<<"\n";

        cout<<"\nattempting invariant violations\n";
        try { r1.setwidth(-5); }
        catch(const char* e) { cout<<"caught: "<<e<<"\n"; }

        try { r1.setheight(0); }
        catch(const char* e) { cout<<"caught: "<<e<<"\n"; }

        cout<<"width still: "<<r1.getwidth()<<"\n";
        cout<<"height still: "<<r1.getheight()<<"\n";
    }
};

int main()
{
    rectangle_demo r1;
}
