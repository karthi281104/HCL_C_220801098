#include<iostream>
#include<fstream>

using namespace std;

class line_counter
{
    public:
    line_counter()
    {
        string filename;
        cout<<"enter filename\n";
        cin>>filename;

        ifstream fin(filename);
        if(!fin.is_open())
        {
            cout<<"failed to open file\n";
            return;
        }
        int count=0;
        string line;
        while(getline(fin,line)) count++;
        fin.close();
        cout<<"total lines: "<<count<<"\n";

        fstream fs(filename,ios::app);
        if(!fs.is_open())
        {
            cout<<"failed to open file for appending\n";
            return;
        }
        fs<<"total lines: "<<count<<"\n";
        fs.close();
        cout<<"appended total lines to file\n";

        ifstream fin2(filename);
        cout<<"file content after append\n";
        while(getline(fin2,line)) cout<<line<<"\n";
        fin2.close();
    }
};

int main()
{
    line_counter l1;
}
