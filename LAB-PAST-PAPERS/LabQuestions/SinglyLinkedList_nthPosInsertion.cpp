#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at end
void insertEnd(Node*& head, int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    Node* p = head;
    while(p->next != NULL)
        p = p->next;

    p->next = temp;
}

// Count nodes
int countNodes(Node* head)
{
    int count = 0;
    Node* p = head;

    while(p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

// Insert at beginning
void insertBeginning(Node*& head, int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

// Insert at nth position
void insertNth(Node*& head, int value, int n)
{
    int total = countNodes(head);

    // If list has fewer than n nodes
    if(total < n)
    {
        if(value % 2 != 0)
        {
            cout << "List has less than " << n
                 << " nodes.\nOdd value inserted at beginning.\n";
            insertBeginning(head, value);
        }
        else
        {
            cout << "List has less than " << n
                 << " nodes.\nEven value inserted at end.\n";
            insertEnd(head, value);
        }
        return;
    }

    // Insert at first position
    if(n == 1)
    {
        insertBeginning(head, value);
        return;
    }

    //total>=n 
    Node* temp = new Node;
    temp->data = value;

    Node* p = head;

    for(int i = 1; i < n - 1; i++)
        p = p->next;

    temp->next = p->next;
    p->next = temp;
}

// Display list
void display(Node* head)
{
    Node* p = head;

    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Reverse display using iteration
void reverseDisplay(Node* head)
{
    stack<int> st;

    Node* p = head;

    while(p != NULL)
    {
        st.push(p->data);
        p = p->next;
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    int size;

    cout << "Enter number of nodes: ";
    cin >> size;

    cout << "Enter elements:\n";

    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        insertEnd(head, x);
    }

    int value;
    cout << "Enter value to insert: ";
    cin >> value;

    int n = 7;      // Last digit of roll number 767

    insertNth(head, value, n);

    cout << "\nLinked List:\n";
    display(head);

    cout << "Reverse Display:\n";
    reverseDisplay(head);

    return 0;
}