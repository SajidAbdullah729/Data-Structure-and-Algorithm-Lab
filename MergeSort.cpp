#include<iostream>
#include<vector>
#include<string>

using namespace std;
const int INF=1000000000;

void Merge(int left,int mid,int right,vector<int>&arr)
{
    int leftsz=mid-left+1;
    int rightsz=right-mid;
    int bamarray[leftsz+1];
    int danarray[rightsz+1];

    for(int i=0;i<leftsz;i++)
    {
        bamarray[i]=arr[left+i];
    }
    for(int i=0;i<rightsz;i++)
    {
        danarray[i]=arr[mid+1+i];
    }
    bamarray[leftsz]=INF;
    danarray[rightsz]=INF;
    int pb=0,pd=0;
    for(int i=left;i<=right;i++)
    {
        if(bamarray[pb]<danarray[pd])
        {
            arr[i]=bamarray[pb];
            pb++;
        }
        else
        {
            arr[i]=danarray[pd];
            pd++;
        }
    }
}


void MergeSort(int left,int right,vector<int> &arr)
{
    if(left<right)
    {
        int mid=(left+right)/2;

        MergeSort(left,mid,arr);

        MergeSort(mid+1,right,arr);


        Merge(left,mid,right,arr);
    }
}


int main()
{
    cout<<"Enter amount of elements:";
    int n; cin>>n;
    vector<int> v;
    cout<<"Enter elements of sets:"<<endl;
    for(int i=0; i<n; i++)
    {
        int k;cin>>k;
        v.push_back(k);
    }
    MergeSort(0,n-1,v);
    cout<<"Sorted List of Numbers : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
