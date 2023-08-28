#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    double arr[]={2,1,4,7,8,9,10,11,13,14};
    double key;
    cin>>key;
    int c=0;

    for(double i=0; i<10; i++)
    {
        if(key==arr[i])
        {
            c=1;
            break;
        }
    }
    if(c==1) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}
