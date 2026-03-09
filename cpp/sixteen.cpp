#include<iostream>
#include<cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

class distance_calc
{
    public:
    double distance(double x1, double y1, double x2, double y2)
    {
        return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    double distance(point p1, point p2)
    {
        return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
    }
    double distance(point p)
    {
        return sqrt(p.x*p.x+p.y*p.y);
    }
    distance_calc()
    {
        cout<<"distance between coordinates (1,2) and (4,6): "<<distance(1,2,4,6)<<"\n";

        point p1,p2;
        cout<<"enter first point x y\n";
        cin>>p1.x>>p1.y;
        cout<<"enter second point x y\n";
        cin>>p2.x>>p2.y;
        cout<<"distance between two points: "<<distance(p1,p2)<<"\n";
        cout<<"distance of first point from origin: "<<distance(p1)<<"\n";
    }
};

int main()
{
    distance_calc d1;
}
