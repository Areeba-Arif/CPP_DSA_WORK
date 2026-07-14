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

// Insert in Sorted Order
void sortedInsert(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    // Empty List
    if (head == NULL)
    {
        head = tail = temp;
        return;
    }

    // Insert at Beginning
    if (value < head->data)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    // Insert at End
    if (value > tail->data)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        return;
    }

    // Insert in Middle
    Node* p = head;

    while (p != NULL && p->data < value)
    {
        p = p->next;
    }

    temp->next = p;
    temp->prev = p->prev;

    p->prev->next = temp;
    p->prev = temp;
}

// Print List
void print(Node* h)
{
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

// Copy List
Node* copyList(Node* head)
{
    Node* newHead = NULL;
    Node* newTail = NULL;

    Node* p = head;

    while (p != NULL)
    {
        Node* temp = new Node;
        temp->data = p->data;
        temp->next = NULL;
        temp->prev = NULL;

        if (newHead == NULL)
        {
            newHead = newTail = temp;
        }
        else
        {
            newTail->next = temp;
            temp->prev = newTail;
            newTail = temp;
        }

        p = p->next;
    }

    return newHead;
}

// Reverse List
Node* reverseList(Node* head)
{
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main()
{
    sortedInsert(40);
    sortedInsert(20);
    sortedInsert(50);
    sortedInsert(10);
    sortedInsert(30);

    cout << "Original Sorted List:\n";
    print(head);

    Node* copyHead = copyList(head);

    cout << "Copied List:\n";
    print(copyHead);

    copyHead = reverseList(copyHead);

    cout << "Reversed Copied List:\n";
    print(copyHead);

    return 0;
}