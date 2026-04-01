#include<iostream>
#include<cstdint>

using namespace std;

class reinterpret_demo
{
    public:
    reinterpret_demo()
    {
        uintptr_t addr=0x1234; // fake address
        int *p=reinterpret_cast<int*>(addr);

        cout<<"integer address: 0x"<<hex<<addr<<dec<<"\n";
        cout<<"pointer value  : "<<p<<"\n";

        cout<<"not dereferencing this pointer\n";
        cout<<"reason: address may be invalid or not mapped -> crash/UB\n";
        cout<<"also on 64-bit, converting from smaller integer types can truncate\n";
    }
};

int main()
{
    reinterpret_demo r1;
}
