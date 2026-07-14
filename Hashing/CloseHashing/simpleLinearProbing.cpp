#include <iostream>
using namespace std;

#define SIZE 10

int hashtable[SIZE];
int flag[SIZE];  
// flag meanings:
// 0 = EMPTY
// 1 = OCCUPIED
// 2 = DELETED

void init() {
    for (int i = 0; i < SIZE; i++) {
        flag[i] = 0;
        hashtable[i] = 0;
    }
}

void insert(int value) {
    int index = value % SIZE;
    if (index < 0) index += SIZE;

    int start = index;

    while (flag[index] == 1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            cout << "Hash table is full!\n";
            return;
        }
    }

    hashtable[index] = value;
    flag[index] = 1;

    cout << "Inserted " << value << " at index " << index << endl;
}

void search(int value) {
    int index = value % SIZE;
    if (index < 0) index += SIZE;

    int start = index;

    while (flag[index] != 0) {

        if (flag[index] == 1 && hashtable[index] == value) {
            cout << "Found at index: " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Not found\n";
}

void remove(int value) {
    int index = value % SIZE;
    if (index < 0) index += SIZE;

    int start = index;

    while (flag[index] != 0) {

        if (flag[index] == 1 && hashtable[index] == value) {
            flag[index] = 2;  // mark as DELETED
            cout << "Deleted value from index: " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Value not found to delete\n";
}

void display() {
    cout << "\nINDEX\tVALUE\tSTATUS\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";

        if (flag[i] == 0)
            cout << "-\tEMPTY";
        else if (flag[i] == 1)
            cout << hashtable[i] << "\tOCCUPIED";
        else
            cout << "-\tDELETED";

        cout << endl;
    }
}

int main() {
    init();

    int choice, value;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                search(value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                remove(value);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}