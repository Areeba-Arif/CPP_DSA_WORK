#include <iostream>
using namespace std;

struct LL_Queue{
    int data;
    LL_Queue* qNext;

};

LL_Queue* front= nullptr;
LL_Queue* rear= nullptr;



int EnQueue(int value)
{
    LL_Queue* newNode = new LL_Queue();
    newNode -> data = value; 
    newNode -> qNext = nullptr; 
    if(rear==nullptr && front ==nullptr){
        rear = newNode;
        front = newNode;
           
    }else{
        rear->qNext = newNode;
        rear = newNode;
    }
    cout<<"Element " << rear -> data << " inserted!" << endl;
}

int DeQueue()
{
    if(front==nullptr)
    {
        cout<<"Queue is Empty, Cannot Dequeued"<<endl;
        return -1;
    }

    LL_Queue* temp = front;
    front = front->qNext;

    if(front==nullptr)
    {
        rear = nullptr;
    }

    cout<<"Deleted element : "<<temp->data<<endl;
    free(temp);

}

void display(){
    if(front == nullptr){
        cout<<"Queue is Empty"<<endl;
        return;
    }

    LL_Queue* temp = front;
    cout<<"Queue: "<<endl;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->qNext;
    }

    cout<<"NULL"<<endl;
    
}



int main() {
    int yourChoice;

    while(true)
    {
        cout<<"------MENU-------"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice"<<endl;

         cin>>yourChoice;
        switch(yourChoice){
            case 1:
            {
                int value;
                cout<<"Enter value u want to add..";
                cin>>value; 
                EnQueue(value);
                break;
            }
             case 2:
            { 
                DeQueue();
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