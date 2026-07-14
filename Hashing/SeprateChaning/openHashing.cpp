#include <iostream>
using namespace std;


struct HashNode
{
    int data = -1;
    HashNode* next;
};



HashNode hashTable[10];

void insert(int value)
{
    int idx = value % 10;

    if(hashTable[idx].data == -1)
    {
        hashTable[idx].data = value;
    }
    else
    {
        //chaining...
        HashNode* temp = (HashNode*)malloc(sizeof(HashNode));
        temp -> data = value;
        temp ->next = NULL;
        HashNode* curr = hashTable[idx].next;
        if(curr==NULL)
        {
            hashTable[idx].next = temp;
        }
        else
        {
            while(curr->next!=NULL)
            {
                curr = curr->next;
            }
            //link new node at the end 
            curr->next = temp;
        }
        
    }
}

void search(int value)
{
    int idx =  value % 10;

    if(hashTable[idx].data== -1)
    {
        cout << "empty"<<endl;
        return;
    }

    HashNode* curr = hashTable[idx].next;
    while(curr!=NULL)
    {
        if(curr->data == value )
        {
            cout<<"Value " << value << " found at index " <<idx <<"!" << endl;
        }

        curr = curr->next;
    }

    cout << "Value " << value << " not found in the chain. " <<endl;
 


}


void display()
{
    cout<<"\n-----Hash Table-------"<<endl;

    for(int i=0; i<10; i++)
    {
        cout << "[" << i << "]:";
        if(hashTable[i].data==-1)
        {
            cout<< "Empty";
        }
        else
        {   
            cout<<hashTable[i].data << " ->";
            HashNode* curr = hashTable[i].next;
            while(curr!=NULL)
            {
                cout << curr->data << (curr->next ? " -> " : "");
                curr = curr->next;
            }
        }
        cout<<endl;
    }
}


int main() {

    int yourChoice;
    
    while(true){
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert" << endl;
        cout<<"2. Search"<<endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: "<<endl;
        cin>>yourChoice;
        switch(yourChoice){
            case 1:
            {
                int value;
                cout<<"Enter value: "<<endl;
                cin>>value;
                insert(value);
                break;
            }
            case 2:
            {   
                int value;
                cout<<"Enter value: "<<endl;
                cin>>value;
                search(value);
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
    