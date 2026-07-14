#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target, int index)
{
    // Base Case: End of array
    if (index == size)
        return -1;

    // If target found
    if (arr[index] == target)
        return index;

    // Recursive call for next element
    return linearSearch(arr, size, target, index + 1);
}

int main()
{
    int input[] = {22, 1, 56, 34, 98, 67, 52, 34, 81, 22};
    int size = sizeof(input) / sizeof(input[0]);

    int target;
    cout << "Enter target: ";
    cin >> target;

    int result = linearSearch(input, size, target, 0);

    if (result != -1)
        cout << "Target Found at index " << result;
    else
        cout << "Target Not Found!";

    return 0;
}