#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int target, int index, bool &flag)
{
    // Base Case
    if(index == size)
        return;

    // Check current element
    if(arr[index] == target)
    {
        flag = true;
        cout << "Target found at index " << index << endl;
    }

    // Check next index
    linearSearch(arr, size, target, index + 1, flag);
}

int main()
{
    int input[] ={22, 55, 13, 45, 76 , 22 , 34, 1, 10, 20,33, 13 , 22 , 34, 45};
    int size = sizeof(input)/sizeof(input[0]);

    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    bool flag = false;

    linearSearch(input, size, target, 0, flag);

    if(!flag)
        cout<<"Target not found!"<<endl;

    return 0;
}