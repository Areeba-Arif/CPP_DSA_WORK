#include <iostream>
using namespace std;

// ================= NODE =================
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

// ================= UTIL FUNCTIONS =================
int height(AVLNode* node) {
    if (node == NULL) return -1;
    return node->height;
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(AVLNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// ================= ROTATIONS =================

// RIGHT ROTATION (LL)
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = getMax(height(y->left), height(y->right)) + 1;
    x->height = getMax(height(x->left), height(x->right)) + 1;

    return x;
}

// LEFT ROTATION (RR)
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = getMax(height(x->left), height(x->right)) + 1;
    y->height = getMax(height(y->left), height(y->right)) + 1;

    return y;
}

// LEFT-RIGHT (LR)
AVLNode* rotateLeftRight(AVLNode* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// RIGHT-LEFT (RL)
AVLNode* rotateRightLeft(AVLNode* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);//node = the UNBALANCED node (root of that subtree)
}

// ================= INSERT =================
AVLNode* insert(AVLNode* node, int value) {

    // 1. Normal BST insertion
    if (node == NULL) {
        AVLNode* temp = new AVLNode();
        temp->data = value;
        temp->left = temp->right = NULL;
        temp->height = 0;
        return temp;
    }

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node; // no duplicates

    // 2. Update height
    node->height = getMax(height(node->left), height(node->right)) + 1;

    // 3. Get balance
    int balance = getBalance(node);

    // 4. Rotations

    // LL
    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    // RR
    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    // LR
    if (balance > 1 && value > node->left->data)
        return rotateLeftRight(node);

    // RL
    if (balance < -1 && value < node->right->data)
        return rotateRightLeft(node);

    return node;
}

// ================= FIND MIN =================
AVLNode* findMin(AVLNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// ================= DELETE =================
AVLNode* deleteNode(AVLNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // case 1 or 2: one child or no child
       if (root->left == NULL) {
            AVLNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            AVLNode* temp = root->left;
            delete root;
            return temp;
        }
         // Case 3: Two children
        else {
            AVLNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // if (root == NULL) return root;
    

    root->height = getMax(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0)
        return rotateLeftRight(root);

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0)
        return rotateRightLeft(root);

    return root;
}

// ================= SEARCH =================
bool search(AVLNode* root, int key) {
    if (root == NULL) return false;

    if (key == root->data) return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ================= DISPLAY =================
void inorder(AVLNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(AVLNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


// ================= MAIN =================
int main() {
    AVLNode* root = NULL;
    int choice, value;

    do {
        cout << "\n--- AVL TREE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display (Inorder)\n";
        cout << "5. Display (Preorder)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 4:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}