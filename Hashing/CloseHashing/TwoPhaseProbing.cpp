#include <iostream>
using namespace std;

#define SIZE 10

int hashtable[SIZE];
int flag[SIZE];  
// flag meanings:
// 0 = EMPTY
// 1 = OCCUPIED
// 2 = DELETED (Treat as empty for insertion, but keep searching for search/delete)

void init() {
    for (int i = 0; i < SIZE; i++) {
        flag[i] = 0;
        hashtable[i] = 0;
    }
}

void insert(int value) {
    int start = value % SIZE;
    if (start < 0) start += SIZE;

    // --- PHASE 1: QUADRATIC PROBING ---
    for (int i = 0; i < SIZE; i++) {
        int index = (start + i * i) % SIZE;

        // In insertion, we can take a slot if it's EMPTY (0) or DELETED (2)
        if (flag[index] == 0 || flag[index] == 2) {
            hashtable[index] = value;
            flag[index] = 1;
            cout << "Inserted " << value << " at index " << index << " (Quadratic)" << endl;
            return;
        }
    }

    // --- PHASE 2: LINEAR PROBING FALLBACK ---
    // If quadratic failed, check every single slot one by one
    int index = start;
    do {
        if (flag[index] == 0 || flag[index] == 2) {
            hashtable[index] = value;
            flag[index] = 1;
            cout << "Inserted " << value << " at index " << index << " (Linear Fallback)" << endl;
            return;
        }
        index = (index + 1) % SIZE;
    } while (index != start);

    cout << "HASH TABLE IS FULL\n";
}

void search(int value) {
    int start = value % SIZE;
    if (start < 0) start += SIZE;

    // --- PHASE 1: QUADRATIC SEARCH ---
    for (int i = 0; i < SIZE; i++) {
        int index = (start + i * i) % SIZE;

        // If we hit a truly EMPTY slot, the value definitely isn't here
        if (flag[index] == 0) break; 

        if (flag[index] == 1 && hashtable[index] == value) {
            cout << "Found at index: " << index << " (via Quadratic)" << endl;
            return;
        }
    }

    // --- PHASE 2: LINEAR SEARCH FALLBACK ---
    int index = start;
    do {
        if (flag[index] == 0) break;

        if (flag[index] == 1 && hashtable[index] == value) {
            cout << "Found at index: " << index << " (via Linear)" << endl;
            return;
        }
        index = (index + 1) % SIZE;
    } while (index != start);

    cout << "VALUE NOT FOUND\n";
}

void remove(int value) {
    int start = value % SIZE;
    if (start < 0) start += SIZE;

    // --- PHASE 1: QUADRATIC SEARCH TO DELETE ---
    for (int i = 0; i < SIZE; i++) {
        int index = (start + i * i) % SIZE;

        if (flag[index] == 0) break;

        if (flag[index] == 1 && hashtable[index] == value) {
            flag[index] = 2; // Mark as DELETED
            cout << "Deleted value from index: " << index << endl;
            return;
        }
    }

    // --- PHASE 2: LINEAR SEARCH TO DELETE ---
    int index = start;
    do {
        if (flag[index] == 0) break;

        if (flag[index] == 1 && hashtable[index] == value) {
            flag[index] = 2;
            cout << "Deleted value from index: " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
    } while (index != start);

    cout << "Value not found to delete\n";
}

void display() {
    cout << "\nINDEX\tVALUE\tSTATUS\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";
        if (flag[i] == 0) cout << "-\tEMPTY";
        else if (flag[i] == 1) cout << hashtable[i] << "\tOCCUPIED";
        else cout << "-\tDELETED";
        cout << endl;
    }
}

int main() {
    init();
    int choice, val;
    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; insert(val); break;
            case 2: cout << "Value: "; cin >> val; search(val); break;
            case 3: cout << "Value: "; cin >> val; remove(val); break;
            case 4: display(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}