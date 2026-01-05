#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  for(int i = 0; i<n; i++){
    bool swapped = false;
    for(int j = 0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(!swapped)
      break;
  }
}

int main(){
  vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 8, 3, 2, 1};
  bubbleSort(arr);
  for(int i = 0; i<arr.size(); i++)
    cout<<arr[i]<<" ";
  return 0;
}
