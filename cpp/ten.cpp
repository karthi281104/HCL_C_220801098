#include<iostream>
#include<cstdlib>

using namespace std;

class dynamic_array
{
    int *arr;
    int size;
    int capacity;
    public:
    dynamic_array()
    {
        capacity=2;
        size=0;
        arr=(int*)malloc(capacity*sizeof(int));
        cout<<"initial capacity: "<<capacity<<"\n";
    }
    void insert(int val)
    {
        if(size==capacity)
        {
            capacity*=2;
            arr=(int*)realloc(arr,capacity*sizeof(int));
            cout<<"capacity doubled to "<<capacity<<"\n";
        }
        arr[size++]=val;
    }
    void display()
    {
        cout<<"array elements: ";
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    ~dynamic_array()
    {
        free(arr);
    }
};

int main()
{
    dynamic_array d1;
    int n,val;
    cout<<"enter number of elements to insert\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter element "<<i+1<<"\n";
        cin>>val;
        d1.insert(val);
    }
    d1.display();
}
