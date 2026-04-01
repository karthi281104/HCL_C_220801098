#include<iostream>
#include<string>
#include<stack>

using namespace std;

class undo_redo_editor
{
    string text;
    stack<string> undo_stack;
    stack<string> redo_stack;

    void save_for_undo()
    {
        undo_stack.push(text);
        while(!redo_stack.empty()) redo_stack.pop();
    }

    public:
    undo_redo_editor()
    {
        int choice;
        while(true)
        {
            cout<<"\n1.type(char) 2.backspace 3.undo 4.redo 5.print 6.exit\n";
            cin>>choice;

            if(choice==1)
            {
                char ch;
                cout<<"enter char\n";
                cin>>ch;
                save_for_undo();
                text.push_back(ch);
            }
            else if(choice==2)
            {
                save_for_undo();
                if(!text.empty()) text.pop_back();
            }
            else if(choice==3)
            {
                if(undo_stack.empty())
                {
                    cout<<"nothing to undo\n";
                }
                else
                {
                    redo_stack.push(text);
                    text=undo_stack.top();
                    undo_stack.pop();
                }
            }
            else if(choice==4)
            {
                if(redo_stack.empty())
                {
                    cout<<"nothing to redo\n";
                }
                else
                {
                    undo_stack.push(text);
                    text=redo_stack.top();
                    redo_stack.pop();
                }
            }
            else if(choice==5)
            {
                cout<<"text: "<<text<<"\n";
            }
            else if(choice==6)
            {
                break;
            }
            else
            {
                cout<<"invalid choice\n";
            }
        }
    }
};

int main()
{
    undo_redo_editor u1;
}
