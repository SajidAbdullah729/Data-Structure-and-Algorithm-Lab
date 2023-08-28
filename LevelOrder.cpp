


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
};

SS Queue[100];


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

void Enqueue(Node* x)
{
    top++;
    Queue[top].a=x;

}

void Dequeue()
{
    top--;
    for(int i=0;i<=top;i++)
    {
        Queue[i].a=Queue[i+1].a;
    }
    Queue[top+1].a=NULL;
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




void LevelOrder(Node* root)
{
    Enqueue(root);
    while(!isEmpty())
    {
        Node *tp=new Node();
        tp=Queue[0].a;
        Dequeue();
        if(tp!=NULL)
        {
            cout<<tp->data<<" ";
            if(tp->left!=NULL)
            {
                    Enqueue(tp->left);
            }
            if(tp->right!=NULL)
            {
                Enqueue(tp->right);
            }

        }
    }
}

void fun(Node *node)
{

}

int main()
{
    Node* root=createTree();
    //cout<<root->data<<endl;
    //fun(root);
    LevelOrder(root);
    return 0;
}
