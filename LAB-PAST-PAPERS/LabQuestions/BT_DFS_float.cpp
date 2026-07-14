#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node
{
    float data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(float value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Search using DFS (Iterative Preorder)
bool DFS_Search(Node* root, float x)
{
    if (root == NULL)
        return false;

    stack<Node*> s;
    s.push(root);

    while (!s.empty())
    {
        Node* current = s.top();
        s.pop();

        if (current->data == x)
            return true;

        // Push right first
        if (current->right != NULL)
            s.push(current->right);

        // Push left second
        if (current->left != NULL)
            s.push(current->left);
    }

    return false;
}

// Preorder Traversal without recursion
void preorder(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    cout << "Preorder Traversal: ";

    while (!s.empty())
    {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push right first
        if (current->right != NULL)
            s.push(current->right);

        // Push left second
        if (current->left != NULL)
            s.push(current->left);
    }

    cout << endl;
}

int main()
{
    // Create Binary Tree

    Node* root = createNode(10.5);

    root->left = createNode(5.2);
    root->right = createNode(20.8);

    root->left->left = createNode(3.1);
    root->left->right = createNode(7.6);

    root->right->left = createNode(15.4);
    root->right->right = createNode(30.9);

    // Display preorder traversal
    preorder(root);

    // Search
    float x;
    cout << "Enter value to search: ";
    cin >> x;

    if (DFS_Search(root, x))
        cout << x << " Found in the tree." << endl;
    else
        cout << x << " Not Found." << endl;

    return 0;
}