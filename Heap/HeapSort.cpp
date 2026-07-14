#include <iostream>
using namespace std;

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {

    // ✅ Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) { //all node from 0 to n/2 -1 are internal node they have at least one child in heap 
        heapify(arr, n, i);
    }

    // ✅ Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move max to end
        heapify(arr, i, 0);     // heapify reduced heap
    }
}

// Print array
void printArrayAss(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void printArrayDes(int arr[], int n) {
    for (int i = n-1; i >=0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

// Main
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    cout << "Original Array: ";
    printArrayAss(arr, n);
    printArrayDes(arr , n);

    heapSort(arr, n);

    cout << "Sorted (Ascending): ";
    printArrayAss(arr, n);


    cout << "Sorted (Descending): ";
    printArrayDes(arr, n);

    return 0;
}