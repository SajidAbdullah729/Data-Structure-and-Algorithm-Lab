#include<iostream>
#include<stdlib.h>
using namespace std;

void Merge(int arr[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(int i=1; i<=n1; i++)
    {
        L[i]=arr[p+i-1];
    }
    for(int i=1; i<=n2; i++)
    {
        R[i]=arr[q+i];
    }
    L[n1+1]=1000000;
    R[n2+1]=1000000;
    int i=1;
    int j=1;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
    }

}

void MergeSort(int arr[],int p,int q)
{
    if(p<q)
    {
        int r=(p+q)/2;
        MergeSort(arr,p,r);
        MergeSort(arr,r+1,q);
        Merge(arr,p,r,q);
    }

}
int main()
{
    int arr[10];
    for(int i=0; i<=9; i++)
    {
        arr[i]=rand()%10+0;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    MergeSort(arr,0,9);
    cout<<"After Sorting: "<<endl;
    for(int i=0; i<=9; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
