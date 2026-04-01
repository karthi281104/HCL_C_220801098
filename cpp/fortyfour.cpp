#include<iostream>
#include<string>

using namespace std;

class Shape
{
    public:
    virtual ~Shape()
    {
        cout<<"Shape destructor\n";
    }

    virtual string type() const
    {
        return "Shape";
    }
};

class Circle : public Shape
{
    double r;

    public:
    Circle(double radius): r(radius) {}

    string type() const override
    {
        return "Circle";
    }

    double radius() const
    {
        return r;
    }

    ~Circle() override
    {
        cout<<"Circle destructor\n";
    }
};

class Rectangle : public Shape
{
    public:
    string type() const override
    {
        return "Rectangle";
    }

    ~Rectangle() override
    {
        cout<<"Rectangle destructor\n";
    }
};

class cast_demo
{
    public:
    cast_demo()
    {
        Shape *s1=new Circle(5.5);
        Shape *s2=new Rectangle();

        cout<<"s1 type: "<<s1->type()<<"\n";
        cout<<"s2 type: "<<s2->type()<<"\n";

        Circle *c1=dynamic_cast<Circle*>(s1);
        if(c1) cout<<"downcast s1 -> Circle ok, radius="<<c1->radius()<<"\n";
        else cout<<"downcast s1 -> Circle failed\n";

        Circle *c2=dynamic_cast<Circle*>(s2);
        if(c2) cout<<"downcast s2 -> Circle ok (unexpected)\n";
        else cout<<"downcast s2 -> Circle failed safely (nullptr)\n";

        delete s1;
        delete s2;
    }
};

int main()
{
    cast_demo c1;
}
