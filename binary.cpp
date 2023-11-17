#include <bits/stdc++.h>
using namespace std;

class Node
{
     public:
     
     int data;
     Node * left,*right;
     
     Node(int x): data(x),left(NULL),right(NULL) {}
};

class BST
{
    public:
    
    Node * root;
    
    BST() : root(NULL){}
    
    void insert(int x)
    {
        root = insertRec(root,x);
    }
    
    Node * insertRec(Node * root,int x)
    {
        if(!root)
        {
            return new Node(x);
        }
        
        if(x<root->data)
        {
            root->left = insertRec(root->left,x);
        }
        else if(x>root->data)
        {
            root->right = insertRec(root->right,x);
        }
        
        return root;
    }
    
    
    void pre()
    {
        cout<<"Preorder Traversal"<<endl;
        preOrder(root);
        cout<<endl;
    }
    
    void preOrder(Node * root)
    {
        if(root)
        {
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    
    
    void in()
    {
        cout<<"Inorder Traversal"<<endl;
        inOrder(root);
        cout<<endl;
    }
    
    void inOrder(Node * root)
    {
        if(root)
        {
            
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
    
    void post()
    {
        cout<<"Post order Traversal"<<endl;
        postOrder(root);
        cout<<endl;
    }
    
    void postOrder(Node * root)
    {
        if(root)
        {
            
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }
    
    
    
    
};

int main()
{
    BST bst;
    int numbers[] = {50, 30, 20, 40, 70, 60, 80};

    for (int number : numbers) {
        bst.insert(number);
    }

    bst.pre();
    bst.in();
    bst.post();

    return 0;
}
