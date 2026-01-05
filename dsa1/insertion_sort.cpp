#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
  int n = arr.size();
  for(int i = 1; i<n; i++){
    int temp = arr[i];
    int j = i-1;
    while(j >= 0){
      if(arr[j] > temp)
        arr[j+1] = arr[j];
      else 
        break;
      j--;
    }
    j++;
    arr[j] = temp;
  }
}

int main(){
  vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 8, 3, 2, 1};
  insertionSort(arr);
  for(int i = 0; i<arr.size(); i++)
    cout<<arr[i]<<" ";
  return 0;
}