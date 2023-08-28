
#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void Insert(int x)
{
    struct Node* node=(struct Node*)malloc(sizeof(Node));
    node->data=x;
    if(head==NULL)
    {
        head=node;
        node->next=head;
    }
    else
    {
        struct Node* it=(struct Node*)malloc(sizeof(Node));
        it=head;
        while(it->next!=head)
        {
            it=it->next;
        }
        node->next=head;
        it->next=node;
        head=node;
    }
}

void Delete()
{
    if(head==NULL ) return ;
    else if(head->next==head)
    {
        head=NULL;
        free(head);
    }
    else
    {
        struct Node* it=(struct Node*)malloc(sizeof(Node));
        it=head;
        do

        {
            it=it->next;
        }  while(it->next!=head);

        it->next=head->next;
        free(head);
        head=it->next;
    }
}
void Print()
{
   if(head==NULL) return;
   else
   {
       struct Node* it=(struct Node*)malloc(sizeof(Node));
       it=head;

       do{
           cout<<it->data<<" ";
           it=it->next;
       }
       while(it!=head);
       cout<<endl;
   }
}

void PrintReverse(Node*t)
{
    if(t->next!=head) PrintReverse(t->next);
    cout<<t->data<<" ";
}

int main() {


   Insert(1);
   Insert(2);
   Insert(3);
   Insert(4);
   Print();
   Delete();
   Print();
   PrintReverse(head);
   Delete();
   cout<<endl;
   Print();
   return 0;
}
