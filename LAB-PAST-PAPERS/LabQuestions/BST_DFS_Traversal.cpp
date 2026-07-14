#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//------------ Insert in BST ------------

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        Node* temp = new Node;
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

//------------ DFS Traversals ------------

// Preorder
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder
void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;

    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,70);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,60);
    root = insert(root,80);

    cout << "Preorder : ";
    preorder(root);

    cout << "\nInorder  : ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}