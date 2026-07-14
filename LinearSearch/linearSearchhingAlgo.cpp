#include <iostream>
using namespace std;


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // return index if found
        }
    }
    return -1; // return -1 if not found
}

int main() {
    int input[] = {22, 1, 56, 34, 98, 67, 52,34 , 81, 22};
    int size = sizeof(input) / sizeof(input[0]); // calculate array size
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    // Function call
    int result = linearSearch(input, size, target);

    if (result != -1) {
        cout << "Target Found at index " << result;
    } else {
        cout << "Target Not Found!";
    }

    return 0;
}