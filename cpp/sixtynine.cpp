#include<iostream>
#include<vector>

using namespace std;

template<class T>
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

    int rows() const { return r; }
    int cols() const { return c; }

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
        {
            for(int k=0;k<c;k++)
            {
                for(int j=0;j<other.c;j++)
                {
                    res.at(i,j)=res.at(i,j) + at(i,k)*other.at(k,j);
                }
            }
        }
        return res;
    }

    void print() const
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++) cout<<at(i,j)<<" ";
            cout<<"\n";
        }
    }
};

class matrix_demo
{
    public:
    matrix_demo()
    {
        Matrix<int> m1(2,2,0);
        Matrix<int> m2(2,2,0);

        m1.at(0,0)=1; m1.at(0,1)=2;
        m1.at(1,0)=3; m1.at(1,1)=4;

        m2.at(0,0)=5; m2.at(0,1)=6;
        m2.at(1,0)=7; m2.at(1,1)=8;

        cout<<"m1\n";
        m1.print();
        cout<<"m2\n";
        m2.print();

        cout<<"m1+m2\n";
        (m1+m2).print();

        cout<<"m1*m2\n";
        (m1*m2).print();
    }
};

int main()
{
    matrix_demo m1;
}
