#include <iostream>
#include <queue>
#include <vector>

// Using namespace std makes the code less cluttered for simple programs
using namespace std;

// 1. Define the Node structure with a float value
struct Node {
    float data;
    Node* left;
    Node* right;

    Node(float value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// 2. Build the binary tree in a level-order (heap-like) manner
Node* insertLevelOrder(Node* root, float value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        return newNode;
    }

    // Queue to find the first node that has an empty child
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Check the left child
        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        } else {
            q.push(temp->left);
        }

        // Check the right child
        if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// 3. Find/create the mirror image of the tree
void mirrorTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Swap the left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// 4. Helper function to print tree level-by-level for verification
void printLevelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << " | "; // Visual separator between levels
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;

    // Elements inserted in level-order matching the image: 89 -> 122 -> 12 -> 75 -> 99 -> 68
    vector<float> elements = {89.0f, 122.0f, 12.0f, 75.0f, 99.0f, 68.0f};

    for (float val : elements) {
        root = insertLevelOrder(root, val);
    }

    cout << "Original Tree (Level-order traversal):" << endl;
    printLevelOrder(root);
    cout << "---------------------------------------" << endl;

    // Mirror the tree
    mirrorTree(root);

    cout << "Mirrored Tree (Level-order traversal):" << endl;
    printLevelOrder(root);

    return 0;
}