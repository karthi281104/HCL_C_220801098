#include<iostream>
#include<string>
#include<type_traits>

using namespace std;

template<class T>
struct Vector2
{
    static_assert(is_arithmetic<T>::value, "Vector2 supports only numeric types");

    T x;
    T y;

    Vector2(T a=T(), T b=T()): x(a), y(b) {}

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x+other.x, y+other.y);
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x-other.x, y-other.y);
    }

    Vector2 operator*(T scalar) const
    {
        return Vector2(x*scalar, y*scalar);
    }
};

template<class T>
void print_vec(const Vector2<T>& v)
{
    cout<<"("<<v.x<<","<<v.y<<")";
}

class vector_demo
{
    public:
    vector_demo()
    {
        Vector2<int> a(1,2);
        Vector2<int> b(3,4);
        Vector2<int> c=a+b;
        Vector2<int> d=b-a;
        Vector2<int> e=a*10;

        cout<<"int vectors\n";
        print_vec(c); cout<<"\n";
        print_vec(d); cout<<"\n";
        print_vec(e); cout<<"\n\n";

        Vector2<float> f1(1.5f,2.5f);
        Vector2<float> f2(0.5f,1.0f);
        cout<<"float vectors\n";
        print_vec(f1+f2); cout<<"\n";

        Vector2<double> d1(2.0,3.0);
        cout<<"double scalar multiply\n";
        print_vec(d1*0.25); cout<<"\n";

        // Vector2<string> s("a","b"); // will not compile due to static_assert
    }
};

int main()
{
    vector_demo v1;
}
