#include <iostream>
#include <queue>
#include <vector>

// Use the standard namespace globally
using namespace std;

// Define the Node structure with float values
struct Node {
    float data;
    Node* left;
    Node* right;

    Node(float val) : data(val), left(nullptr), right(nullptr) {}
};

// 1. Insert a node level-by-level (heap-like structure)
Node* insertLevelOrder(Node* root, float val) {
    Node* newNode = new Node(val);
    if (root == nullptr) {
        return newNode;
    }

    // Use a queue to find the first empty child slot in level-order
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// 2. Search for element x in the tree
bool searchElement(Node* root, float x) {
    if (root == nullptr) return false;
    if (root->data == x) return true;
    
    // Search left and right subtrees
    return searchElement(root->left, x) || searchElement(root->right, x);
}

// Helper: Perform Inorder traversal to find predecessor and successor
void findPredecessorSuccessorHelper(Node* root, float x, Node*& prev, Node*& pred, Node*& succ, bool& found) {
    if (root == nullptr) return;

    // Traverse Left Subtree
    findPredecessorSuccessorHelper(root->left, x, prev, pred, succ, found);

    // Process Current Node ROOT 
    if (root->data == x) {
        found = true;
        pred = prev; // The node visited right before x
    } else if (prev != nullptr && prev->data == x) {
        succ = root; // The node visited right after x
    }
    
    prev = root; // Update the previous node before moving to the next

    // Traverse Right Subtree
    findPredecessorSuccessorHelper(root->right, x, prev, pred, succ, found);
}

// Wrapper function to find predecessor and successor
void findPredecessorSuccessor(Node* root, float x) {
    Node* prev = nullptr;
    Node* pred = nullptr;
    Node* succ = nullptr;
    bool found = false;

    findPredecessorSuccessorHelper(root, x, prev, pred, succ, found);

    if (!found) {
        cout << "Element " << x << " does not exist in the tree.\n";
        return;
    }

    cout << "Inorder Predecessor: ";
    if (pred) cout << pred->data << "\n";
    else cout << "None (It is the first node in inorder traversal)\n";

    cout << "Inorder Successor: ";
    if (succ) cout << succ->data << "\n";
    else cout << "None (It is the last node in inorder traversal)\n";
}

// 3. Find total number of nodes
int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to print tree in-order (for debugging/visualization)
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = nullptr;
    
    // Elements to insert into our tree
    vector<float> elements = {10.5f, 20.2f, 30.8f, 40.1f, 50.6f, 60.3f, 70.9f};
    
    cout << "Inserting elements in heap-like fashion: ";
    for (float val : elements) {
        cout << val << " ";
        root = insertLevelOrder(root, val);
    }
    cout << "\n\n";

    // 1. Total Nodes
    cout << "Total number of nodes: " << countNodes(root) << "\n";

    // Show the resulting Inorder sequence so predecessor/successor make sense
    cout << "Inorder sequence of the built tree: ";
    printInorder(root);
    cout << "\n\n";

    // 2. Search & Find Predecessor/Successor for a target 'x'
    float x = 20.2f; 
    cout << "Searching for target x = " << x << "...\n";
    if (searchElement(root, x)) {
        cout << "Element " << x << " found in the tree!\n";
        findPredecessorSuccessor(root, x);
    } else {
        cout << "Element " << x << " not found.\n";
    }

    return 0;
}