#include <iostream>
#include<stdlib.h>
using namespace std;

struct BSTNode  
{
    int data ; 
    BSTNode *left;
    BSTNode *right;
};

BSTNode *Root = NULL;

BSTNode *insert(BSTNode *curr ,  int value)
{//
    BSTNode *temp;

    if(curr==NULL)
    {
        temp = (BSTNode*)malloc(sizeof(BSTNode));
        temp->data = value;
        temp->left = temp->right = NULL ; 
        return temp;
    }
    
    if(value < curr->data )
    {
        curr->left = insert(curr->left , value);
    }
    else
    {
        curr->right = insert(curr->right , value);
    }

    return curr;

}


void search(BSTNode *curr , int  value)
{
    if(curr == NULL)
    {
        cout<<"No value found!"<<endl;
        return;
    }

    if(value==curr->data)
    {
        cout<<"Value Found"<<endl;
        return;
    }

    if(value<curr->data)
    {
        search(curr->left , value);
    }
    else
    {
        search(curr->right , value);
    }

}



BSTNode* findMin(BSTNode *node)
{
    while (node->left!=NULL)
    {
        node = node->left;
    }
    return node;
    
}

BSTNode* deleteNode(BSTNode* curr, int value) {
    if (curr == NULL) return curr;

    if (value < curr->data) {
        curr->left = deleteNode(curr->left, value);
    } else if (value > curr->data) {
        curr->right = deleteNode(curr->right, value);
    } else {
        // Case 1 & 2: No child or one child
        if (curr->left == NULL) {
            BSTNode* temp = curr->right;
            free(curr);
            return temp;
        } else if (curr->right == NULL) {
            BSTNode* temp = curr->left;
            free(curr);
            return temp;
        }
        // Case 3: Two children
        BSTNode* temp = findMin(curr->right);
        curr->data = temp->data;
        curr->right = deleteNode(curr->right, temp->data);
    }
    return curr;
}


void inOrderTraversal(BSTNode *curr)
{
    if(curr!=NULL)
    {
        inOrderTraversal(curr->left);
        cout<<curr->data <<" ";
        inOrderTraversal(curr->right);

    }
}

void preOrderTraversal(BSTNode *curr)
{
    if(curr!=NULL)
    {  
        cout<<curr->data <<" ";
        preOrderTraversal(curr->left);
        preOrderTraversal(curr->right);

    }
}

void postOrderTraversal(BSTNode *curr)
{
    if(curr!=NULL)
    {
        postOrderTraversal(curr->left);
        postOrderTraversal(curr->right);
        cout<<curr->data <<" ";

    }
}


int main() {
    int yourChoice = 0;
    
    while(true){
        cout <<"\n--- MENU ---" << endl;
        cout <<"1. Insert Value in BST" << endl;
        cout<<"2. Search Value in BST"<<endl;
        cout<<"3. Delete Value in BST"<<endl;
        cout <<"4. InOrder Traversal" << endl;
        cout <<"5. PreOrder Traversal" << endl;
        cout <<"6. PostOrder Traversal" << endl;
        cout <<"7. Exit" << endl;
        cout <<"Enter your choice: "<<endl;
        cin>>yourChoice;
        switch(yourChoice){
            case 1:
            {
                int value;
                cout<<"Enter value u want to add "<<endl;
                cin>>value;

                Root = insert(Root , value);
                
                break;
            }
            case 2:
            {   
                int value;
                cout<<"Search : "<<endl;
                cin>>value;
                search(Root , value);
                break;
            }
            case 3:
            {
                int val;
                cout << "Delete value: "; 
                cin >> val;
                Root = deleteNode(Root, val);
                break;

            }
            case 4:
            {
                inOrderTraversal(Root);
                break;
            }
             case 5:
            {
                preOrderTraversal(Root);
                break;
            }
             case 6:
            {
                postOrderTraversal(Root);
                break;
            }
            case 7:
            {
                cout << "Exiting..." << endl;
                return 0;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
            }





        }
    }
    


    
   return 0;
}
