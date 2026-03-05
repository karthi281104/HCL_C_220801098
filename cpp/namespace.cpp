#include<iostream>


using namespace std;

namespace company
{
    namespace hr
    {
        void policies()
        {
            cout<<"hr company policies";
        }
    }
    namespace accounts{
    void policies()
        {
            cout<<"company policies";
        }
    }

}
using namespace company::accounts;


int main()
{
     policies();
    // accounts::policies();
    
}