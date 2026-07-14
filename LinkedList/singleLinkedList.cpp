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
    temp = (LL_Node*)malloc(sizeo f(LL_Node));

    temp->data= value;
    temp->next=NULL;

    if(list==NULL){
        list = temp;
    }else{
        LL_Node* curr = list;
        while(curr->next!=NULL){
            curr = curr->next;
        }

        curr->next = temp;
    }

}
int search(int value){
    if(list==NULL){
        cout<<"List is empty"<<endl;
        return -1;
    }
    LL_Node* current = list;
    int position = 0;
    while(current!=NULL){
        position++;
        if(current->data == value)
        {
            return position;
        }
        current = current->next;
    }

    return -1;
}

void delt(int value)
{
    LL_Node* curr = list;
    LL_Node* prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == value)
        {
            // First node
            if (prev == NULL)
                list = curr->next;
            else
                prev->next = curr->next;

            free(curr);   // or delete curr if you used new
            cout << "Deleted successfully!";
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Value not found!";
}



void display(){
    LL_Node* curr = list;
    if(curr==NULL){
        cout << "List is empty!" << endl;
        return;
    }
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}




int main() {
    int yourChoice = 0;
    
    while(yourChoice != 5){
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
                delt(key);
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
