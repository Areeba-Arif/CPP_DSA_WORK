#include<iostream>

using namespace std;

void BinarySearching(int arr[] , int size, int target){
    int left=0 , right = size-1, mid;
    int foundIdx=-1;
    while(left<=right){
        mid= (left+right)/2;

        if(target==arr[mid]){
            foundIdx = mid; 
        }
        if(target>arr[mid]){
            left = mid +1;
        }else{
            right = mid-1;
        }
    }

    if(foundIdx==-1){
        cout<<"Target not found!";
        return;
    }
    left=mid-1;
    while(left>=0 && arr[left]==target){
        left--;
    }
    right = mid+1;
    while(right<size  && arr[right]==target){
        right++;
    }
    for(int i=left+1; i<right; i++){
        cout<<"Target found at index "<<i<<endl;
    }
}

int main(){
    int n ;
    cout<<"Enter size of array";
    cin>>n;
    int input[n];

    cout<<"Enter "<<n <<" numebers!"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Value " <<i << ": ";
        cin>>input[i];
    }

    int target; 
    cout<<"Enter the target value: " ;
    cin>>target;


    BinarySearching(input , n , target);
    

  

    return 0;
}