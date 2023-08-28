

#include<iostream>
using namespace std;
const int qq=-167717;
int top=-1;


struct Node
{
    int data;
    Node* left;
    Node* right;
} ;


struct SS
{
   Node* a;
   int b;
};

SS Stack[100];


 Node* createNode(int item)
{
    Node *new_node=new Node;
    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void addleftchild(Node* parentnode,Node* child)
{
    parentnode->left=child;
}

void addrightchild(Node* parentnode,Node* child)
{
    parentnode->right=child;
}

Node* createTree()
{
    Node* two=createNode(2);
    Node* seven=createNode(7);
    Node* nine=createNode(9);
    addleftchild(two,seven);
    addrightchild(two,nine);
    Node* one=createNode(1);
    Node* six=createNode(6);
    addleftchild(seven,one);
    addrightchild(seven,six);
    Node* five=createNode(5);
    Node* ten=createNode(10);
    addleftchild(six,five);
    addrightchild(six,ten);
    Node *eight=createNode(8);
    addrightchild(nine,eight);
    Node* three=createNode(3);
    Node* four=createNode(4);
    addleftchild(eight,three);
    addrightchild(eight,four);
    return two;

}


void Push(Node *P,int i)
{
    top++;
    //Stack[top].a=new Node;
    Stack[top].a=P;
    Stack[top].b=i;
}
void Pop()
{
    //Stack[top].a=new Node;
    Stack[top].a=NULL;
    Stack[top].b=qq;
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




void Preorder(Node* P)
{
   Push(P,1);
   while(!isEmpty())
    {
        Node* tp=new Node();
        int ti;
        tp=Stack[top].a;
        ti=Stack[top].b;
        Pop();
        if(tp!=NULL)
        {
            if(ti==1)
            {
                Push(tp,2);
                cout<<tp->data<<" ";
            }
            else if(ti==2)
            {
                Push(tp,3);
                Push(tp->left,1);
            }
            else if(ti==3)
            {
                Push(tp->right,1);
            }
        }
    }
}



int main()
{
    Node* root=createTree();
    //cout<<root->data<<endl;
    //fun(root);
    Preorder(root);
    return 0;
}
