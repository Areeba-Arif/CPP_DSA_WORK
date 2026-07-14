#include<iostream>
 
using namespace std;

//Search Function
int BinarySearching(int inputArr[] , int size , int target){
    int left =0 , right = size-1 , mid;

    while(left<=right){
        mid = (left+right)/2;
        if(target == inputArr[mid]){
            return mid;
        }
        if(target>inputArr[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"enter size of array!";
    cin>>n;

    int input[n]; //int* input = new int[n]

    cout<<"Enter " <<n <<" numbers!"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Value " <<i <<": ";
        cin>>input[i];
    }

    int target;
    cout<<"Enter the target value : ";
    cin>>target;

    int result = BinarySearching(input, n , target);

    if(result!=-1){
        cout<<"Target found at index " <<result <<endl;
    }else{
        cout<< "Value not found."<<endl;
    }
    return 0;
}