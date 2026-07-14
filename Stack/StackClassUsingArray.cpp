#include <iostream>
using namespace std;

class Stack{
    int* arr; 
    int top;
    int capacity;

public:

    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x){
        if(isFull()){
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        } else {
            return -1;
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    // EXTRA (important for understanding)
    void display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";
        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }

        /*
        for(int i = 0; i <= top ; i++){
            cout << arr[i] << " ";
        }
        */
        cout << endl;
    }
};

int main() {

    Stack s(5);  // create stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.display();

    return 0;
}