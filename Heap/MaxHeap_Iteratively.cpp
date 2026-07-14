#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    // Upheapify
    void upHeapify(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }

    // Downheapify
    void downHeapify(int i, int size) {
        while (true) {
            int largest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:

    // Insert
    void insert(int value) {
        heap.push_back(value);
        upHeapify(heap.size() - 1);
    }

    // Delete Max
    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Deleted: " << heap[0] << endl;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            downHeapify(0, heap.size());
    }

    // Display
    void display() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Heap: ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

  
};

int main() {
    MaxHeap h;
    int choice, value;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete Max\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            h.insert(value);
            break;

        case 2:
            h.deleteMax();
            break;

        case 3:
            h.display();
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}