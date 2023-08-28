
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int INF=1000000000;


int Partition(int left,int right,vector<int>&arr)
{
    int bame=left+1;
    int dane=right;
    while(arr[left]>=arr[bame]) bame++;
    while(arr[left]<arr[dane]) dane--;
    while(bame<dane)
    {
        swap(arr[bame],arr[dane]);
        while(arr[bame]<=arr[left]) bame++;
        while(arr[dane]>arr[left]) dane--;
    }
    swap(arr[left],arr[dane]);
    return dane;
}


void QuickSort(int left,int right,vector<int> &arr)
{
    if(left<right)
    {
        int majhe=Partition(left,right,arr);
        QuickSort(left,majhe-1,arr);
        QuickSort(majhe+1,right,arr);
    }
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
    QuickSort(0,n-1,v);
    cout<<"Sorted List of Numbers : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
