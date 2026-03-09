#include<iostream>
#include<cmath>

using namespace std;

class mathops
{
    public:
    int pow(int base, int exp)
    {
        int result=1;
        for(int i=0;i<exp;i++) result*=base;
        return result;
    }
    double pow(double base, double exp)
    {
        return ::pow(base,exp);
    }
};

class func
{
    public:
    virtual double evaluate(double x)
    {
        return x;
    }
    virtual ~func(){}
};

class square_func: public func
{
    public:
    double evaluate(double x) { return x*x; }
};

class cube_func: public func
{
    public:
    double evaluate(double x) { return x*x*x; }
};

class mathops_demo
{
    public:
    mathops_demo()
    {
        mathops m;
        cout<<"compile time resolution (overloading)\n";
        cout<<"pow(2,10) int version: "<<m.pow(2,10)<<"\n";
        cout<<"pow(2.0,0.5) double version: "<<m.pow(2.0,0.5)<<"\n";

        cout<<"\nruntime resolution (overriding)\n";
        func *f1=new square_func();
        func *f2=new cube_func();
        cout<<"square of 4: "<<f1->evaluate(4)<<"\n";
        cout<<"cube of 3: "<<f2->evaluate(3)<<"\n";
        delete f1;
        delete f2;
    }
};

int main()
{
    mathops_demo m1;
}
