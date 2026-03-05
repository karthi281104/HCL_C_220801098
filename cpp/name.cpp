#include<iostream>


using namespace std;

namespace var
{
    class str
    {
        public:
            int a;
        str(int b)
        {
            a=b;
        }
    };

    struct student
    {
        int roll;
    }s5;
    
    namespace inside_var
    {
        class employee
        {
            public:
                int emp_id;
            employee(int emp)
            {
                emp_id;
            }
        }
    }


}

int main()
{
    var::str s1(5);
    var::s5.roll=200;
    cout<<s1.a;
    cin.ignore();
    cout<<var::s5.roll;
}