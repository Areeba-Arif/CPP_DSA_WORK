#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

// Search
bool search(Node* head, int value)
{
    Node* p = head;

    while (p != NULL)
    {
        if (p->data == value)
            return true;

        p = p->next;
    }

    return false;
}

// Display
void display(Node* head)
{
    Node* p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Union
void Union(Node* head1, Node* head2)
{
    Node* result = NULL;

    Node* p = head1;
    while (p != NULL)
    {
        if (!search(result, p->data))
            insert(result, p->data);

        p = p->next;
    }

    p = head2;
    while (p != NULL)
    {
        if (!search(result, p->data))
            insert(result, p->data);

        p = p->next;
    }

    cout << "Union: ";
    display(result);
}

// Intersection
void Intersection(Node* head1, Node* head2)
{
    cout << "Intersection: ";

    Node* p = head1;

    while (p != NULL)
    {
        if (search(head2, p->data))
            cout << p->data << " ";

        p = p->next;
    }

    cout << endl;
}

// Difference A-B
void Difference(Node* head1, Node* head2)
{
    cout << "Difference (A-B): ";

    Node* p = head1;

    while (p != NULL)
    {
        if (!search(head2, p->data))
            cout << p->data << " ";

        p = p->next;
    }

    cout << endl;
}

// Customized Insert
void CustomizedInsert(Node*& head, int target, int value)
{
    Node* p = head;

    while (p != NULL)
    {
        if (p->data == target)
        {
            Node* temp = new Node;
            temp->data = value;

            temp->next = p->next;
            p->next = temp;

            p = temp->next;
        }
        else
        {
            p = p->next;
        }
    }
}

// Merge
void Merge(Node*& head1, Node* head2)
{
    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }

    Node* p = head1;

    while (p->next != NULL)
        p = p->next;

    p->next = head2;
}

int main()
{
    Node* set1 = NULL;
    Node* set2 = NULL;

    int n, value;

    cout << "Enter number of elements in Set 1: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (!search(set1, value))
            insert(set1, value);
    }

    cout << "Enter number of elements in Set 2: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (!search(set2, value))
            insert(set2, value);
    }

    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Sets\n";
        cout << "2. Union\n";
        cout << "3. Intersection\n";
        cout << "4. Difference (A-B)\n";
        cout << "5. Customized Insert\n";
        cout << "6. Merge\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Set 1: ";
            display(set1);
            cout << "Set 2: ";
            display(set2);
            break;

        case 2:
            Union(set1, set2);
            break;

        case 3:
            Intersection(set1, set2);
            break;

        case 4:
            Difference(set1, set2);
            break;

        case 5:
        {
            int target, newValue;

            cout << "Insert after which value? ";
            cin >> target;

            cout << "Enter new value: ";
            cin >> newValue;

            CustomizedInsert(set1, target, newValue);

            cout << "Updated Set 1: ";
            display(set1);
            break;
        }

        case 6:
            Merge(set1, set2);

            cout << "Merged List: ";
            display(set1);
            break;

        case 0:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}













/*
// Merge (Merged in ascending numerical order as specified in the sheet)
void Merge(Node* head1, Node* head2)
{
    Node* result = NULL;
    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            insert(result, p1->data);
            p1 = p1->next;
        }
        else
        {
            insert(result, p2->data);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insert(result, p1->data);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insert(result, p2->data);
        p2 = p2->next;
    }

    cout << "Merged List: ";
    display(result);
}

*/