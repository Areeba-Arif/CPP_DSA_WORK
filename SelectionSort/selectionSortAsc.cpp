#include<iostream>
using namespace std;

void SelectionSort(int arr[] , int n){
    for(int i=0; i<n-1; i++){
        int min_Value = i;
        for(int j=i+1; j<n ; j++){
            if(arr[j]<arr[min_Value]){
                min_Value = j;
            }
        }

        swap(arr[i], arr[min_Value]);
    }
}

void PrintArr(int arr[] , int n){
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

    SelectionSort(arr , count);
    cout<<"Sorted Array: " <<endl;
    PrintArr(arr , count);
 
    return 0;
}