#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    cout<<"Enter amount of elements:";
    int n;cin>>n;
    vector<int> v;
    cout<<"Enter elements of sets:"<<endl;
    for(int i=0;i<n;i++)
    {
         int k;cin>>k;v.push_back(k);
    }
    cout<<"Enter searching element :";
    int val;cin>>val;
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(v[i]==val) {f=true;break;}
    }
    if(f) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}

