#include<iostream>
#include<cstdlib>

using namespace std;

class printdiag_demo
{
    public:
    void printdiag(int val)
    {
        cout<<"int: "<<val<<"\n";
    }
    void printdiag(double val)
    {
        cout<<"double: "<<val<<"\n";
    }
    void printdiag(string val)
    {
        cout<<"string: "<<val<<"\n";
    }
    void printdiag(int *arr, int n)
    {
        cout<<"vector of ints: ";
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    printdiag_demo()
    {
        printdiag(42);
        printdiag(3.14);
        printdiag("hello world");

        int n=5;
        int *arr=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++) arr[i]=(i+1)*10;
        printdiag(arr,n);
        free(arr);
    }
};

int main()
{
    printdiag_demo p1;
}
