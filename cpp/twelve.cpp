#include<iostream>
#include<cstdlib>

using namespace std;

struct lineitem
{
    int id;
    int qty;
};

class order
{
    lineitem *items;
    int size;
    int capacity;
    public:
    order()
    {
        size=0;
        capacity=2;
        items=(lineitem*)malloc(capacity*sizeof(lineitem));
        cout<<"order created\n";
    }
    void addlineitem(int id, int qty)
    {
        if(size==capacity)
        {
            capacity*=2;
            items=(lineitem*)realloc(items,capacity*sizeof(lineitem));
            cout<<"capacity doubled to "<<capacity<<"\n";
        }
        items[size].id=id;
        items[size].qty=qty;
        size++;
        cout<<"added item id "<<id<<" qty "<<qty<<"\n";
    }
    int totalitems()
    {
        int total=0;
        for(int i=0;i<size;i++) total+=items[i].qty;
        return total;
    }
    void print()
    {
        cout<<"\norder summary\n";
        for(int i=0;i<size;i++)
        {
            cout<<"item id: "<<items[i].id<<" qty: "<<items[i].qty<<"\n";
        }
        cout<<"total items: "<<totalitems()<<"\n";
    }
    ~order()
    {
        free(items);
    }
};

int main()
{
    order o1;
    o1.addlineitem(101,3);
    o1.addlineitem(102,5);
    o1.addlineitem(103,2);
    o1.addlineitem(104,7);
    o1.print();
}
