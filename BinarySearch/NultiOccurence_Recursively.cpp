#include<iostream>
using namespace std;

// ---------- Find First Occurrence ----------
int findFirst(int arr[], int left, int right, int target)
{
    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(arr[mid] == target)
    {
        // Check if it's first OR go left
        if(mid == 0 || arr[mid - 1] != target)
            return mid;
        else
            return findFirst(arr, left, mid - 1, target);
    }
    else if(target < arr[mid])
        return findFirst(arr, left, mid - 1, target);
    else
        return findFirst(arr, mid + 1, right, target);
}

// ---------- Find Last Occurrence ----------
int findLast(int arr[], int left, int right, int target, int size)
{
    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(arr[mid] == target)
    {
        // Check if it's last OR go right
        if(mid == size - 1 || arr[mid + 1] != target)
            return mid;
        else
            return findLast(arr, mid + 1, right, target, size);
    }
    else if(target < arr[mid])
        return findLast(arr, left, mid - 1, target, size);
    else
        return findLast(arr, mid + 1, right, target, size);
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted array:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    int first = findFirst(arr, 0, n - 1, target);
    int last  = findLast(arr, 0, n - 1, target, n);

    if(first == -1)
    {
        cout << "Target not found!";
        return 0;
    }

    for(int i = first; i <= last; i++)
    {
        cout << "Target found at index " << i << endl;
    }

    return 0;
}