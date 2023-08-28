
#include<iostream>
#include<stdlib.h>
using namespace std;


void swapp(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void QuickSort(int arr[],int f,int l)
{

    if(f<l)
    {
       int i=f+1;
       int j=l;
       while(arr[i]<=arr[f]) i++;
       while(arr[j]>arr[f]) j--;
       while(i<j)
       {
           swapp(arr[i],arr[j]);
           while(arr[i]<=arr[f]) i++;
           while(arr[j]>arr[f]) j--;
       }
       swapp(arr[j],arr[f]);
       QuickSort(arr,f,j-1);
       QuickSort(arr,j+1,l);
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
    QuickSort(arr,0,9);
    for(int i=0; i<=9; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
