#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int xlen,ylen;
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


int LCS(int x,int y,string &s1,string &s2)
{
    if(x==xlen || y==ylen) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(s1[x]==s2[y])
    {
        return dp[x][y]=LCS(x+1,y+1,s1,s2)+1;
    }
    else
    {
        return dp[x][y]=max(LCS(x+1,y,s1,s2),LCS(x,y+1,s1,s2));
    }

}

int main()
{
    string s1,s2;cin>>s1>>s2;
    xlen=s1.length();
    ylen=s2.length();

    initi(xlen,ylen);
    cout<<LCS(0,0,s1,s2)<<endl;
    return 0;
}
