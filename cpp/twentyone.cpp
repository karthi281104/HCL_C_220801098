#include<iostream>
#include<cstdlib>

using namespace std;

class media
{
    public:
    virtual void play()
    {
        cout<<"playing media\n";
    }
    virtual ~media()
    {
        cout<<"media destroyed\n";
    }
};

class audio: public media
{
    public:
    void play()
    {
        cout<<"playing audio\n";
    }
    ~audio()
    {
        cout<<"audio destroyed\n";
    }
};

class video: public media
{
    public:
    void play()
    {
        cout<<"playing video\n";
    }
    ~video()
    {
        cout<<"video destroyed\n";
    }
};

class media_demo
{
    public:
    media_demo()
    {
        int n=4;
        media **arr=(media**)malloc(n*sizeof(media*));
        arr[0]=new audio();
        arr[1]=new video();
        arr[2]=new video();
        arr[3]=new audio();

        cout<<"playing all media\n";
        for(int i=0;i<n;i++) arr[i]->play();

        cout<<"\ndestructing\n";
        for(int i=0;i<n;i++) delete arr[i];
        free(arr);
    }
};

int main()
{
    media_demo m1;
}
