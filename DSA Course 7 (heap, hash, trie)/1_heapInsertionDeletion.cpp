#include <iostream>
using namespace std;

// max heap
class Heap {
  public:
    int arr[100];
    int size;
    Heap(){
      arr[0] = -1;
      size = 0;
    }

    void insert(int val){
      size += 1;
      int index = size;
      arr[index] = val;
      while(index > 1){
        int parent = index/2;
        if(arr[parent] < arr[index]){
          swap(arr[parent], arr[index]);
          index = parent;
        }
        else  
          return;
      }
    }

    // deleting the root node
    void deletion(){
      if(size == 0)
        return;
      
      arr[1] = arr[size];    // copying last node to root node 
      size--;
      int i = 1;
      while(i < size) {
        int left = 2*i;
        int right = 2*i + 1;
        if(left <= size && arr[i] < arr[left]){
          swap(arr[i], arr[left]);
          i = left;
        }
        else if(right <= size && arr[i] < arr[right]){
          swap(arr[right], arr[i]);
          i = right;
        }
        else 
          return;
      }
    }

    void print(){
      for(int i = 1; i<size; i++){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
};

// to check the heap is in correct order and if it is not then convert it to correct order
void heapify(int arr[], int n, int i){
  int largest = i;
  int left = 2*i;
  int right = 2*i + 1;
  if(left <= n && arr[largest] < arr[left])
    largest = left;
  if(right <= n && arr[largest] < arr[right])
    largest = right;
  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void printHeap(int arr[], int size){
  for(int i = 1; i<=size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {
  Heap h;
  h.insert(60);
  h.insert(50);
  h.insert(40);
  h.insert(30);
  h.insert(20);
  h.insert(10);
  h.insert(55);
  h.insert(70);
  h.print();
  h.deletion();
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;
  // since leaf nodes fron n/2+1 to n are aready heap so only applying the method on nodes from 1 to n/2 in reverse order
  for(int i = n/2; i>0; i--){      // built heap
    heapify(arr, n, i);
  }
  printHeap(arr, n);
  return 0;
}