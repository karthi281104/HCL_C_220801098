#include<iostream>

using namespace std;

class menu
{
    public:
    menu()
    {
        int choice;
        do
        {
            cout<<"1. add\n";
            cout<<"2. subtract\n";
            cout<<"3. multiply\n";
            cout<<"4. divide\n";
            cout<<"5. exit\n";
            cout<<"enter your choice\n";
            cin>>choice;
            int a,b;
            if(choice>=1 && choice<=4)
            {
                cout<<"enter two numbers\n";
                cin>>a>>b;
            }
            switch(choice)
            {
                case 1: cout<<"result: "<<a+b<<"\n"; break;
                case 2: cout<<"result: "<<a-b<<"\n"; break;
                case 3: cout<<"result: "<<a*b<<"\n"; break;
                case 4:
                    if(b==0) cout<<"cannot divide by zero\n";
                    else cout<<"result: "<<a/b<<"\n";
                    break;
                case 5: cout<<"exiting...\n"; break;
                default: cout<<"invalid choice\n";
            }
        }while(choice!=5);
    }
};

int main()
{
    menu m1;
}
