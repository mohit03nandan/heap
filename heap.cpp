#include <iostream>

using namespace std;

class heap{
    public:
      int arr[100]; // array to store heap elements
      int size; // size of heap
      
      heap(){ // constructor to initialize heap
          arr[0] = -1; // dummy value at index 0
          size = 0; // heap is empty
      }
      
      void insert(int val){ // function to insert an element into the heap
          size = size + 1; // increase size of heap
          int index = size; // index of inserted element in array
          arr[index] = val; // insert element at end of array
          
          // bubble up the element to its correct position in the heap
          while(index>1){
              int parent = index/2; // index of parent element
              if(arr[parent] < arr[index]){ // if parent is smaller, swap with child
                  swap(arr[parent] , arr[index]);
                  index = parent; // update index to parent's index
              }
              else{
                  return; // parent is larger, element is in correct position
              }
          }
      }
      
      void print(){ // function to print all elements in the heap
          for(int i = 1; i<= size ; i++){
              cout<<arr[i]<<" "; // print each element in the array
          }cout<<endl; // print new line after all elements have been printed
      }
      
      
      void deletefromheap(){ // function to delete root element from heap
          if(size == 0){ // if heap is empty, there is nothing to delete
              cout<<"nothing to delete"<<endl;
              return;
          }
          
          arr[1] = arr[size]; // replace root with last element in heap
          size--; // decrease size of heap
          
          // bubble down the new root to its correct position in the heap
          int i = 1; // index of current element
          while(i<size){
              int leftindex = 2*i; // index of left child element
              int rightindex = 2*i + 1; // index of right child element
              
              if(leftindex < size && arr[i] < arr[leftindex]){ // if left child is larger, swap with parent
                  swap(arr[i],arr[leftindex]);
                  i = leftindex; // update index to left child's index
              }
              else if(rightindex < size && arr[i] < arr[rightindex] ){ // if right child is larger, swap with parent
                  swap(arr[i],arr[rightindex]);
                  i = rightindex; // update index to right child's index
              }
              else{
                  return; // parent is larger than both children, element is in correct position
              }
          }
          
      }
};

int main()
{
    heap h; // create a heap object
    h.insert(50); // insert elements into heap
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print(); // print all elements in heap
    
    h.deletefromheap(); // delete root element from heap
    h.print(); // print updated heap
    
    return 0; // end of program
} 
