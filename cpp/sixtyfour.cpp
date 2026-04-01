#include<iostream>
#include<string>

using namespace std;

namespace Company
{
    namespace HR
    {
        void displayPolicy()
        {
            cout<<"HR Policy: attendance is mandatory\n";
        }
    }
}

int main()
{
    Company::HR::displayPolicy();
}
