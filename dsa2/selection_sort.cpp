#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) {
  int n = arr.size();
  for(int i = 0; i<n-1; i++){
    int minIndex = i;
    for(int j = i+1; j<n; j++){
      if(arr[j] < arr[minIndex])
        minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
}

int main(){
  vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 8, 3, 2, 1};
  selectionSort(arr);
  for(int i = 0; i<arr.size(); i++)
    cout<<arr[i]<<" ";
  return 0;
}