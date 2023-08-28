#include<bits/stdc++.h>
using namespace std;


int par[1000];
struct edge
{
    int u,v,w;
};

bool compare(edge a,edge b)
{
    return (a.w<b.w);
}




vector<edge> e;
int find_set(int v)
{
    if (v== par[v])
        return v;
    return par[v] = find_set(par[v]);
}



int kruskal(int n)
{
    sort(e.begin(), e.end(),compare);
    //nijeke nijer parent banano
    for (int i = 0; i <= n; i++)
        par[i] = i;

    int cc = 0, totalcost = 0;

    for (int i = 0; i < e.size(); i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if (u != v)
        {
            par[u] = v;
            cc++;
            totalcost += e[i].w;
            if (cc == n-1)
                break;
        }
    }
    return totalcost;
}





int main()
{

    int nodes,edges;
    cin>>nodes>>edges;
    e.clear();
    for(int i=1;i<=edges;i++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        edge get;
        get.u=a;
        get.v=b;
        get.w=cost;
        e.push_back(get);
    }
    cout<<kruskal(nodes)<<endl;


    return 0;
}


