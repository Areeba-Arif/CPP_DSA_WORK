#include <iostream>
using namespace std;
void insertionSort(int arr[] , int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while (prev>=0 && arr[prev]>curr)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
        
    }
}


void displayArr(int arr[] , int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int count;
    int arr[100];
    cout<<"How many numbers you want to add?";
    cin>>count;
    for(int i=0; i<count; i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>arr[i]; 
    }

    insertionSort(arr , count);
    cout<<"Sorted Array: " <<endl;
    displayArr(arr , count);
 
    return 0;
}