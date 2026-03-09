#include<iostream>

using namespace std;

class rectangle
{
    float width;
    float height;
    public:
    void setwidth(float w)
    {
        if(w<=0)
        {
            cout<<"invalid width "<<w<<" clamped to 1\n";
            width=1;
        }
        else
        {
            width=w;
        }
    }
    void setheight(float h)
    {
        if(h<=0)
        {
            cout<<"invalid height "<<h<<" clamped to 1\n";
            height=1;
        }
        else
        {
            height=h;
        }
    }
    float getwidth() { return width; }
    float getheight() { return height; }
    float area() { return width*height; }
    rectangle()
    {
        float w,h;
        cout<<"enter width\n";
        cin>>w;
        setwidth(w);
        cout<<"enter height\n";
        cin>>h;
        setheight(h);
        cout<<"width: "<<width<<" height: "<<height<<"\n";
        cout<<"area: "<<area()<<"\n";

        cout<<"\nattempting to violate constraints\n";
        setwidth(-10);
        setheight(0);
        cout<<"width after invalid set: "<<width<<"\n";
        cout<<"height after invalid set: "<<height<<"\n";
        cout<<"area after invalid set: "<<area()<<"\n";
    }
};

int main()
{
    rectangle r1;
}
