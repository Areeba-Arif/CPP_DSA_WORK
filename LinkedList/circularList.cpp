#include <iostream>
#include <stdlib.h>
using namespace std;

struct LL_Node
{
    int data;
    LL_Node* next;
};

LL_Node* head = NULL;
LL_Node* tail = NULL;

// ---------------- INSERT ----------------
void insert(int value)
{
    LL_Node* temp = (LL_Node*)malloc(sizeof(LL_Node));
    temp->data = value;

    if(head == NULL)
    {
        head = tail = temp;
        tail->next = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
}

// ---------------- DISPLAY ----------------
void display()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    LL_Node* current = head;

    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while(current != head);

    cout << endl;
}

// ---------------- SEARCH ----------------
int search(int value)
{
    if(head == NULL)
        return -1;

    LL_Node* current = head;
    int position = 1;

    do
    {
        if(current->data == value)
            return position;

        current = current->next;
        position++;

    }while(current != head);

    return -1;
}

// ---------------- DELETE ----------------
void delete_node(int value)
{
    if(head == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }

    LL_Node* current = head;
    LL_Node* previous = tail;

    // Only one node
    if(head == tail && head->data == value)
    {
        free(head);
        head = tail = NULL;
        cout << "DELETE SUCCESSFULLY\n";
        return;
    }

    do
    {
        if(current->data == value)
        {
            // Delete Head
            if(current == head)
            {
                head = head->next;
                tail->next = head;
            }

            // Delete Tail
            else if(current == tail)
            {
                tail = previous;
                tail->next = head;
            }

            // Delete Middle
            else
            {
                previous->next = current->next;
            }

            free(current);
            cout << "DELETE SUCCESSFULLY\n";
            return;
        }

        previous = current;
        current = current->next;

    }while(current != head);

    cout << "VALUE NOT FOUND\n";
}

// ---------------- MAIN ----------------
int main()
{
    int choice;

    while(true)
    {
        cout << "\n------ MENU ------\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int n,value;

                cout<<"How many values? ";
                cin>>n;

                for(int i=0;i<n;i++)
                {
                    cout<<"Enter value "<<i+1<<": ";
                    cin>>value;
                    insert(value);
                }

                break;
            }

            case 2:
                display();
                break;

            case 3:
            {
                int key;
                cout<<"Enter value to search: ";
                cin>>key;

                int pos = search(key);

                if(pos==-1)
                    cout<<"Value not found\n";
                else
                    cout<<"Found at position "<<pos<<endl;

                break;
            }

            case 4:
            {
                int key;
                cout<<"Enter value to delete: ";
                cin>>key;

                delete_node(key);
                break;
            }

            case 5:
                return 0;

            default:
                cout<<"Invalid Choice\n";
        }
    }

    return 0;
}