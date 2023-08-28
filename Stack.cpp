
#include<iostream>
using namespace std;
const int qq=-167717;
int top=-1;
int Stack[50];
void Push(int x)
{
    top++;
    Stack[top]=x;
}
void Pop()
{
    Stack[top]=qq;
    top--;
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
    if( isEmpty() ) cout<<"It is Empty"<<endl;
    Push(10);
    cout<<Stack[top]<<endl;
    if(isEmpty()) cout<<"It is Empty"<<endl;
    Pop();
    cout<<Size()<<endl;

    return 0;
}
