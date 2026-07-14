#include <iostream>
#include <algorithm>
using namespace std;

int partition ( int arr[] , int left , int right )
{
    int pivot = ( left + right ) / 2;

    while ( left < right )
    {
        while ( right > pivot )
        {
            if ( arr[pivot] > arr[right] )
            {
                swap ( arr[pivot] , arr[right] );
                pivot = right;
                break;
            }
            else
            {
                right--;
            }
        }

        while ( left < pivot )
        {
            if ( arr[pivot] < arr[left] )
            {
                swap ( arr[pivot] , arr[left] );
                pivot = left;
                break;
            }
            else
            {
                left++;
            }
        }
    }

    return pivot;
    




}


/*int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // last element
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}*/

void quickSort ( int arr[] , int left , int right )
{
    if ( left < right )
    {
        int pi = partition ( arr , left , right );
        quickSort ( arr , left , pi - 1);
        quickSort ( arr , pi + 1 , right);
    }
}

int main() {
    
    int n;

    cout<<"Enter the number of elements : ";
    cin>>n;

    int number[n];
    cout<<"Enter "<< n <<" values :"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>number[i];
    }

    cout<<"\n================Original Array ================";
    for(int i=0; i<n ; i++ )
    {
        cout<< number[i] <<" ";
    }

    quickSort( number , 0 , n - 1);
    cout<<"\n===============Sorted Array ===================";
    for(int i=0; i<n ; i++ )
    {
        cout<< number[i] <<" ";
    }

    cout<<endl;


    
    return 0;
}