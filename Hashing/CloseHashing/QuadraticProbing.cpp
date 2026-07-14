#include <iostream>
using namespace std;

int hashtable[10];
int flag[10];

void insert(int value)
{
    int index = value % 10;

    int i = 0;
    int start = index;

    while (flag[index] == 1)
    {
        i++;
        index = (start + i*i) % 10;
        
        if(i == 10){
            cout << "hash table is full";
            return;
        }
    }

    hashtable[index] = value;
    flag[index] = 1;
}

void search(int value)
{
    int index = value % 10;

    int i = 0;
    int start = index;
    while (flag[index] != 0)
    {
        if (hashtable[index] == value)
        {
            cout << "value is fount at index: " << index << endl;
            return;
        }

        i++;
        index = (start + i*i) % 10;

        if (i == 10)
        {
            break;
        }
    }

    cout << "not found" << endl;
}

void display()
{
    for (int i = 0; i < 10; i++)
    {
        if (flag[i] == 1)
            cout << i << "\t" << hashtable[i] << endl;
        else
            cout << i << "\t-\n";
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        flag[i] = 0;
    }

    int choice, exitflag = 0, val;

    while (exitflag == 0)
    {
        cout << "\n\nMENU.........\n"
             << "1. Insert\n"
             << "2. Search\n"
             << "3. Display\n"
             << "4. exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            insert(val);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
            break;

        case 3:
            cout << "\nDISPLAY EMLEMENT\n";
            display();
            break;
        case 4:
            exitflag = 1;
            cout << "Program exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
