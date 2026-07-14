#include <iostream>
using namespace std;

struct DL_Node
{
    int data;
    DL_Node* next;
    DL_Node* prev;
};

DL_Node* head = NULL;
DL_Node* tail = NULL;

void insert(int value){
    //create new node
    DL_Node* temp = new DL_Node;
    temp->data = value;
    temp->next = NULL;

    //1)if list is empty
    if(head==NULL){
        temp->prev = NULL;
        head = tail = temp;
    }else{
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

int search(int value) {
    // If list is empty
    if (head == NULL) {
        cout << "List is empty" << endl;
        return -1;
    }

    DL_Node* current = head;
    int position = 0;

    // Traverse from head to tail
    while (current != NULL) {
        position++;
        if (current->data == value)
            return position;
        current = current->next;
    }

    return -1;
}



void delete_node(int value) {
    // If list is empty
    if (head == NULL) {
        cout << "LIST IS EMPTY";
        return;
    }

    DL_Node* current = head;

    // Traverse list
    while (current != NULL) {
        if (current->data == value) {

            // Case 1: Only one node in list
            if (head == tail) {
                delete current;
                head = tail = NULL;
            }
            // Case 2: Deleting head node
            else if (current == head) {
                head = head->next;
                head->prev = NULL;
                delete current;
            }
            // Case 3: Deleting tail node
            else if (current == tail) {
                tail = tail->prev;
                tail->next = NULL;
                delete current;
            }
            // Case 4: Deleting middle node
            else {
                current->prev->next = current->next;     //current ka prev or prev ka next equal hojaiga curr k next sai
                current->next->prev = current->prev;     //current ka next or next ka prev equal hojaiga curr k prev sai
                delete current;
            }

            cout << "DELETE SUCCESSFULLY";
            return;
        }

        current = current->next;
    }

    // Value not found
    cout << "VALUE DOES NOT EXIST";
}


//display list from head to tail
void display_forward(){
    //chck if the list is empty 
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    DL_Node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

//display list from tail to head
void display_backward(){
  //chck if the list is empty 
    if(tail==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    DL_Node* curr = tail;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display Forward" << endl;
        cout << "5. Display Backward" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int count, value;
            cout << "How many numbers you want to add? ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> value;
                insert(value);
            }
            cout << "Values inserted successfully!" << endl;
            break;
        }

        case 2: {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int pos = search(key);
            if (pos != -1)
                cout << "Value found at position: " << pos << endl;
            else
                cout << "Value not found!" << endl;
            break;
        }

        case 3: {
            int key;
            cout << "Enter value to delete: ";
            cin >> key;
            delete_node(key);
            break;
        }

        case 4:
            display_forward();
            break;

        case 5:
            display_backward();
            break;

        case 6:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
