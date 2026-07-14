#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Insert at End
void insert(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Print List
void print()
{
    Node* p = head;

    cout << "List: ";

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Delete a Value
void Delete(int value)
{
    Node* p = head;

    while (p != NULL && p->data != value)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Value not found.\n";
        return;
    }

    // Only node
    if (head == tail)
    {
        head = tail = NULL;
    }

    // First node
    else if (p == head)
    {
        head = head->next;
        head->prev = NULL;
    }

    // Last node
    else if (p == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    // Middle node
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
}

// Count Nodes
int countNodes()
{
    int count = 0;

    Node* p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

// Find Middle Value
void middleValue()
{
    int count = countNodes();

    int mid = count / 2;

    Node* p = head;

    for (int i = 0; i < mid; i++)
    {
        p = p->next;
    }

    cout << "Middle Value = " << p->data << endl;
}

// Move Minimum to First
void moveMinToFirst()
{
    if (head == NULL)
        return;

    Node* minNode = head;
    Node* p = head;

    while (p != NULL)
    {
        if (p->data < minNode->data)
            minNode = p;

        p = p->next;
    }

    int temp = head->data;
    head->data = minNode->data;
    minNode->data = temp;
}

// Move Maximum to Last
void moveMaxToLast()
{
    if (head == NULL)
        return;

    Node* maxNode = head;
    Node* p = head;

    while (p != NULL)
    {
        if (p->data > maxNode->data)
            maxNode = p;

        p = p->next;
    }

    int temp = tail->data;
    tail->data = maxNode->data;
    maxNode->data = temp;
}

int main()
{
    insert(20);
    insert(50);
    insert(10);
    insert(40);
    insert(30);

    print();

    cout << "Total Nodes = " << countNodes() << endl;

    middleValue();

    moveMinToFirst();
    cout << "After Moving Minimum to First:\n";
    print();

    moveMaxToLast();
    cout << "After Moving Maximum to Last:\n";
    print();

    Delete(40);

    cout << "After Deleting 40:\n";
    print();

    return 0;
}