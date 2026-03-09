#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class file_opener
{
    public:
    void openfile(string filename)
    {
        ifstream fin(filename);
        if(!fin.is_open()) throw string("cannot open file: "+filename);
        cout<<"file opened successfully\n";
        string line;
        while(getline(fin,line)) cout<<line<<"\n";
        fin.close();
    }
    file_opener()
    {
        string filename;
        cout<<"enter filename\n";
        cin>>filename;
        try
        {
            openfile(filename);
        }
        catch(string e)
        {
            cout<<"error: "<<e<<"\n";
        }
    }
};

int main()
{
    file_opener f1;
}
