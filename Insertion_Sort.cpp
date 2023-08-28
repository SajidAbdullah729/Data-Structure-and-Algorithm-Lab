#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Insertion_Sort(vector<int> &arr,int n)
{
     for(int i=1;i<n;i++)
     {
         int temp=arr[i];
         int j=i-1;
         for(j=i-1;j>=0 && temp<arr[j];j--)
         {
             arr[j+1]=arr[j];
         }
         arr[j+1]=temp;
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
    Insertion_Sort(v,n);
    cout<<"Sorted List of Numbers : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

