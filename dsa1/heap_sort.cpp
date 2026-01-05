#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i){         // max heap
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;
  if(left < n && arr[largest] < arr[left])
    largest = left;
  if(right < n && arr[largest] < arr[right])
    largest = right;
  if(largest != i){                        // swap with parent if req
    swap(arr[largest], arr[i]);         
    heapify(arr, n, largest);
  } 
}

int main(){
  vector<int> arr = {5,1,1,2,0,0};
  int n = arr.size();
  // built heap
  for(int i = n/2; i >= 0; i--)
    heapify(arr, n, i);
  
  // heap sort
  while(n){
    n--;
    swap(arr[0], arr[n]);       // as the max element is in the 0th index
    heapify(arr, n, 0);             // to rearrange the max heap
  }

  for(int i: arr)
    cout<<i<<" ";
  return 0;
}