
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
void Search(Node* &curr,Node* &par,int val)
{

    while (curr != NULL && curr->data != val)
    {
        par = curr;
        if (val < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}

Node* SmallestVal(Node* curr)
{
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}


void Delete(Node*& root, int val)
{
    Node* parent = NULL;
    Node* curr = root;
    Search(curr, parent, val);
    if (curr == NULL) {
        return;
    }
    //leaf
    if (curr->left == NULL && curr->right == NULL)
    {

        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else {
            root = NULL;
        }
        delete(curr);
    }
    else if (curr->left && curr->right) //two child
    {
        Node* successor = SmallestVal(curr->right);
        int val = successor->data;
        Delete(root, successor->data);
        curr->data = val;
    }
    else {
                //onechild
        Node* child;
        if(curr->left)
        {
            child=curr->left;
        }
        else
        {
            child=curr->right;
        }

        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        else {
            root = child;
        }
        delete(curr);
    }
}


int main()
{
    int arr[] = { 1, 20, 100, 50, 52, 55 };
    Node* temp=BST(arr,6);
    Inorder(temp);
    cout<<endl;
    int k;cin>>k;
    Delete(temp,k);
    Inorder(temp);
    return 0;
}
