#include <iostream>
using namespace std;

struct SLL_Node{
    int data;
    SLL_Node *next;
};

SLL_Node *top = NULL;

void push(int value){
    SLL_Node *newNode = (SLL_Node*)malloc(sizeof(SLL_Node)); //new node
    newNode->data = value;
    newNode->next=NULL;
    if(top==NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
    cout<<value <<" Pushed to stack"<<endl;

}

void pop(){
    if(top==NULL){
        cout<<"Stack underflow"<<endl;
        return;
    }

    SLL_Node *temp = top;
    top = top->next;
    cout<<temp->data<<" Popped from stack";
    free(temp);

}

void display(){
    if(top==NULL){
        cout << "List is empty!" << endl;
        return;
    }
    SLL_Node* curr = top;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


int main() {
    int yourChoice;
    
    while(true){
        cout << "\n--- MENU ---" << endl;
        cout << "1. Push(insert)" << endl;
        cout<<"2. Pop(remove)"<<endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: "<<endl;
        cin>>yourChoice;
        switch(yourChoice){
            case 1:
            {
                int value;
                cout<<"Enter value u want to add..";
                cin>>value; 
                push(value);
                
                break;
            }
             case 2:
            { 
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
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