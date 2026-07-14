/*2Bt(t1 and T2 as input)
check both are qual 
check both hvae same strucutre
check both are mirror images of each other
*/

#include <iostream>
#include <string>

using namespace std;

// Definition of a Binary Tree Node
struct Node {
    string data;
    Node* left;
    Node* right;

    // Constructor to easily create a node
    Node(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Task 1: Check if two binary trees are equal (same structure and same data)
bool areEqual(Node* t1, Node* t2) {
    // If both are null, they are equal
    if (t1 == nullptr && t2 == nullptr) return true;
    
    // If only one is null, they are not equal
    if (t1 == nullptr || t2 == nullptr) return false;
    
    // Values must match, and both left and right subtrees must match
    return (t1->data == t2->data) && 
           areEqual(t1->left, t2->left) && 
           areEqual(t1->right, t2->right);
}

// Task 2: Check if two binary trees have the same structure (data can be different)
bool haveSameStructure(Node* t1, Node* t2) {
    // If both are null, they have the same structure
    if (t1 == nullptr && t2 == nullptr) return true;
    
    // If only one is null, structure is different
    if (t1 == nullptr || t2 == nullptr) return false;
    
    // Recursively check structure of left and right children
    return haveSameStructure(t1->left, t2->left) && 
           haveSameStructure(t1->right, t2->right);
}

// Task 3: Check if one tree is the mirror image of another
bool areMirrors(Node* t1, Node* t2) {
    // If both are null, they are mirrors
    if (t1 == nullptr && t2 == nullptr) return true;
    
    // If only one is null, they are not mirrors
    if (t1 == nullptr || t2 == nullptr) return false;
    
    // The data of the current nodes must be equal,
    // and the left subtree of t1 must mirror the right subtree of t2 (and vice versa)
    return (t1->data == t2->data) && 
           areMirrors(t1->left, t2->right) && 
           areMirrors(t1->right, t2->left);
}

// Helper function to clean up allocated memory
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // --- Setup Test Trees ---
    
    // Tree 1 (Root: "A")
    //     A
    //    / \
    //   B   C
    Node* T1 = new Node("A");
    T1->left = new Node("B");
    T1->right = new Node("C");

    // Tree 2 (Identical to Tree 1)
    //     A
    //    / \
    //   B   C
    Node* T2 = new Node("A");
    T2->left = new Node("B");
    T2->right = new Node("C");

    // Tree 3 (Same structure as Tree 1, different data)
    //     X
    //    / \
    //   Y   Z
    Node* T3 = new Node("X");
    T3->left = new Node("Y");
    T3->right = new Node("Z");

    // Tree 4 (Mirror image of Tree 1)
    //     A
    //    / \
    //   C   B
    Node* T4 = new Node("A");
    T4->left = new Node("C");
    T4->right = new Node("B");

    // --- Execute Tests ---
    
    cout << boolalpha; // prints true/false instead of 1/0

    cout << "Are T1 and T2 Equal? " << areEqual(T1, T2) << " (Expected: true)\n";
    cout << "Are T1 and T3 Equal? " << areEqual(T1, T3) << " (Expected: false)\n\n";

    cout << "Do T1 and T3 have the same structure? " << haveSameStructure(T1, T3) << " (Expected: true)\n\n";

    cout << "Are T1 and T4 mirror images? " << areMirrors(T1, T4) << " (Expected: true)\n";
    cout << "Are T1 and T2 mirror images? " << areMirrors(T1, T2) << " (Expected: false)\n";

    // --- Clean Up Memory ---
    deleteTree(T1);
    deleteTree(T2);
    deleteTree(T3);
    deleteTree(T4);

    return 0;
}