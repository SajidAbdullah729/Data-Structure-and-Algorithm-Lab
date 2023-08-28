#include<iostream>
using namespace std;
const int qq=-167377;
int Queue[50];
int top=-1;

void Enqueue(int x)
{
    top++;
    Queue[top]=x;

}

void Dequeue()
{
    top--;
    for(int i=0;i<top;i++)
    {

        Queue[i]=Queue[i+1];
        cout<<Queue[i]<<endl;
    }
    Queue[top+1]=qq;
}

int Size()
{
    return top+1;
}

bool isEmpty()
{
    if(top==-1) return true;
    else return false;
}

int main()
{

    Enqueue(50);
    Enqueue(40);
    cout<<Queue[0]<<endl;
    if(isEmpty()) cout<<"It is Empty"<<endl;
    Dequeue();
    if(isEmpty()) cout<<"It is Empty"<<endl;
    Enqueue(15);
    Enqueue(20);
    for(int i=0;i<=top;i++)
    {
        cout<<Queue[i]<<" ";
    }
    cout<<endl;
    cout<<"Size is:"<<Size()<<endl;
    return 0;
}
