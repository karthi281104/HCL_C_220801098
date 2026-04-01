#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int d): data(d), next(NULL) {}
};

node* create_list(int n)
{
    if(n<=0) return NULL;
    node *head=new node(1);
    node *cur=head;
    for(int i=2;i<=n;i++)
    {
        cur->next=new node(i);
        cur=cur->next;
    }
    return head;
}

void print_list(node *head)
{
    node *cur=head;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<"\n";
}

node* get_node_at(node *head, int pos)
{
    int i=1;
    node *cur=head;
    while(cur && i<pos)
    {
        cur=cur->next;
        i++;
    }
    return cur;
}

bool detect_and_remove_cycle(node *head)
{
    node *slow=head;
    node *fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }

    if(!fast || !fast->next) return false;

    slow=head;
    node *prev=NULL;
    while(slow!=fast)
    {
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }

    // now slow==fast is start of loop, prev is last node in loop
    if(prev) prev->next=NULL;
    return true;
}

void free_list(node *head)
{
    while(head)
    {
        node *t=head;
        head=head->next;
        delete t;
    }
}

class cycle_demo
{
    public:
    cycle_demo()
    {
        int n;
        cout<<"enter number of nodes\n";
        cin>>n;

        node *head=create_list(n);
        cout<<"list created\n";

        int pos;
        cout<<"enter position to create cycle (0 for no cycle)\n";
        cin>>pos;

        if(pos>0)
        {
            node *last=head;
            while(last && last->next) last=last->next;
            node *join=get_node_at(head,pos);
            if(last && join)
            {
                last->next=join;
                cout<<"cycle created at position "<<pos<<"\n";
            }
            else
            {
                cout<<"invalid position, no cycle created\n";
            }
        }

        bool removed=detect_and_remove_cycle(head);
        cout<<"cycle present? "<<(removed ? "yes (removed)" : "no")<<"\n";

        cout<<"list after remove\n";
        print_list(head);
        free_list(head);
    }
};

int main()
{
    cycle_demo c1;
}
