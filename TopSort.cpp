#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int vis[100];
vector<int> adj[100];

void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        vis[i]=0;
    }
}

void dfs(int val)
{
    vis[val]=1;
    for(int i=0;i<adj[val].size();i++)
    {
        int child=adj[val][i];
        if(!vis[child])
        {
            dfs(child);
        }
    }
    v.push_back(val);
}

vector<int> topsort()
{
    vector<int> temp;
    int k=v.size();
    for(int i=k-1;i>=0;i--)
    {
        temp.push_back(v[i]);
    }
    return temp;
}

int main()
{
    int node,edge;
    init(node);
    cout<<"Enter total node: ";
    cin>>node;
    cout<<"Enter total edge: ";
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b;

        cin>>a>>b;
        cout<<"From "<<a<<" To "<<b<<endl;

        adj[a].push_back(b);
    }
    for(int i=1;i<=node;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }

    vector<int> ans;

    ans=topsort();
    cout<<"After topological sorting: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}



