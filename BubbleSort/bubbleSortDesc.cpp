#include<iostream>
using namespace std;

void bubbbleSort(int arr[] , int n){
    for(int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
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