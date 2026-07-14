#include <iostream>
using namespace std;

struct DL_Node
{
    int data;
    int index;        // Added to maintain the count/index of the node
    DL_Node* next;
    DL_Node* prev;
};

DL_Node* head = NULL;
DL_Node* tail = NULL;

// Insert a node at the end (tail) of the list
void insert(int value){
    // Create new node
    DL_Node* temp = new DL_Node;
    temp->data = value;
    temp->next = NULL;

    // 1) If list is empty
    if(head == NULL){
        temp->prev = NULL;
        temp->index = 0; // First node has index 0
        head = tail = temp;
    } else {
        temp->prev = tail;
        temp->index = tail->index + 1; // Index is previous tail's index + 1
        tail->next = temp;
        tail = temp;
    }
}

// Partition helper function for Quick Sort
DL_Node* partition(DL_Node* l, DL_Node* h) {
    // Set pivot as the data of the high node (h)
    int pivot = h->data;
    
    // i starts before the low node (l)
    DL_Node* i = l->prev;
    
    // Traverse from low (l) to high->prev (h)
    for (DL_Node* j = l; j != h; j = j->next) {
        if (j->data <= pivot) {
            // Move i forward
            i = (i == NULL) ? l : i->next;
            
            // Swap data of i and j
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    
    // Place pivot in its correct position
    i = (i == NULL) ? l : i->next;
    int temp = i->data;
    i->data = h->data;
    h->data = temp;
    
    return i;
}

// Recursive helper function for Quick Sort
void _quickSort(DL_Node* l, DL_Node* h) {
    if (h != NULL && l != h && l != h->next) {
        DL_Node* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

// Main Quick Sort wrapper function
void quickSort() {
    if (head == NULL) {
        cout << "List is empty, cannot sort." << endl;
        return;
    }
    _quickSort(head, tail);
    cout << "List sorted successfully using Quick Sort!" << endl;
}

// Print the list showing both data and index
void print_list() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    DL_Node* curr = head;
    while (curr != NULL) {
        cout << "[Val: " << curr->data << " (Index: " << curr->index << ")] -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert Elements" << endl;
        cout << "2. Print List" << endl;
        cout << "3. Quick Sort List" << endl;
        cout << "4. Exit" << endl;
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
            quickSort();
            break;

        case 4:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}