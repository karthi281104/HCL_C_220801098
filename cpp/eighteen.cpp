#include<iostream>

using namespace std;

struct meters
{
    double value;
    meters(double v): value(v){}
};

struct seconds
{
    double value;
    seconds(double v): value(v){}
};

struct meterspersecond
{
    double value;
    meterspersecond(double v): value(v){}
};

meterspersecond operator/(meters m, seconds s)
{
    return meterspersecond(m.value/s.value);
}

// meters operator/(meters m, meterspersecond s) omitted - incompatible
// seconds operator/(seconds s, meters m) omitted - incompatible

class units_demo
{
    public:
    units_demo()
    {
        double d,t;
        cout<<"enter distance in meters\n";
        cin>>d;
        cout<<"enter time in seconds\n";
        cin>>t;
        meters m(d);
        seconds s(t);
        meterspersecond speed=m/s;
        cout<<"speed: "<<speed.value<<" m/s\n";

        meters m2(200);
        seconds s2(8);
        meterspersecond speed2=m2/s2;
        cout<<"200m / 8s = "<<speed2.value<<" m/s\n";
    }
};

int main()
{
    units_demo u1;
}
