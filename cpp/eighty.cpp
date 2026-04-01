#include<iostream>
#include<string>

using namespace std;

class Shape
{
    public:
    virtual ~Shape() {}
    virtual double area() const =0;
    virtual string type() const =0;
};

class Circle : public Shape
{
    double r;

    public:
    Circle(double radius): r(radius) {}
    double area() const override { return 3.14159 * r * r; }
    string type() const override { return "Circle"; }
};

class Rectangle : public Shape
{
    double w;
    double h;

    public:
    Rectangle(double a, double b): w(a), h(b) {}
    double area() const override { return w*h; }
    string type() const override { return "Rectangle"; }
};

Shape* createShape(const string& name)
{
    if(name=="circle")
    {
        double r;
        cout<<"enter radius\n";
        cin>>r;
        return new Circle(r);
    }
    if(name=="rectangle")
    {
        double w,h;
        cout<<"enter width height\n";
        cin>>w>>h;
        return new Rectangle(w,h);
    }

    return NULL;
}

class factory_demo
{
    public:
    factory_demo()
    {
        string name;
        cout<<"enter shape (circle/rectangle)\n";
        cin>>name;

        Shape *s=createShape(name);
        if(!s)
        {
            cout<<"unknown shape\n";
            return;
        }

        cout<<"shape: "<<s->type()<<" area: "<<s->area()<<"\n";
        delete s;
    }
};

int main()
{
    factory_demo f1;
}
