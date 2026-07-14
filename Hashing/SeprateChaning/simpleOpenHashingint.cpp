#include <iostream>
using namespace std;

// Node
struct Node {
    int data;
    Node* next;
};

// Hash Table
Node* table[10];

// Initialize
void init() {
    for(int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
}

// Hash Function
int hashFunc(int key) {
    return key % 10;
}

// Insert
void insert(int value) {
    int idx = hashFunc(value);

    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    // If empty
    if(table[idx] == NULL) {
        table[idx] = temp;
    }
    else {
        // Chaining
        Node* curr = table[idx];
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Search
void search(int key) {
    int idx = hashFunc(key);

    Node* curr = table[idx];

    while(curr != NULL) {
        if(curr->data == key) {
            cout << "Found\n";
            return;
        }
        curr = curr->next;
    }

    cout << "Not Found\n";
}

// Delete
void del(int key) {
    int idx = hashFunc(key);

    Node* curr = table[idx];
    Node* prev = NULL;

    while(curr != NULL) {
        if(curr->data == key) {
            // If first node
            if(prev == NULL) {
                table[idx] = curr->next;
            }
            else {
                prev->next = curr->next;
            }

            delete curr;
            cout << "Deleted\n";
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Not Found\n";
}

// Display
void display() {
    for(int i = 0; i < 10; i++) {
        cout << i << " : ";
        Node* curr = table[i];

        if (curr == NULL) {
            cout << "Empty";
        }
        else {
            while (curr != NULL) {
                cout << curr->data;
                if (curr->next != NULL)
                    cout << " -> ";
                curr = curr->next;
            }
        }

        cout << "->NULL\n";
    }
}

// Main
int main() {
    init();

    insert(10);
    insert(20);
    insert(30);  // collision at index 0
    insert(21);
    insert(25);
    insert(11);  // collision at index 1

    display();

    search(30);
    del(30);

    display();

    return 0;
}