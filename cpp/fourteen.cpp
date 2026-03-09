#include<iostream>
#include<initializer_list>

using namespace std;

class matrix
{
    int **data;
    int rows;
    int cols;
    public:
    matrix(int r, int c, initializer_list<int> vals)
    {
        rows=r;
        cols=c;
        data=new int*[rows];
        for(int i=0;i<rows;i++) data[i]=new int[cols];
        int k=0;
        for(int v:vals)
        {
            if(k<rows*cols)
            {
                data[k/cols][k%cols]=v;
                k++;
            }
        }
        cout<<"matrix created ("<<rows<<"x"<<cols<<")\n";
    }
    void display()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++) cout<<data[i][j]<<" ";
            cout<<"\n";
        }
    }
    ~matrix()
    {
        for(int i=0;i<rows;i++) delete[] data[i];
        delete[] data;
        cout<<"matrix destroyed ("<<rows<<"x"<<cols<<")\n";
    }
};

int main()
{
    matrix m1(2,3,{1,2,3,4,5,6});
    m1.display();
    matrix m2(3,3,{10,20,30,40,50,60,70,80,90});
    m2.display();
}
