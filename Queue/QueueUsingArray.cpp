#include <iostream>
using namespace std;

class SimpleQueue {
    int *q;
    int capacity;
    int front, rear;

public:
    SimpleQueue(int size) {
        capacity = size;
        q = new int[capacity];
        front = -1;
        rear = -1;
    }

    // ✅ isEmpty
    bool isEmpty() {
        return front == -1;
    }

    // ✅ isFull
    bool isFull() {
        return rear == capacity - 1;
    }

    // ✅ enqueue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        q[++rear] = value;
        cout << value << " inserted\n";
    }

    // ✅ dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }

        cout << q[front] << " deleted\n";
        front++;

        // Reset when queue becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // ✅ display
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;

    cout << "Enter queue size: ";
    cin >> size;

    SimpleQueue q(size);

    while(true) {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exit\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}