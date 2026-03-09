#include<iostream>

using namespace std;

class wallet
{
    float balance;
    friend class walletauditor;
    public:
    wallet(float initial)
    {
        if(initial<0)
        {
            cout<<"invalid initial balance\n";
            balance=0;
        }
        else
        {
            balance=initial;
        }
    }
    void deposit(float amount)
    {
        if(amount<=0) { cout<<"invalid deposit amount\n"; return; }
        balance+=amount;
        cout<<"deposited "<<amount<<" balance: "<<balance<<"\n";
    }
    void withdraw(float amount)
    {
        if(amount<=0) { cout<<"invalid withdraw amount\n"; return; }
        if(amount>balance) { cout<<"insufficient funds\n"; return; }
        balance-=amount;
        cout<<"withdrawn "<<amount<<" balance: "<<balance<<"\n";
    }
};

class walletauditor
{
    public:
    void report(const wallet &w)
    {
        cout<<"audit report: balance="<<w.balance<<"\n";
    }
};

// class thirdclass
// {
//     public:
//     void snoop(const wallet &w)
//     {
//         cout<<w.balance; // error: balance is private
//         // friendship is not transitive - thirdclass cannot access wallet
//     }
// };

class wallet_demo
{
    public:
    wallet_demo()
    {
        wallet w1(100);
        w1.deposit(50);
        w1.withdraw(30);
        w1.deposit(-10);
        w1.withdraw(999);

        walletauditor a1;
        a1.report(w1);
    }
};

int main()
{
    wallet_demo w1;
}
