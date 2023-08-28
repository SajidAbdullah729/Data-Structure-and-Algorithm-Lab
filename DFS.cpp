

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<cmath>
using namespace std;

int adj[100][100];
int node,edge;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;


void Push(int x)
{
    struct Node* node=new Node();
    node->data=x;
    node->next=head;
    head=node;
}

void Pop()
{
    struct Node* node=new Node();
    node=head;
    head=head->next;
    free(node);
}

int Top()
{
    if(head!=NULL) return head->data;
}




bool isEmpty()
{
    if(head==NULL) return true;
    else return false;
}


bool visited[102];
void DFS(int source)
{
    Push(source);
    cout<<source<<" ";
    visited[source]=true;

    while(!isEmpty())
    {
        int temp=Top();
        Pop();
        if(!visited[temp])
        {
            cout<<temp<<" ";
            visited[temp]=1;
        }
        for(int i=0;i<=node;i++)
        {
            if(adj[temp][i]>=1 && !(visited[i]))
            {
                Push(i);
            }
        }
    }
}



int main()
{
    cout<<"Total Nodes: ";
    cin>>node;
    cout<<"Total Edges: ";
    cin>>edge;
    for(int i=0; i<edge; i++)
    {
        int from,to,weight;
        cout<<"From: ";
        cin>>from;
        cout<<"To: ";
        cin>>to;
        cout<<"Weight: ";
        cin>>weight;
        adj[from][to]=weight;
    }
    DFS(0);
    return 0;
}
