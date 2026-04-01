#include<iostream>
#include<string>

using namespace std;

class Logger
{
    Logger() {}

    public:
    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }

    void logMessage(const string& msg)
    {
        cout<<"log: "<<msg<<"\n";
    }

    Logger(const Logger&)=delete;
    Logger& operator=(const Logger&)=delete;
};

class singleton_demo
{
    public:
    singleton_demo()
    {
        Logger::getInstance().logMessage("application started");
        Logger::getInstance().logMessage("doing work");
        Logger::getInstance().logMessage("application finished");
    }
};

int main()
{
    singleton_demo s1;
}
