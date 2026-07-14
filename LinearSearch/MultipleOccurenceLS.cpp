#include<iostream>

using namespace std;

int main(){
    //repeatation in values
    //variable initialization
    int i=0 , flag=0;
    int input[] ={22, 55, 13, 45, 76 , 22 , 34, 1, 10, 20,33, 13 , 22 , 34, 45};
    int size = sizeof(input)/sizeof(input[0]);
    int target;
    cout<<"Enter the target value ";
    cin>>target;

    //loop to find the target indexes
    for(i=0; i<size; i++)
    {
        if(target==input[i]){
            flag=1;
            cout<<"Target found at index " << i << endl;
        }
    }

    //check if the target was never found
    if(flag==0){
        cout<<"Target not found!"<<endl;
    }

    return 0;
}