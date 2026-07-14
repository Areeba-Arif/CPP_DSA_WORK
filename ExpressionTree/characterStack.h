#include <iostream>
using namespace std;

struct SLL_Node{
    char data;
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