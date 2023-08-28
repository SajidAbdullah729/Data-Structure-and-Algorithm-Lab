#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<cmath>
using namespace std;

struct Node {
    int data;
    struct Node* next;

};

struct Node* head=NULL;

struct Node* tail=NULL;
void EnQueue(int x)
{

    struct Node* temp =(struct Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;

    if (tail == NULL)
    {
        tail = temp;
        head= temp;
        return;
    }


    tail->next = temp;
    tail = temp;
}


void DeQueue()
{

    if (head == NULL) return;


    struct Node* temp =(struct Node*)malloc(sizeof(Node));
    temp=head;
    head = head->next;

    if (head == NULL)
        tail = NULL;

    free(temp);
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
    if(isEmpty()) cout<<"No element"<<endl;
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    Print();
    DeQueue();
    Print();
    cout<<Size()<<endl;
    return 0;
}
