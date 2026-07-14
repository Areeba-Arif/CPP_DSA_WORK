#include <iostream>
using namespace std;

class CircularQueue {
    int *q;
    int size;
    int front, rear;

public:
    CircularQueue(int s) {
        size = s;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is FULL\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        q[rear] = value;
        cout << "Inserted\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is EMPTY\n";
            return;
        }

        cout << q[front] << " deleted\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {       // Display shows elements in the SAME SEQUENCE they were inserted
        if (front == -1) {
            cout << "Queue is EMPTY\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear)//Stop the loop when you reach the last element (rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};



int main() {
    int size, choice, value;

    cout << "Enter queue size: ";
    cin >> size;

    CircularQueue q(size);

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
