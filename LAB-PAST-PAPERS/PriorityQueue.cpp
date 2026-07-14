#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent each task with stability tracking
struct Task {
    string name;
    int priority;
    int sequence; // Sequence counter to maintain FIFO order for equal priorities
};

class TaskPriorityQueue {
private:
    vector<Task> heap;
    int sequenceCounter = 0; // Increments with every insertion

    // Helper to compare priority and enforce stability
    bool isHigherPriority(const Task& a, const Task& b) {
        if (a.priority != b.priority) {
            return a.priority > b.priority; // True if 'a' has higher priority
        }
        return a.sequence < b.sequence; // FIFO: True if 'a' entered earlier (smaller sequence number)
    }

    // Upheapify
    void upHeapify(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (isHigherPriority(heap[i], heap[parent])) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    // Downheapify
    void downHeapify(int i, int size) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && isHigherPriority(heap[left], heap[largest]))
                largest = left;

            if (right < size && isHigherPriority(heap[right], heap[largest]))
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Insert a new task
    void insert(string name, int priority) {
        Task newTask = {name, priority, sequenceCounter++};
        heap.push_back(newTask);
        upHeapify(heap.size() - 1);
    }

    // Delete and return the highest priority task
    void deleteMax() {
        if (heap.empty()) {
            cout << "Queue is empty! No tasks to execute.\n";
            return;
        }

        // Show the user the completed task
        cout << "Executing: " << heap[0].name << " (Priority: " << heap[0].priority << ")\n";

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            downHeapify(0, heap.size());
        }
    }

    // Display the items in current storage order
    void display() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "\nCurrent Queue Structure (Heap Order):\n";
        for (const auto& task : heap) {
            cout << "- " << task.name << " [Priority: " << task.priority << ", Seq: " << task.sequence << "]\n";
        }
        cout << endl;
    }
};

int main() {
    TaskPriorityQueue pq;
    int choice;
    string name;
    int priority;

    while (true) {
        cout << "\n--- TASK MANAGER ---\n";
        cout << "1. Add Task (Enqueue)\n";
        cout << "2. Execute Highest Priority Task (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter task name: ";
            cin >> name;
            cout << "Enter priority (higher number = higher priority): ";
            cin >> priority;
            pq.insert(name, priority);
            break;

        case 2:
            pq.deleteMax();
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Exiting system...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}