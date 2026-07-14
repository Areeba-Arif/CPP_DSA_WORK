/*
Step 1: Create a BST
Insert all values into the BST.
Zero (0) and negative numbers are also valid values, so insert them normally.

Example input:

50 30 70 20 40 60 80 0 -10 35


Step 2: Convert BST into an Array

Store the BST in an array using level order indexing.

For a node at index i

Left child = 2*i + 1
Right child = 2*i + 2


Step 3: Display the Array using Preorder

Now treat the array as a tree and perform preorder.

Preorder:

Root
Left
Right

Output:

50 30 20 0 -10 40 35 70 60 80




Step 4: Search in Array without Linear Search

You cannot simply scan the array.

Instead, use BST property.

Suppose we search 35.

Start at index 0.

*/



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// BST Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find required array size
int findHeight(Node* root)
{
    if(root == NULL)
        return 0;

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return max(left, right) + 1;
}

// Convert BST to Array
void BSTtoArray(Node* root, vector<int>& arr, int index) //index----The position where the current node should be stored.
{
    if(root == NULL)
        return;

    if(index >= arr.size())
        arr.resize(index + 1, INT_MIN);

    arr[index] = root->data;

    BSTtoArray(root->left, arr, 2*index + 1);
    BSTtoArray(root->right, arr, 2*index + 2);
}

// Preorder Traversal using Array
void preorderArray(vector<int>& arr, int index)
{
    if(index >= arr.size())
        return;

    if(arr[index] == INT_MIN)
        return;

    cout << arr[index] << " ";

    preorderArray(arr, 2*index + 1);

    preorderArray(arr, 2*index + 2);
}

// BST Search using Array
bool searchArrayBST(vector<int>& arr, int key)
{
    int index = 0;

    while(index < arr.size() && arr[index] != INT_MIN)
    {
        if(arr[index] == key)
            return true;

        if(key < arr[index])
            index = 2*index + 1;
        else
            index = 2*index + 2;
    }

    return false;
}

// Display Array
void displayArray(vector<int>& arr)
{
    cout << "Array Representation:\n";

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==INT_MIN)
            cout<<"NULL ";
        else
            cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    Node* root = NULL;

    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter values:\n";

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root=insert(root,x);
    }

    vector<int> arr;

    BSTtoArray(root,arr,0);

    displayArray(arr);

    cout<<"\nPreorder using Array:\n";
    preorderArray(arr,0);

    cout<<"\n\nEnter value to search: ";

    int key;
    cin>>key;

    if(searchArrayBST(arr,key))
        cout<<"Value Found";
    else
        cout<<"Value Not Found";

    return 0;
}