


#include<iostream>
using namespace std;

void swapnumber(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void Sort(int *arr,int n)
{
     for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1]) {
                    swapnumber(arr[j],arr[j+1]);
                    c++;
            }
        }
        if(c==0) break;
    }
}

struct Node
{
    Node *left;
    Node *right;
    int data;
};


void Inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

Node* createNode(int item)
{
    Node *new_node=new Node;
    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
Node* Insert(Node* root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val< root->data)
    {
        root->left=Insert(root->left, val);
    }
    else
    {
        root->right=Insert(root->right, val);
    }

    return root;
}

void CreateBST( int left, int right, Node* &root,int arr[])
{
    if (left > right)
    {
        return;
    }
    int mid = (left+right)/2;
    root = createNode(arr[mid]);
    CreateBST(left, mid-1, root->left, arr);
    CreateBST(mid+1, right, root->right, arr);
}

Node* BST(int arr[], int n)
{
    Sort(arr,n);
    Node *root=NULL;
    CreateBST(0, n - 1, root,arr);
    return root;
}

void Search(Node* root,Node* parent,int val)
{
    if (root == NULL)
    {
        cout<<"Node is not in BST"<<endl;
        return;
    }

    if (root->data == val)
    {
        if (parent == NULL) {
            cout<<"Node is in BST"<<endl;
        }
        else if (val< parent->data)
        {
            cout<<"Node is in BST"<<endl;
        }
        else  {
           cout<<"Node is in BST"<<endl;
        }
        return;
    }

    if (val < root->data) {
        return Search(root->left,root,val);
    }

    return Search(root->right,root,val);
}

int main()
{
    int arr[] = { 1, 20, 100, 50, 52, 55 };
    Node* temp=BST(arr,6);
    Insert(temp,28);
    Inorder(temp);
    cout<<endl;
    Search(temp,NULL,28);
    return 0;
}
