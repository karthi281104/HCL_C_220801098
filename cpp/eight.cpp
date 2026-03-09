#include<iostream>

using namespace std;

struct customer
{
    string name;
    string email;
    string phone;
};

struct order
{
    int order_id;
    string product;
    int quantity;
    float price;
    customer cust;
};

class order_display
{
    public:
    order_display()
    {
        order o1;
        cout<<"enter order id\n";
        cin>>o1.order_id;
        cout<<"enter product name\n";
        cin>>o1.product;
        cout<<"enter quantity\n";
        cin>>o1.quantity;
        cout<<"enter price\n";
        cin>>o1.price;
        cout<<"enter customer name\n";
        cin>>o1.cust.name;
        cout<<"enter customer email\n";
        cin>>o1.cust.email;
        cout<<"enter customer phone\n";
        cin>>o1.cust.phone;
        cout<<"\norder details\n";
        cout<<"order id: "<<o1.order_id<<"\n";
        cout<<"product: "<<o1.product<<"\n";
        cout<<"quantity: "<<o1.quantity<<"\n";
        cout<<"price: "<<o1.price<<"\n";
        cout<<"customer name: "<<o1.cust.name<<"\n";
        cout<<"customer email: "<<o1.cust.email<<"\n";
        cout<<"customer phone: "<<o1.cust.phone<<"\n";
    }
};

int main()
{
    order_display o1;
}
