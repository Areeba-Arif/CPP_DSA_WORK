#include <iostream>
#include <stack>
using namespace std;

struct ExpressionTree
{
    char data;
    ExpressionTree* left;
    ExpressionTree* right;
};


//create new node

ExpressionTree* createNode(char val)
{
    ExpressionTree* temp = new ExpressionTree;
    temp->data = val;
    temp->left=temp->right = nullptr;
    return temp;
}


bool isOperand(char c) {
    return (c >= '0' && c <= '9') || 
           (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z');
}


ExpressionTree* BuildTree(string postfix)
{
    stack<ExpressionTree*> s ;

    for(int i=0; i<postfix.length(); i++)
    {
        char c = postfix[i];

        if(isOperand(c))
        {
            s.push(createNode(c));
        }

        else
        {
            //operator

            ExpressionTree* opNode = createNode(c);

            ExpressionTree* right = s.top(); s.pop();
            ExpressionTree* left = s.top(); s.pop();

            opNode->right = right;
            opNode->left = left;

            s.push(opNode);
        }


    }

    return s.top();
}



//display


//tree traversal

void inorder(ExpressionTree* root) {
    if (root) {
        if(root->left) cout << "(";
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        if(root->right) cout << ")";
    }
}

void preorder(ExpressionTree* root) {
    if (root) {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(ExpressionTree* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}


int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    ExpressionTree* root = BuildTree(postfix);

    cout << "\nInorder (Infix): ";
    inorder(root);

    cout << "\nPreorder (Prefix): ";
    preorder(root);

    cout << "\nPostorder (Postfix): ";
    postorder(root);

    return 0;
}