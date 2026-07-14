#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

// Use the standard namespace
using namespace std;

// Define the structure of the Binary Tree Node
struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

// 1. Insert elements left-to-right (Heap-like complete binary tree insertion)
void insert(Node*& root, string val) {
    Node* newNode = new Node(val);
    if (!root) {
        root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// 2. Find and create its mirror image (In-place mirror)
void mirror(Node* root) {
    if (!root) return;

    // Swap left and right child pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// 3. Helper: Perform Inorder traversal to find predecessor and successor on the fly
void findPredecessorSuccessorHelper(Node* root, const string& x, Node*& prev, Node*& pred, Node*& succ, bool& found) {
    if (root == nullptr) return;

    // Traverse Left Subtree
    findPredecessorSuccessorHelper(root->left, x, prev, pred, succ, found);

    // Process Current Node
    if (root->data == x) {
        found = true;
        pred = prev; // The node visited right before x is the predecessor
    } else if (prev != nullptr && prev->data == x) {
        succ = root; // The current node (visited right after x) is the successor
    }
    
    prev = root; // Update "previous" to be the current node before moving right

    // Traverse Right Subtree
    findPredecessorSuccessorHelper(root->right, x, prev, pred, succ, found);
}

// Wrapper function to find predecessor and successor
void findPredecessorSuccessor(Node* root, const string& x) {
    Node* prev = nullptr;
    Node* pred = nullptr;
    Node* succ = nullptr;
    bool found = false;

    findPredecessorSuccessorHelper(root, x, prev, pred, succ, found);

    if (!found) {
        cout << "Element \"" << x << "\" does not exist in the tree.\n";
        return;
    }

    cout << "Inorder Predecessor of \"" << x << "\": ";
    if (pred) cout << pred->data << "\n";
    else cout << "None (It is the first node in inorder traversal)\n";

    cout << "Inorder Successor of \"" << x << "\": ";
    if (succ) cout << succ->data << "\n";
    else cout << "None (It is the last node in inorder traversal)\n";
}

// 4. Find the level of any element x (Root is level 0)
int findLevel(Node* root, const string& x, int currentLevel = 0) {
    if (!root) return -1;
    if (root->data == x) return currentLevel;

    // Search left subtree
    int leftLevel = findLevel(root->left, x, currentLevel + 1);
    if (leftLevel != -1) return leftLevel;

    // Search right subtree
    return findLevel(root->right, x, currentLevel + 1);
}

// Helper: Find a node containing data x
Node* findNode(Node* root, const string& x) {
    if (!root) return nullptr;
    if (root->data == x) return root;

    Node* leftResult = findNode(root->left, x);
    if (leftResult) return leftResult;

    return findNode(root->right, x);
}

// Helper: Calculate height of a given subtree (Leaf node height = 0)
int calculateHeight(Node* node) {
    if (!node) return -1; 
    if (!node->left && !node->right) return 0;

    return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
}

// 5. Find the height of the node of any element x
void printHeightOfNode(Node* root, const string& x) {
    Node* target = findNode(root, x);
    if (!target) {
        cout << "Element \"" << x << "\" does not exist to find height.\n";
        return;
    }
    cout << "Height of node \"" << x << "\": " << calculateHeight(target) << "\n";
}

// Helper: Display tree in Level-Order for testing visual verification
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << "\n";
}

// Main Driver Program
int main() {
    Node* root = nullptr;

    // Build the tree as shown in the worksheet: A, B, E, C, D
    vector<string> elements = {"A", "B", "E", "C", "D"};
    for (const string& val : elements) {
        insert(root, val);
    }

    cout << "--- Level-Order Tree Representation ---\n";
    cout << "Original Tree: ";
    printLevelOrder(root);
    cout << "\n";

    // Testing Predecessor and Successor
    cout << "--- Predecessors and Successors ---\n";
    findPredecessorSuccessor(root, "B");
    cout << "\n";

    // Testing Level Lookup (Level 0 based)
    cout << "--- Node Levels ---\n";
    string targetLevel = "C";
    int level = findLevel(root, targetLevel);
    if (level != -1) {
        cout << "Level of \"" << targetLevel << "\": " << level << "\n";
    } else {
        cout << "Node \"" << targetLevel << "\" not found.\n";
    }
    cout << "\n";

    // Testing Height Lookup
    cout << "--- Node Heights ---\n";
    printHeightOfNode(root, "B");
    printHeightOfNode(root, "E");
    cout << "\n";

    // Testing Mirroring
    cout << "--- Mirroring Tree ---\n";
    mirror(root);
    cout << "Mirrored Tree (Level-Order): ";
    printLevelOrder(root);

    return 0;
}