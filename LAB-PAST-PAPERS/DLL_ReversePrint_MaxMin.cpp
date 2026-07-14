#include <iostream>
using namespace std;

struct DL_Node
{
    int data;
    DL_Node* next;
    DL_Node* prev;
};

DL_Node* head = NULL;
DL_Node* tail = NULL;

// Insert an element at the end of the list
void insert(int value){
    // create new node
    DL_Node* temp = new DL_Node;
    temp->data = value;
    temp->next = NULL;

    // 1) if list is empty
    if(head == NULL){
        temp->prev = NULL;
        head = tail = temp;
    } else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

// Print list from head to tail
void print_list(){
    // check if the list is empty 
    if(head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    DL_Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Reverse list: changes next to prev and prev to next, updating head and tail
void reverse_list() {
    if (head == NULL) {
        cout << "List is empty, nothing to reverse!" << endl;
        return;
    }

    DL_Node* current = head;
    DL_Node* temp = NULL;

    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node (which is now stored in current->prev due to the swap)
        current = current->prev;
    }

    // Update global head and tail pointers
    temp = head;
    head = tail;
    tail = temp;

    cout << "LIST REVERSED SUCCESSFULLY" << endl;
}

// Find minimum element in the list
void find_minimum() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    DL_Node* current = head;
    int min_val = current->data;

    while (current != NULL) {
        if (current->data < min_val) {
            min_val = current->data;
        }
        current = current->next;
    }

    cout << "Minimum element in the list: " << min_val << endl;
}

// Find maximum element in the list
void find_maximum() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    DL_Node* current = head;
    int max_val = current->data;

    while (current != NULL) {
        if (current->data > max_val) {
            max_val = current->data;
        }
        current = current->next;
    }

    cout << "Maximum element in the list: " << max_val << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- MENU (Objective 09) ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Print List" << endl;
        cout << "3. Reverse List" << endl;
        cout << "4. Find Minimum" << endl;
        cout << "5. Find Maximum" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int count, value;
            cout << "How many numbers you want to add? ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> value;
                insert(value);
            }
            cout << "Values inserted successfully!" << endl;
            break;
        }

        case 2:
            print_list();
            break;

        case 3:
            reverse_list();
            break;

        case 4:
            find_minimum();
            break;

        case 5:
            find_maximum();
            break;

        case 6:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}