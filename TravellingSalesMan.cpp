
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvll;
const int INF=1000000000;



int row,col;

struct TSP
{
    int cost;
    int nodenum;
    vector<int> path;
    vvll rcl;
};



struct compare
{
    bool operator()(TSP const&p1, TSP const& p2)
    {
        return p1.cost > p2.cost;
    }
};
struct Abar
{
    vvll ar;
    int val;
};


Abar ReducedRow(vvll &a)
{
    vvll arr=a;
    int minarr[row+1];
    int ans=0;
    for(int i=1;i<=row;i++)
    {
        int minn=INF;
        for(int j=1;j<=col;j++)
        {
            if(arr[i][j]<minn)
            {
                minn=min(minn,arr[i][j]);
            }
        }
        minarr[i]=minn;
        if(minn==INF) minarr[i]=0;
        ans+=minarr[i];
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(arr[i][j]!=INF) arr[i][j]-=minarr[i];
        }

    }
    Abar jj;
    jj.ar=arr;
    jj.val=ans;
    return jj;
}

Abar ReducedColumn(vvll &a)
{
     vvll arr=a;
     int ans=0;
    int minarr[col+1];
    for(int j=1;j<=col;j++)
    {
        int minn=INF;
        for(int i=1;i<=row;i++)
        {
            if(arr[i][j]<minn)
            {
                minn=min(minn,arr[i][j]);
            }
        }
        minarr[j]=minn;
        if(minn==INF) minarr[j]=0;
        ans+=minarr[j];
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(arr[i][j]!=INF) arr[i][j]-=minarr[j];
        }

    }
    Abar jj;
    jj.ar=arr;
    jj.val=ans;
    return jj;
}




int main()
{
    int n;
    cin>>n;
    row=n;
    col=n;

    vvll arr(row+2,vector<int>(col+2,0));

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
                cin>>arr[i][j];
        }
    }

    vvll temp=arr;
    for(int i=1;i<=row;i++)
    {
        temp[i][i]=INF;
    }

    priority_queue<TSP,vector<TSP>,compare> pq;
    vector<int> v;
    int c=1;
    int source;
    cout<<"source: ";
    cin>>source;
    v.push_back(source);
    Abar aa=ReducedRow(temp);
    int val=aa.val;
    Abar bb=ReducedColumn(aa.ar);
    val+=bb.val;
    TSP t;
    t.cost=val;
    t.nodenum=c;
    t.path=v;
    t.rcl=bb.ar;
    pq.push(t);
    TSP solve;
    while(!pq.empty())
    {
        TSP h=pq.top();
        if(h.path.size()==row)
        {

            solve.nodenum=h.nodenum;
            solve.cost=h.cost;
            solve.rcl=h.rcl;
            solve.path=h.path;
            break;
        }

        pq.pop();
        vector<int> visited(row+2,0);
        int pathsz=h.path.size();
        for(int i=0;i<pathsz;i++)
        {
            int k=h.path[i];
            visited[k]=1;
        }
        for(int i=1;i<=row;i++)
        {
            if(!visited[i])
            {
                c++;
                TSP notun;
                notun.nodenum=c;
                vector<int> nn;
                nn=h.path;
                nn.push_back(i);

                notun.path=nn;

                vvll tt=h.rcl;

                int ans=0;
                int lastvalue=h.path[pathsz-1];
                ans+=tt[lastvalue][i];
                ans+=h.cost;

                for(int j=1;j<=row;j++)
                {
                    tt[lastvalue][j]=INF;
                    tt[j][i]=INF;
                }
                tt[i][1]=INF;
                Abar t1=ReducedRow(tt);
                ans+=t1.val;
                Abar t2=ReducedColumn(t1.ar);
                ans+=t2.val;
                notun.cost=ans;
                notun.rcl=t2.ar;
                pq.push(notun);
            }
        }
    }
    cout<<"path : " <<endl;
    for(int i=0;i<solve.path.size();i++)
    {
        cout<<solve.path[i]<<" ";
    }
    cout<<source<<endl;
    cout<<"Cost :   "<<solve.cost<<endl;


    return 0;
}



