#include<iostream>

using namespace std;

float add(float a, float b) { return a+b; }
float subtract(float a, float b) { return a-b; }
float multiply(float a, float b) { return a*b; }
float divide(float a, float b)
{
    if(b==0) { cout<<"cannot divide by zero\n"; return 0; }
    return a/b;
}

class func_pointer_calc
{
    public:
    func_pointer_calc()
    {
        float (*operations[4])(float,float)={add,subtract,multiply,divide};
        int choice;
        float a,b;
        do
        {
            cout<<"1. add\n";
            cout<<"2. subtract\n";
            cout<<"3. multiply\n";
            cout<<"4. divide\n";
            cout<<"5. exit\n";
            cout<<"enter your choice\n";
            cin>>choice;
            if(choice>=1 && choice<=4)
            {
                cout<<"enter two numbers\n";
                cin>>a>>b;
                cout<<"result: "<<operations[choice-1](a,b)<<"\n";
            }
            else if(choice!=5)
            {
                cout<<"invalid choice\n";
            }
        }while(choice!=5);
        cout<<"exiting...\n";
    }
};

int main()
{
    func_pointer_calc f1;
}
