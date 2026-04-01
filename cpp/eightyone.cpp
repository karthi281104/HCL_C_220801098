#include<iostream>
#include<vector>
#include<string>

using namespace std;

class IObserver
{
    public:
    virtual ~IObserver() {}
    virtual void update(const string& stock, double price)=0;
};

class Stock
{
    string name;
    double price;
    vector<IObserver*> observers;

    public:
    Stock(string n): name(n), price(0.0) {}

    void attach(IObserver* o)
    {
        observers.push_back(o);
    }

    void setPrice(double p)
    {
        price=p;
        for(size_t i=0;i<observers.size();i++)
            observers[i]->update(name, price);
    }
};

class MobileApp : public IObserver
{
    string user;

    public:
    MobileApp(string u): user(u) {}
    void update(const string& stock, double price) override
    {
        cout<<"mobile("<<user<<") update: "<<stock<<" price="<<price<<"\n";
    }
};

class WebApp : public IObserver
{
    string site;

    public:
    WebApp(string s): site(s) {}
    void update(const string& stock, double price) override
    {
        cout<<"web("<<site<<") update: "<<stock<<" price="<<price<<"\n";
    }
};

class observer_demo
{
    public:
    observer_demo()
    {
        Stock s("ACME");
        MobileApp m1("alice");
        MobileApp m2("bob");
        WebApp w1("dashboard");

        s.attach(&m1);
        s.attach(&m2);
        s.attach(&w1);

        cout<<"setting price to 100\n";
        s.setPrice(100);
        cout<<"setting price to 120.5\n";
        s.setPrice(120.5);
    }
};

int main()
{
    observer_demo o1;
}
