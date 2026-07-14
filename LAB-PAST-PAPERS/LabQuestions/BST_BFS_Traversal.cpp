#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct QNode
{
    Node* data;
    QNode* next;
};

QNode* front = NULL;
QNode* rear = NULL;

//---------------- Queue ----------------

void enqueue(Node* temp)
{
    QNode* n = new QNode;
    n->data = temp;
    n->next = NULL;

    if(rear == NULL)
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

Node* dequeue()
{
    if(front == NULL)
        return NULL;

    QNode* temp = front;
    Node* node = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    delete temp;

    return node;
}

bool isEmpty()
{
    return front == NULL;
}

//---------------- Insert in BST ----------------

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

//---------------- BFS Traversal ----------------

void BFS(Node* root)
{
    if(root == NULL)
        return;

    enqueue(root);

    while(!isEmpty())
    {
        Node* current = dequeue();

        cout << current->data << " ";

        if(current->left != NULL)
            enqueue(current->left);

        if(current->right != NULL)
            enqueue(current->right);
    }
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

    cout << "BFS Traversal: ";
    BFS(root);

    return 0;
}