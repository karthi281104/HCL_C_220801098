#include<iostream>
#include<string>

using namespace std;

#define STR2(x) #x
#define STR(x) STR2(x)

string compiler_version()
{
#ifdef __clang__
    return string("Clang ") + STR(__clang_major__) + "." + STR(__clang_minor__) + "." + STR(__clang_patchlevel__);
#elif defined(__GNUC__)
    return string("GCC ") + STR(__GNUC__) + "." + STR(__GNUC_MINOR__) + "." + STR(__GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
    return string("MSVC ") + STR(_MSC_VER);
#else
    return "Unknown compiler";
#endif
}

#define ASSERT_WITH_LOC(cond) do { \
    if(!(cond)) { \
        cout<<"assert failed at "<<__FILE__<<":"<<__LINE__<<"\n"; \
        throw "assert failed"; \
    } \
} while(0)

class version_demo
{
    public:
    version_demo()
    {
        cout<<"compiler: "<<compiler_version()<<"\n";
        cout<<"location: "<<__FILE__<<":"<<__LINE__<<"\n";

        try
        {
            ASSERT_WITH_LOC(1==1);
            cout<<"assert ok\n";
        }
        catch(const char* e)
        {
            cout<<"caught: "<<e<<"\n";
        }
    }
};

int main()
{
    version_demo v1;
}
