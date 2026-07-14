#include <iostream>
#include<stdlib.h>
using namespace std;

struct LL_Node{
    int data;
    LL_Node* next;
};


LL_Node* list = NULL;

void insert(int value){
    LL_Node* temp;
    // malloc(sizeof(LL_Node)) this will only return void address
    temp = (LL_Node*)malloc(sizeof(LL_Node));

    temp->data= value;

    if(list==NULL){
        list = temp;
        temp->next = list;
    }else{
        LL_Node* curr = list;
        while(curr->next!=list){
            curr = curr->next;
        }

        curr->next = temp;
        temp->next = list;
    }

}
int search(int value){
    if(list==NULL){
        cout<<"List is empty"<<endl;
        return -1;
    }
    LL_Node* current = list;
    int position = 0;
    do{
          position++;
        if(current->data == value)
        {
            return position;
        }
        current = current->next;

    }
    while(current!=list);
      

    return -1;
}

// /*
//     Function: delete_node
//     Purpose : Delete a node from circular linked list
// */
// void delete_node(int value) {
//     if (head == NULL) {
//         cout << "LIST IS EMPTY";
//         return;
//     }

//     LL_Node* current = head;
//     LL_Node* previous = tail;

//     // Case 1: Only one node in list
//     if (head == tail && head->data == value) {
//         delete head;
//         head = tail = NULL;
//         cout << "DELETE SUCCESSFULLY";
//         return;
//     }

//     // Traverse list
//     do {
//         if (current->data == value) {

//             // Case 2: Deleting head node
//             if (current == head) {
//                 head = head->next;
//                 tail->next = head;
//             }
//             // Case 3: Deleting tail node
//             else if (current == tail) {
//                 tail = previous;
//                 tail->next = head;
//             }
//             // Case 4: Deleting middle node
//             else {
//                 previous->next = current->next;
//             }

//             delete current;
//             cout << "DELETE SUCCESSFULLY";
//             return;
//         }

//         previous = current;
//         current = current->next;

//     } while (current != head);

//     cout << "VALUE DOES NOT EXIST";
// }

void delete_node(int value){
    if(list == NULL){
        cout << "LIST IS EMPTY";
        return;
    }

    LL_Node *current = list;
    LL_Node *previous = NULL;

    // Case 1: Only one node
    if(current->next == list && current->data == value){
        free(current);
        list = NULL;
        cout << "DELETE SUCCESSFULLY";
        return;
    }

    // Traverse circular list
    do{
        if(current->data == value){

            // Case 2: Deleting head
            if(current == list){
                LL_Node* last = list;
                while(last->next != list){
                    last = last->next;
                }

                list = list->next;
                last->next = list;
            }
            // Case 3: Deleting middle or last
            else{
                previous->next = current->next;
            }

            free(current);
            cout << "DELETE SUCCESSFULLY";
            return;
        }

        previous = current;
        current = current->next;

    } while(current != list);

    cout << "VALUE DOES NOT EXIST";
}




void display(){
    LL_Node* curr = list;
    if(list==NULL){
        cout << "List is empty!" << endl;
        return;
    }
    do{

        cout<<curr->data<<" ";
        curr = curr->next;
    }
    while(curr!=list);
    cout<<endl;
}




int main() {
    int yourChoice;
    
    while(true){
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert Numbers" << endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Delete"<<endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: "<<endl;
        cin>>yourChoice;
        switch(yourChoice){
            case 1:
            {
                int count , value;
                cout<<"How many numbers you want to add?";
                cin>>count;
                for(int i=0; i<count; i++){
                    cout<<"Enter value "<<i+1<<": ";
                    cin>>value; 
                    insert(value);
                }
                cout<<"Values inserted sucessfully!"<<endl;
                
                break;
            }
            case 2:
            {   
                int key;
                cout<<"Enter the number you want to search: "<<endl;
                cin>>key;
                int result = search(key);
                if(result!=-1)
                {
                    cout<<"Value found at position : "<<result<<endl;
                }else{
                    cout<<"Value not found!"<<endl;
                }
                break;
            }
            case 3:
            {
                int key;
                cout<<"Enter the number you want to delete?"<<endl;
                cin>>key;
                delete_node(key);
                break;

            }
            case 4:
            {
                display();
                break;
            }
            case 5:
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