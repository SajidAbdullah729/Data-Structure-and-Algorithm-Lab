#include<bits/stdc++.h>
using namespace std;

struct P
{
    int cost,node;
};
int cost[1010];
int parent[1010];
bool vis[1010];
const int INF=1000000;
vector<pair<int,int> > adj[1010];
struct compare
{
    bool operator()(P const&p1, P const& p2)
    {
        return p1.cost > p2.cost;
    }
};
int ans=0;

void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        cost[i]=INF;
        parent[i]=-INF;
        vis[i]=0;
    }
}
void prims(int n,int source)
{
    init(n);
    priority_queue<P,vector<P>,compare> pq;
    P nisi;
    cost[source]=0;
    nisi.cost= 0;
    nisi.node= 1;
    pq.push(nisi);

    while(!pq.empty())
    {
        int nilam=pq.top().node;
        pq.pop();

        if(vis[nilam]) continue;
        vis[nilam]=1;
        for(int i=0; i<adj[nilam].size(); i++)
        {
            int child=adj[nilam][i].first;
            int jawarcost=adj[nilam][i].second;
            if(!vis[child] && cost[child]> jawarcost )
            {
                cost[child]=jawarcost;
                P aa;
                aa.cost=jawarcost;
                aa.node=child;
                pq.push(aa);
                parent[child]=nilam;
            }
        }


    }

}


int main()
{

    int n,m,source;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,cc;
        cin>>a>>b>>cc;
        adj[a].push_back(make_pair(b,cc));
        adj[b].push_back(make_pair(a,cc));
    }
    cout<<"Source:"<<endl;
    cin>>source;
    prims(n,source);


    for(int i=1;i<=n;i++) ans+=cost[i];
    cout<<ans<<endl;
    return 0;
}
