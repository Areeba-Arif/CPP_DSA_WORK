#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem AnalysisFind Median ($M$): 
For any sorted array of elements, find the middle element.
Divide into Four Sets
Recursive Subtree Construction:
     For each subset, recursively build subtrees.
     Output level and height: Whenever a node is inserted/created, 
     we output the height and level of all nodes currently in the tree using a helper traversal.
*/




// 4-Way Tree Node Structure
struct TreeNode {
    int data;
    TreeNode *child1; // For subset S1 (<= M/2)
    TreeNode *child2; // For subset S2 (> M/2 and < M)
    TreeNode *child3; // For subset S3 (> M and < 3M/2)
    TreeNode *child4; // For subset S4 (>= 3M/2)
};

// Global Root pointer
TreeNode *Root = NULL;

// Helper function to calculate the height of a given node
int calculateHeight(TreeNode *curr) {
    if (curr == NULL) {
        return -1;
    }
    int h1 = calculateHeight(curr->child1);
    int h2 = calculateHeight(curr->child2);
    int h3 = calculateHeight(curr->child3);
    int h4 = calculateHeight(curr->child4);

    return max({h1, h2, h3, h4}) + 1;
}

// Traversal to print level and height of all nodes currently in the tree
void printLevelsAndHeights(TreeNode *curr, int level) {
    if (curr != NULL) {
        int height = calculateHeight(curr);
        cout << "Node: " << curr->data << " | Level: " << level << " | Height: " << height << endl;
        
        printLevelsAndHeights(curr->child1, level + 1);
        printLevelsAndHeights(curr->child2, level + 1);
        printLevelsAndHeights(curr->child3, level + 1);
        printLevelsAndHeights(curr->child4, level + 1);
    }
}

// Recursive function to build the tree
TreeNode* buildRecursiveTree(vector<int> S) {
    if (S.empty()) {
        return NULL;
    }

    // Find the median (middle element)
    int n = S.size();
    int midIdx = n / 2;
    int M = S[midIdx];

    // --- REPLACED MALLOC WITH NEW ---
    TreeNode *temp = new TreeNode; 
    temp->data = M;
    temp->child1 = temp->child2 = temp->child3 = temp->child4 = NULL;

    // If this is the absolute root of the tree, set our global Root variable
    if (Root == NULL) {
        Root = temp;
    }

    // Output tree status upon insertion of this node
    cout << "\n--- Node [" << M << "] Inserted. Current Tree Status: ---\n";
    printLevelsAndHeights(Root, 0);
    cout << "--------------------------------------------------\n";

    // Split array S into S1, S2, S3, S4 based on rules
    vector<int> S1, S2, S3, S4;
    double boundary1 = (double)M / 2.0;
    double boundary3 = 3.0 * (double)M / 2.0;

    for (int val : S) {
        if (val == M) continue; // Skip median

        if (val <= boundary1) {
            S1.push_back(val);
        } else if (val > boundary1 && val < M) {
            S2.push_back(val);
        } else if (val > M && val < boundary3) {
            S3.push_back(val);
        } else {
            S4.push_back(val);
        }
    }

    // Recursively assign to the 4 children
    temp->child1 = buildRecursiveTree(S1);
    temp->child2 = buildRecursiveTree(S2);
    temp->child3 = buildRecursiveTree(S3);
    temp->child4 = buildRecursiveTree(S4);

    return temp;
}

// Menu structure
int main() {
    int yourChoice = 0;
    
    while(true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Build Tree from Default Set" << endl;
        cout << "2. View Node Levels and Heights" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> yourChoice;

        switch(yourChoice) {
            case 1: {
                vector<int> S = {22, 44, 75, 90, 92, 99, 110, 112, 125, 130, 131};
                
                cout << "Sorting and preparing the initial set: ";
                sort(S.begin(), S.end());
                for(int val : S) cout << val << " ";
                cout << "\nBuilding 4-way tree..." << endl;

                Root = NULL; 
                Root = buildRecursiveTree(S);
                break;
            }
            case 2: {
                if (Root == NULL) {
                    cout << "Tree is empty! Please build the tree first (Option 1)." << endl;
                } else {
                    cout << "\n--- Full Tree Levels and Heights ---" << endl;
                    printLevelsAndHeights(Root, 0);
                }
                break;
            }
            case 3: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    }
    return 0;
}