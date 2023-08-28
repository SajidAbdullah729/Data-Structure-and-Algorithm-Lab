#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<cmath>

using namespace std;

int adj[100][100];

bool visited[101];

int node,edge;
struct Node {
    int data;
    struct Node* next;

};
const int tt=-1;
struct Node* head=NULL;

struct Node* tail=NULL;
void EnQueue(int x)
{

    struct Node* temp =new Node();
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
    struct Node* temp =new Node();
    temp=head;
    head = head->next;

    if (head == NULL)
        tail = NULL;

    free(temp);
}

int Front()
{
    if(head!=NULL) return head->data;
}


bool isEmpty()
{
    if(head==NULL) return true;
    else return false;
}

int tmp;
void BFS(int source)
{
    EnQueue(source);
    visited[source]=true;
    while(!isEmpty())
    {
           tmp=Front();


            cout<<Front()<<" ";
            DeQueue();
            for(int i=0; i<=node; i++)
            {
                if(adj[tmp][i]>=1 && ( !visited[i] ) )
                {
                    EnQueue(i);
                    visited[i]=true;
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
    for(int i=0;i<=node;i++)
    {
        for(int j=0;j<=node;j++)
        {
            adj[i][j]=0;
        }
    }
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
        adj[to][from]=weight;
    }
    BFS(0);
    return 0;
}
