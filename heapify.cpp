#include <iostream>

using namespace std;

// function to heapify a subtree with root at index i in an array of size n
void heapify(int arr[], int n , int i){
    int largest = i;  // Initialize largest as root
    int left = 2*i;   // left child index
    int right = 2*i + 1;   // right child index
    
    // If left child is larger than root
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    
    // If right child is larger than largest so far
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    
    // If largest is not root
    if(largest != i){
        swap(arr[largest],arr[i]);   // swap largest element with root
        heapify(arr,n,largest);   // recursively heapify the affected sub-tree
    }
}

int main()
{
    // sample array to be heapified
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;   // size of the heap

    // build heap by calling heapify on all non-leaf nodes starting from last non-leaf node
    for(int i = n/2; i>0 ; i--){
        heapify(arr,n,i);
    }cout<<endl;
    
    // print the heapified array
    cout<<"printing the array now"<<endl;
    for(int i = 1; i<=n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}
