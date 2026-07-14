#include <iostream>
using namespace std;

//insert , search , delete , tree traversal

struct BST_Node{
    int data;
    BST_Node* left;
    BST_Node* right;
};

BST_Node* root = NULL;


BST_Node* insert(BST_Node* curr , int value)
{
    BST_Node* temp = (BST_Node*)malloc(sizeof(BST_Node));    
    if(curr==NULL)
    {
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }
    
    if(value < curr->data)
    {
        curr->left = insert(curr->left , value);
    }
    else
    {
        curr->right = insert(curr->right , value);
    }

    return curr;
}

void search(BST_Node* curr , int value)
{
    if(curr==nullptr)
    {
        cout<<"Not found!"<<endl;
        return;
    }
    if(value==curr->data)
    {
        cout<<"Found!"<<endl;
        return;
    }
    if(value<curr->data)
    {
        search(curr->left , value );
    }
    if(value > curr->data)
    {
        search(curr->right , value);
    }
}

BST_Node* findmin(BST_Node* node)
{
    while(node->left!=NULL)
    {
        node = node->left;
    }
    return node;
}

BST_Node* deleteNode(BST_Node* curr , int value)
{
    if(curr==nullptr)
    {
        return curr;
    }
    if(value<curr->data)
    {
        curr->left = deleteNode(curr->left , value);
    }
    else if(value>curr->data)
    {
        curr->right = deleteNode(curr->right , value);
    }
    else{
        //case 1 and 2(no child , 1 child)
        if(curr->left==NULL)
        {
            BST_Node* temp = curr->right;
            free(curr);
            return temp;
        }
        else if(curr->right == NULL)
        {
            BST_Node* temp = curr->left;
            free(curr);
            return temp;
        }

        //case 3(two child)--------find minum form the right sutree and replace it with the curr value

        BST_Node* temp = findmin(curr->right);
        curr->data = temp->data;
        curr->right = deleteNode(curr->right , temp->data);

    }
    
    return curr;
}

//TREE TRAVERSAL



BST_Node* inOrder(BST_Node* curr)
{
    if(curr!=NULL)
    {
        inOrder(curr->left);
        cout<<curr->data<<" ";
        inOrder(curr->right);
    }
    return curr;
}


BST_Node* postOrder(BST_Node* curr)
{
    if(curr!=NULL)
    {
        postOrder(curr->left);
        postOrder(curr->right);
        cout<<curr->data<<" ";
    }
    return curr;
}



BST_Node* preOrder(BST_Node* curr)
{
    if(curr!=NULL)
    {
        cout<<curr->data<<" ";
        preOrder(curr->left);
        preOrder(curr->right);
    }

    return curr;
}











int main()
{
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder: ";
    inOrder(root);

    cout << "\nDeleting 50...\n";
    root = deleteNode(root, 50);

    cout << "Inorder after delete: ";
    inOrder(root);

    return 0;
}