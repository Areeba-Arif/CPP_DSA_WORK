#include <iostream>
#include <stack>
using namespace std;

//--------------- Node Structure ---------------

struct Node
{
    float data;
    Node* left;
    Node* right;
};

//--------------- Create Node ---------------

Node* createNode(float value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//--------------- Preorder (Without Recursion) ---------------

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

//--------------- Inorder (Without Recursion) ---------------

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

//--------------- Postorder (Without Recursion) ---------------


/*
If we use one stack, we don't know when both the left and right subtrees have been processed, so postorder becomes tricky.

Using two stacks makes it simple.

Stack 1 (s1) → Used to visit the nodes.
Stack 2 (s2) → Stores the nodes in reverse order.

At the end, popping from s2 gives the correct postorder.
*/

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

//--------------- Main ---------------

int main()
{
    // Create Binary Tree
    Node* root = createNode(10.5);

    root->left = createNode(5.2);
    root->right = createNode(20.8);

    root->left->left = createNode(3.1);
    root->left->right = createNode(7.6);

    root->right->left = createNode(15.4);
    root->right->right = createNode(25.9);

    cout << "Preorder (Without Recursion): ";
    preorder(root);

    cout << "\n\nInorder (Without Recursion): ";
    inorder(root);

    cout << "\n\nPostorder (Without Recursion): ";
    postorder(root);

    return 0;
}