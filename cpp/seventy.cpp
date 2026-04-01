#include<iostream>
#include<vector>
#include<concepts>

using namespace std;

template<class T>
concept MulAddClosed = requires(T a, T b)
{
    { a + b } -> same_as<T>;
    { a * b } -> same_as<T>;
};

template<MulAddClosed T>
class Matrix
{
    int r;
    int c;
    vector<vector<T>> a;

    public:
    Matrix(int rows=0, int cols=0, T init=T()): r(rows), c(cols)
    {
        a.assign(r, vector<T>(c, init));
    }

    T& at(int i, int j) { return a[i][j]; }
    const T& at(int i, int j) const { return a[i][j]; }

    Matrix operator+(const Matrix& other) const
    {
        Matrix res(r,c);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                res.at(i,j)=at(i,j)+other.at(i,j);
        return res;
    }

    Matrix operator*(const Matrix& other) const
    {
        Matrix res(r, other.c, T());
        for(int i=0;i<r;i++)
            for(int k=0;k<c;k++)
                for(int j=0;j<other.c;j++)
                    res.at(i,j)=res.at(i,j) + at(i,k)*other.at(k,j);
        return res;
    }
};

class concept_demo
{
    public:
    concept_demo()
    {
        Matrix<int> m(1,1,0);
        m.at(0,0)=7;
        Matrix<int> n(1,1,0);
        n.at(0,0)=3;
        auto p=m+n;
        auto q=m*n;
        cout<<"m+n="<<p.at(0,0)<<"\n";
        cout<<"m*n="<<q.at(0,0)<<"\n";

        // Matrix<string> s(1,1,string("a")); // does not satisfy concept (compile error)
    }
};

int main()
{
    concept_demo c1;
}
