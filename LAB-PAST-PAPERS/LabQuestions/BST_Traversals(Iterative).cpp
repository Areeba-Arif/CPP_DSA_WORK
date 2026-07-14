#include <iostream>
#include <stack>
using namespace std;

//---------------- Node ----------------

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//---------------- Insert into BST ----------------

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

//---------------- Preorder (Without Recursion) ----------------

void preorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while(!s.empty())
    {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        if(current->right != NULL)
            s.push(current->right);

        if(current->left != NULL)
            s.push(current->left);
    }
}

//---------------- Inorder (Without Recursion) ----------------

void inorder(Node* root)
{
    stack<Node*> s;
    Node* current = root;

    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

//---------------- Postorder (Without Recursion) ----------------

void postorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node* current = s1.top();
        s1.pop();

        s2.push(current);

        if(current->left != NULL)
            s1.push(current->left);

        if(current->right != NULL)
            s1.push(current->right);
    }

    while(!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

//---------------- Descending Order ----------------

void descending(Node* root)
{
    if(root == NULL)
        return;

    descending(root->right);
    cout << root->data << " ";
    descending(root->left);
}

//---------------- Main ----------------

int main()
{
    Node* root = NULL;

    // Insert values into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Preorder (Without Recursion): ";
    preorder(root);

    cout << "\n\nInorder (Without Recursion): ";
    inorder(root);

    cout << "\n\nPostorder (Without Recursion): ";
    postorder(root);

    cout << "\n\nDescending Order: ";
    descending(root);

    return 0;
}