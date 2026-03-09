#include<iostream>
#include<fstream>

using namespace std;

class file_demo
{
    public:
    file_demo()
    {
        ofstream fout("twenty9.txt");
        if(!fout.is_open())
        {
            cout<<"failed to open file for writing\n";
            return;
        }
        fout<<"hello world\n";
        fout<<"this is a test file\n";
        fout<<"written from c++\n";
        fout.close();
        cout<<"file written and closed\n";

        ifstream fin("twenty9.txt");
        if(!fin.is_open())
        {
            cout<<"failed to open file for reading\n";
            return;
        }
        cout<<"reading file content\n";
        string line;
        while(getline(fin,line))
        {
            cout<<line<<"\n";
        }
        fin.close();
        cout<<"file read and closed\n";
    }
};

int main()
{
    file_demo f1;
}
