#include<iostream>

using namespace std;

class box
{
    float length;
    float width;
    float height;
    public:
    box(float l, float w, float h)
    {
        length=l;
        width=w;
        height=h;
        cout<<"box constructor called: "<<l<<"x"<<w<<"x"<<h<<"\n";
    }
    float volume()
    {
        return length*width*height;
    }
    ~box()
    {
        cout<<"box destructor called: "<<length<<"x"<<width<<"x"<<height<<"\n";
    }
};

int main()
{
    cout<<"creating box with new\n";
    box *b1=new box(3,4,5);
    cout<<"volume: "<<b1->volume()<<"\n";
    cout<<"deleting box\n";
    delete b1;
}
