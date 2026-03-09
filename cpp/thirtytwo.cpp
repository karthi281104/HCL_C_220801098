#include<iostream>
#include<fstream>

using namespace std;

class file_division
{
    public:
    file_division()
    {
        ofstream fout("numbers.txt");
        if(!fout.is_open()) throw "failed to create numbers file";
        fout<<"100\n"<<"50\n"<<"0\n"<<"25\n";
        fout.close();

        ifstream fin("numbers.txt");
        if(!fin.is_open()) throw "failed to open numbers file";

        int a,b;
        while(fin>>a>>b)
        {
            try
            {
                if(b==0) throw "division by zero";
                cout<<a<<"/"<<b<<"="<<a/b<<"\n";
            }
            catch(const char* e)
            {
                cout<<"math error: "<<e<<" (a="<<a<<" b="<<b<<")\n";
            }
        }
        fin.close();
    }
};

int main()
{
    try
    {
        file_division f1;
    }
    catch(const char* e)
    {
        cout<<"file error: "<<e<<"\n";
    }
}
