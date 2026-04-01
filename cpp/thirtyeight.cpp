#include<iostream>
#include<cassert>

using namespace std;

// BAD macro (no parentheses): demonstrates SQR(a+b) bug
#define SQR_BAD(x) x * x

// Fixed macro
#define SQR(x) ((x) * (x))

inline int sqr_inline(int x)
{
    return x * x;
}

class sqr_demo
{
    public:
    sqr_demo()
    {
        int a=2;
        int b=3;

        cout<<"a="<<a<<" b="<<b<<"\n";

        int bad=SQR_BAD(a+b);
        int good=SQR(a+b);
        int inl=sqr_inline(a+b);

        cout<<"SQR_BAD(a+b) = "<<bad<<" (BUG)\n";
        cout<<"SQR(a+b)     = "<<good<<"\n";
        cout<<"inline sqr   = "<<inl<<"\n";

        // Simple "unit test" using asserts
        assert(bad != good);
        assert(good == (a+b)*(a+b));
        assert(inl == good);

        cout<<"asserts passed\n";
    }
};

int main()
{
    sqr_demo s1;
}
