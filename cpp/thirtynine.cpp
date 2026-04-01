#include<iostream>
#include<string>
#include<cassert>

using namespace std;

struct log_record
{
    string file;
    int line;
    string func;
    string message;
};

log_record make_record(const char* file, int line, const char* func, const string& message)
{
    log_record r;
    r.file=file;
    r.line=line;
    r.func=func;
    r.message=message;

    cout<<"LOG "<<r.file<<":"<<r.line<<" "<<r.func<<"() - "<<r.message<<"\n";
    return r;
}

#define LOG(msg) make_record(__FILE__, __LINE__, __func__, (msg))

class logger_demo
{
    public:
    void func1()
    {
        int expected=__LINE__+1;
        log_record r=LOG("from func1");
        assert(r.line==expected);
        assert(r.func=="func1");
    }

    void func2()
    {
        int expected=__LINE__+1;
        log_record r=LOG("from func2");
        assert(r.line==expected);
        assert(r.func=="func2");
    }

    logger_demo()
    {
        func1();
        func2();

        int expected=__LINE__+1;
        log_record r=LOG("from constructor");
        assert(r.line==expected);
        assert(r.func=="logger_demo");

        cout<<"line/function asserts passed\n";
    }
};

int main()
{
    logger_demo l1;
}
