#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool bin_search(vector<int> &arr,int val,int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==val) return true;
        else if(arr[mid]>val) right=mid-1;
        else if(arr[mid]<val) left=mid+1;
    }
    return false;
}
int main()
{
    cout<<"Enter amount of elements:";
    int n;
    cin>>n;
    vector<int> v;
    cout<<"Enter elements of sets:"<<endl;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<"Enter searching element :";
    int val;
    cin>>val;
    if(bin_search(v,val,n))
    {
        cout<<"Found"<<endl;
    }
    else cout<<"Not Found"<<endl;
    return 0;
}

