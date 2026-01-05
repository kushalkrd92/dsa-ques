#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e){
  int pivot = s;
  int i = s, j = e;
  while(i < j){
    while(i < e && arr[i] <= arr[pivot])
      i++;
    while(j > s && arr[j] > arr[pivot])
      j--;
    if(i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[j], arr[pivot]);
  return j;
}

void quickSort(vector<int> &arr, int s, int e){
  if(s >= e)
    return;
  int partitionIndex = partition(arr, s, e);
  quickSort(arr, s, partitionIndex-1);
  quickSort(arr, partitionIndex+1, e);
}

int main(){
  vector<int> arr = {4, 2, 5, 1, 3};
  int s = 0, e = arr.size() - 1;
  quickSort(arr, s, e);
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}