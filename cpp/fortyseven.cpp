#include<iostream>
#include<stdexcept>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

bool is_leap(int y)
{
    return (y%400==0) || (y%4==0 && y%100!=0);
}

int days_in_month(int m, int y)
{
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
    if(m==4 || m==6 || m==9 || m==11) return 30;
    if(m==2) return is_leap(y) ? 29 : 28;
    return 0;
}

Date create_date(int d, int m, int y)
{
    if(y<1) throw invalid_argument("invalid year");
    if(m<1 || m>12) throw invalid_argument("invalid month");

    int dim=days_in_month(m,y);
    if(d<1 || d>dim) throw invalid_argument("invalid day");

    Date dt;
    dt.day=d;
    dt.month=m;
    dt.year=y;
    return dt;
}

class date_demo
{
    public:
    date_demo()
    {
        int d,m,y;
        cout<<"enter day month year\n";
        cin>>d>>m>>y;

        try
        {
            Date dt=create_date(d,m,y);
            cout<<"valid date: "<<dt.day<<"/"<<dt.month<<"/"<<dt.year<<"\n";
        }
        catch(invalid_argument &e)
        {
            cout<<"error: "<<e.what()<<"\n";
        }
    }
};

int main()
{
    date_demo d1;
}
