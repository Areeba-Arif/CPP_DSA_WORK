#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> min_heap;

    // Upheapify (Bubble Up)
    void upHeapify(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (min_heap[i] < min_heap[parent]) {
                swap(min_heap[i], min_heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

     // Downheapify (Delete fix)
    void downHeapify(int i) {
        int n = min_heap.size();

        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // check left child
            if (left < n && min_heap[left] < min_heap[smallest]) {
                smallest = left;
            }

            // check right child
            if (right < n && min_heap[right] < min_heap[smallest]) {
                smallest = right;
            }

            // if no change, heap is correct
            if (smallest == i)
                break;

            swap(min_heap[i], min_heap[smallest]);
            i = smallest;
        }
    }

public:
    // Insert element
    void insert(int value) {
        min_heap.push_back(value);   // insert at end
        upHeapify(min_heap.size() - 1);
    }

     ////Delete 


    void deleteMin() {
        if (min_heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Deleted max: " << min_heap[0] << endl;

        // Step 1: move last to root
        min_heap[0] = min_heap.back();

        // Step 2: remove last
        min_heap.pop_back();

        // Step 3: fix heap
        if (!min_heap.empty())
            downHeapify(0);
    }


    // Display heap (level order)
    void display() {
        for (int x : min_heap) {
            cout << x << " ";
        }
        cout << endl;
    }


};

int main() {
    MinHeap mh;

    mh.insert(50);
    mh.insert(30);
    mh.insert(70);
    mh.insert(20);
    mh.insert(90);
    mh.insert(40);

    cout << "Min Heap: ";
    mh.display();

    mh.deleteMin();


    cout<<"Updated: "<<endl;
    mh.display();

    return 0;
}