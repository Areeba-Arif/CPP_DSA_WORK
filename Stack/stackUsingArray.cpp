// #include <iostream>
// using namespace std;

// int stack[10];
// int top = 0;

// void push(int value){
//     if(top == 10){
//         cout << "Stack overflow!" << endl;
//         return;
//     }
//     stack[top] = value;
//     top++;
// }

// int pop(){
//     if(top == 0){
//         cout << "Stack underflow!" << endl;
//         return -1;   // error value
//     }
//     top--;
//     return stack[top];
// }

// void display(){
//     if(top == 0){
//         cout << "Stack is empty!" << endl;
//         return;
//     }
//     // for(int i = 0; i < top; i++){
//     //     cout << stack[i] << " ";
//     // }
//     for(int i=top-1; i>=0; i--){
//         cout<<stack[i]<<" ";
//     }
//     cout << endl;
// }

// int main() {
//     int yourChoice;
    
//     while(true){
//         cout << "\n--- MENU ---" << endl;
//         cout << "1. Push(insert)" << endl;
//         cout<<"2. Pop(remove)"<<endl;
//         cout << "3. Display" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter your choice: "<<endl;
//         cin>>yourChoice;
//         switch(yourChoice){
//             case 1:
//             {
//                 int value;
//                 cout<<"Enter value u want to add..";
//                 cin>>value; 
//                 push(value);
                
//                 break;
//             }
//              case 2:
//             { 
//                 pop();
//                 break;
//             }
//             case 3:
//             {
//                 display();
//                 break;
//             }
//             case 4:
//             {
//                 cout << "Exiting..." << endl;
//                 return 0;
//             }
//             default:
//             {
//                 cout << "Invalid choice!" << endl;
//             }





//         }
//     }

//     return 0;
// }








#include <iostream>
using namespace std;

int stack[10];
int top = -1;

void push(int value){
    if(top == 9){
        cout << "Stack overflow!" << endl;
        return;
    }
    top++;
    stack[top] = value;
    
}

int pop(){
    if(top == -1){
        cout << "Stack underflow!" << endl;
        return -1;
    }

    int value = stack[top];
    top--;
    return value;
}

void display(){
    if(top == -1){
        cout << "Stack is empty!" << endl;
        return;
    }
    // for(int i = 0; i < top; i++){
    //     cout << stack[i] << " ";
    // }
    for(int i=top; i>=0; i--){
        cout<<stack[i]<<" ";
    }
    cout << endl;
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

