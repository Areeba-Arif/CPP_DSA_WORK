#include <iostream>
using namespace std;

class Node {
public :

    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }


};

class LinkedList {
private:
    Node* head;  

    void displayRecursive(Node* temp)
    {
        if(temp==NULL)  //base case
        {
            return;
        }
        cout<<temp->data<<" ";
        displayRecursive(temp->next);
    }  

    void reverseRecursive(Node* temp)
    {
        if(temp==NULL)  //base case
        {
            return;
        }
        reverseRecursive(temp->next);
        cout<<temp->data<<" ";
    }


public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node* newNode = new Node(value);

        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;

            }
            temp->next = newNode;
        }

    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"List is empty!"<<endl;
            return;

        }
        displayRecursive(head);
        cout<<endl;
    }

    
    void reverseDisplay() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        reverseRecursive(head);
        cout << endl;
    }
}; 

int main() {

      LinkedList list;
    int choice = 0;

    while (choice != 4) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Reverse Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int value;
            cout << "Enter value: ";
            cin >> value;
            list.insert(value);
            cout << "Inserted successfully!" << endl;
            break;
        }

        case 2:
            cout << "Linked List: ";
            list.display();
            break;

        case 3:
            cout << "Reverse Linked List: ";
            list.reverseDisplay();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}