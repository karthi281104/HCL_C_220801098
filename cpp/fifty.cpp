#include<iostream>

using namespace std;

struct flags
{
    unsigned isAdmin:1;
    unsigned isActive:1;
    unsigned isVerified:1;
    unsigned isBlocked:1;
};

class bitfield_demo
{
    public:
    bitfield_demo()
    {
        flags f;
        f.isAdmin=1;
        f.isActive=1;
        f.isVerified=0;
        f.isBlocked=0;

        cout<<"isAdmin: "<<f.isAdmin<<"\n";
        cout<<"isActive: "<<f.isActive<<"\n";
        cout<<"isVerified: "<<f.isVerified<<"\n";
        cout<<"isBlocked: "<<f.isBlocked<<"\n";

        f.isVerified=1;
        cout<<"after verify, isVerified: "<<f.isVerified<<"\n";
    }
};

int main()
{
    bitfield_demo b1;
}
