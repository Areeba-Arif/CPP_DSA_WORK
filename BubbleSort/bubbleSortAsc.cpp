#include<iostream>
using namespace std;

bool isSorted(int arr[] , int n){
    for(int i=0; i< n-1; i++){
        if(arr[i]>arr[i+1]){
            return false ; //unsorted pair found!
        }
    }
    return true; //sorted 
}

void bubbbleSort(int arr[] , int n){
    if(isSorted(arr , n)){
        cout<<"Array is already sorted!"<<endl;
        return;
    }else{
        cout<<"Array is not sorted , Let's sort the array"<<endl;
    }

    bool swapped;
    for(int i=0; i<n-1; i++)
    {   
        swapped=false;
        for (int j=0; j<n-i-1; j++)  // at the end of one pass of this the last element is sorted 
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        //if no two element were swapped, then array is already sorted
        if(!swapped) {
            break ;
        }
    }
    

    
}

void printArr(int arr[] , int n){
    for(int i=0; i<n; i++){ //to print and to check the stabality if we use duplicates
        cout<<arr[i]<<"( "<<i<<") ";
        cout<<endl;
    }
}
int main(){
    int arr[] = {4 , 1 , 4, 5 , 3 , 5 , 6, 5 , 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbbleSort(arr , n);
    printArr(arr , n);
    return 0;
}