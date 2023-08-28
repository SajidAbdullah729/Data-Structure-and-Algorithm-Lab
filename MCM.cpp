#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
const int INF=10000000;
vector<int> dimension;
void initi(int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
}


int MCM(int start,int ended)
{
    if(start>=ended) return 0;
    if(dp[start][ended]!=-1) return dp[start][ended];
    dp[start][ended]=INF;
    int mid;
    for(mid=start;mid<ended;mid++)
    {
        int val=MCM(start,mid)+MCM(mid+1,ended)+(dimension[start-1]*dimension[mid]*dimension[ended]);
        dp[start][ended]=min(val,dp[start][ended]);
    }
    return dp[start][ended];
}

int main()
{
   int totalarray,val;
   cout<<"Total array: ";
   cin>>totalarray;
   for(int i=0;i<totalarray+1;i++)
   {
       cin>>val;
       dimension.push_back(val);
   }
   initi(totalarray+1,totalarray+1);
   cout<<"Min Matrix multiplication :";
   cout<<MCM(1,totalarray)<<endl;
   return 0;
}
