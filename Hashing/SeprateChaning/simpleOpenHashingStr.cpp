// #include <iostream>
// using namespace std;

// // Node
// struct Node {
//     char data;
//     Node* next;
// };

// // Hash table
// Node* table[10];

// // Initialize
// void init() {
//     for(int i = 0; i < 10; i++) {
//         table[i] = NULL;
//     }
// }

// // Hash function
// int hashFunc(char key) {
//     return key % 10;  // ASCII value
// }

// // Insert
// void insert(char value) {
//     int idx = hashFunc(value);

//     Node* temp = new Node;
//     temp->data = value;
//     temp->next = NULL;

//     if(table[idx] == NULL) {
//         table[idx] = temp;
//     }
//     else {
//         Node* curr = table[idx];
//         while(curr->next != NULL) {
//             curr = curr->next;
//         }
//         curr->next = temp;
//     }
// }

// // Search
// void search(char key) {
//     int idx = hashFunc(key);

//     Node* curr = table[idx];
//     while(curr != NULL) {
//         if(curr->data == key) {
//             cout << "Found\n";
//             return;
//         }
//         curr = curr->next;
//     }
//     cout << "Not Found\n";
// }

// // Delete
// void del(char key) {
//     int idx = hashFunc(key);

//     Node* curr = table[idx];
//     Node* prev = NULL;

//     while(curr != NULL) {
//         if(curr->data == key) {
//             if(prev == NULL) {
//                 table[idx] = curr->next;
//             } else {
//                 prev->next = curr->next;
//             }
//             delete curr;
//             cout << "Deleted\n";
//             return;
//         }
//         prev = curr;
//         curr = curr->next;
//     }
//     cout << "Not Found\n";
// }

// // Display
// void display() {
//     for(int i = 0; i < 10; i++) {
//         cout << i << " : ";
//         Node* curr = table[i];
//         while(curr != NULL) {
//             cout << curr->data << " -> ";
//             curr = curr->next;
//         }
//         cout << "NULL\n";
//     }
// }

// // Main
// int main() {
//     init();

//     insert('A');
//     insert('B');
//     insert('K');
//     insert('Z');

//     display();

//     search('K');
//     del('K');

//     display();
// }



#include <iostream>
using namespace std;

// Node
struct Node {
    string data;
    Node* next;
};

// Hash table
Node* table[10];

// Initialize
void init() {
    for(int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
}

// Hash function for string
int hashFunc(string key) {
    int sum = 0;
    for(int i = 0; i < key.length(); i++) {
        sum += key[i];  // ASCII value
    }
    return sum % 10;
}

// Insert
void insert(string value) {
    int idx = hashFunc(value);

    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if(table[idx] == NULL) {
        table[idx] = temp;
    }
    else {
        Node* curr = table[idx];
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Search
void search(string key) {
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
void del(string key) {
    int idx = hashFunc(key);

    Node* curr = table[idx];
    Node* prev = NULL;

    while(curr != NULL) {
        if(curr->data == key) {
            if(prev == NULL) {
                table[idx] = curr->next;
            } else {
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
        while(curr != NULL) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}

// Main
int main() {
    init();

    insert("Ali");
    insert("Ahmed");
    insert("Sara");
    insert("Zara");

    display();

    search("Sara");
    del("Sara");

    display();
}