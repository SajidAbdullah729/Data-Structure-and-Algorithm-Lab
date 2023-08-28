#include<iostream>
#include<conio.h>
using namespace std;
void swapnumber(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
int main()
{
    int arr[]={9,8,7,6,5,4,3,1,2,0};
    for(int i=0;i<10;i++)
    {
        int c=0;
        for(int j=0;j<9;j++)
        {
            if(arr[j]>arr[j+1]) {swapnumber(arr[j],arr[j+1]); c++;}
        }
        if(c==0) break;
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
