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

// --- TASK FUNCTIONS ---

// Task 1: Check if two binary trees are equal (same structure and same data)
bool areEqual(Node* t1, Node* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    
    return (t1->data == t2->data) && 
           areEqual(t1->left, t2->left) && 
           areEqual(t1->right, t2->right);
}

// Task 2: Check if two binary trees have the same structure (data can be different)
bool haveSameStructure(Node* t1, Node* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    
    return haveSameStructure(t1->left, t2->left) && 
           haveSameStructure(t1->right, t2->right);
}

// Task 3: Check if one tree is the mirror image of another
bool areMirrors(Node* t1, Node* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    
    return (t1->data == t2->data) && 
           areMirrors(t1->left, t2->right) && 
           areMirrors(t1->right, t2->left);
}

// --- NEW FUNCTION: Print BST in Descending Order ---
// We visit: Right Subtree -> Root -> Left Subtree
void printDescending(Node* root) {
    if (root == nullptr) return;

    printDescending(root->right);   // Go to the larger values first
    cout << root->data << " ";      // Print the current node
    printDescending(root->left);    // Go to the smaller values last
}

// Helper function to insert nodes into a Binary Search Tree
Node* insert(Node* root, string val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Helper function to clean up allocated memory
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // --- Setup Test Trees (For Tasks 1, 2, 3) ---
    Node* T1 = new Node("A");
    T1->left = new Node("B");
    T1->right = new Node("C");

    Node* T2 = new Node("A");
    T2->left = new Node("B");
    T2->right = new Node("C");

    Node* T3 = new Node("X");
    T3->left = new Node("Y");
    T3->right = new Node("Z");

    Node* T4 = new Node("A");
    T4->left = new Node("C");
    T4->right = new Node("B");

    // --- Create a Binary Search Tree (For Sorting Task) ---
    // Let's insert letters in random order: M, G, R, A, K, T
    Node* bstRoot = nullptr;
    bstRoot = insert(bstRoot, "M");
    bstRoot = insert(bstRoot, "G");
    bstRoot = insert(bstRoot, "R");
    bstRoot = insert(bstRoot, "A");
    bstRoot = insert(bstRoot, "K");
    bstRoot = insert(bstRoot, "T");

    // --- Execute Tests ---
    cout << boolalpha; // Prints true/false instead of 1/0

    cout << "=== Part 1: Previous Tasks ===\n";
    cout << "Are T1 and T2 Equal? " << areEqual(T1, T2) << "\n";
    cout << "Do T1 and T3 have the same structure? " << haveSameStructure(T1, T3) << "\n";
    cout << "Are T1 and T4 mirror images? " << areMirrors(T1, T4) << "\n\n";

    cout << "=== Part 2: Sorting in Descending Order ===\n";
    cout << "BST Nodes printed in descending order: ";
    printDescending(bstRoot);
    cout << "\n"; // Expected Output: T R M K G A 

    // --- Clean Up Memory ---
    deleteTree(T1);
    deleteTree(T2);
    deleteTree(T3);
    deleteTree(T4);
    deleteTree(bstRoot);

    return 0;
}