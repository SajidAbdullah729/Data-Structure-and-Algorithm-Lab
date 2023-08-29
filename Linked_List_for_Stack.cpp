#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<cmath>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;


void Push(int x)
{
    struct Node* node=(struct Node*)malloc(sizeof(Node));
    node->data=x;
    node->next=head;
    head=node;
}

void Pop()
{
    struct Node* node=(struct Node*)malloc(sizeof(Node));
    node=head;
    head=head->next;
    free(node);
}


void Print()
{
    struct Node* it=(struct Node*)malloc(sizeof(it));

    it=head;
    while(it!=NULL)
    {
        cout<<it->data<<" ";
        it=it->next;

    }
    cout<<endl;
}



bool isEmpty()
{
    if(head==NULL) return true;
    else return false;
}

int Size()
{
    struct Node* it=(struct Node*)malloc(sizeof(it));

    it=head;
    int cc=0;
    while(it!=NULL)
    {

        it=it->next;
        cc++;
    }
    return cc;
}

int main()
{
    Print();
    if(isEmpty()) cout<<"No Element"<<endl;
    cout<<Size()<<endl;
    Push(11);
    Push(12);
    Push(13);
    Push(14);
    Print();
    Pop();
    Print();
    Push(16);
    Print();
    cout<<Size()<<endl;
    return 0;
}
