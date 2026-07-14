#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
    // Base Case: element not found
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    // Target found
    if(arr[mid] == target)
        return mid;

    // Search left half
    if(target < arr[mid])
        return binarySearch(arr, low, mid - 1, target);

    // Search right half
    return binarySearch(arr, mid + 1, high, target);
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    if(result != -1)
        cout << "Target found at index " << result;
    else
        cout << "Target not found!";

    return 0;
}