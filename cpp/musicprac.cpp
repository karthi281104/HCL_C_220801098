#include<iostream>
#include<string>

using namespace std;

class node{
public:
    string song;
    node* next;
    node(string name)
    {
        song=name;
        next=NULL;
    }
};

class playlist
{
    private:
        node* head;
        int size;

    public:
        playlist(){
            head = NULL;
            size=0;
        }

        void insert_beg(string name)
        {
            node* newnode = new node(name);
            newnode->next =head;
            head=newnode;
            size++;
        }

        void insert_end(string name)
        {
            node* newnode = new node(name);
            if(head==NULL)
            {
                head=newnode;
            }
            else{
                node* temp;
                while ((temp->next != NULL))
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                
            }
            size++;

        }

        void insert_pos(string name,int pos)
        {
            if(pos<1 || pos>size+1)
            {
                cout<<"invalid position";
            }
            else
            {
                for (int i = 0; i < pos; i++)
                {
                    
                }
                
            }
        }
};
