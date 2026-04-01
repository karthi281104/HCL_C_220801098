#include<iostream>
#include<vector>

using namespace std;

class tree_diameter
{
    vector<vector<int>> g;
    int diameter;

    int dfs(int u, int p)
    {
        int best1=0;
        int best2=0;

        for(int v: g[u])
        {
            if(v==p) continue;
            int h=dfs(v,u)+1;
            if(h>best1)
            {
                best2=best1;
                best1=h;
            }
            else if(h>best2)
            {
                best2=h;
            }
        }

        if(best1+best2>diameter) diameter=best1+best2;
        return best1;
    }

    public:
    tree_diameter()
    {
        int n;
        cout<<"enter number of nodes\n";
        cin>>n;

        g.assign(n+1, vector<int>());
        cout<<"enter "<<(n-1)<<" edges (u v)\n";
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        diameter=0;
        dfs(1,0);
        cout<<"tree diameter (edges): "<<diameter<<"\n";
    }
};

int main()
{
    tree_diameter t1;
}
