#include <iostream>
#include <vector>
using namespace std;

// using dynamic memory 
void merge(vector<int> &arr, int i, int j){
  int mid = i + (j - i)/2;
  int len1 = mid - i + 1;
  int len2 = j - mid;
  int *arr1 = new int[len1];
  int *arr2 = new int[len2];

  int k = i;         // p -> dynamic array index, k -> original array index
  for(int p = 0; p<len1; p++){
    arr1[p] = arr[k];
    k++;
  }
  for(int p = 0; p<len2; p++){
    arr2[p] = arr[k];
    k++;
  }

  k = i;
  int index1 = 0, index2 = 0;
  while(index1 < len1 && index2 < len2){
    if(arr1[index1] < arr2[index2]){
      arr[k] = arr1[index1];
      k++;
      index1++;
    }
    else{
      arr[k] = arr2[index2];
      index2++;
      k++;
    }
  }
  while(index1 < len1){
    arr[k] = arr1[index1];
    index1++;
    k++;
  }
  while(index2 < len2){
    arr[k] = arr2[index2];
    index2++;
    k++;
  }
  delete[] arr1;
  delete[] arr2;
}

// using vector
void merge2(vector<int> &arr, int i, int j){
  int mid = i + (j - i)/2;
  int len1 = mid - i + 1;
  int len2 = j - mid;
  vector<int> arr1(len1), arr2(len2);

  int k = i;
  for(int p = 0; p<len1; p++){
    arr1[p] = arr[k];
    k++;
  }
  for(int p = 0; p<len2; p++){
    arr2[p] = arr[k];
    k++;
  }

  k = i;
  int index1 = 0, index2 = 0;
  while(index1 < len1 && index2 < len2){
    if(arr1[index1] < arr2[index2]){
      arr[k] = arr1[index1];
      k++;
      index1++;
    }
    else{
      arr[k] = arr2[index2];
      index2++;
      k++;
    }
  }
  while(index1 < len1){
    arr[k] = arr1[index1];
    index1++;
    k++;
  }
  while(index2 < len2){
    arr[k] = arr2[index2];
    index2++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int i, int j){
  if(i >= j)
    return;
  int mid = i + (j - i)/2;
  mergeSort(arr, i, mid);
  mergeSort(arr, mid+1, j);
  merge(arr, i, j);
}

int main(){
  vector<int> arr = {3, 4, 1, 6, 2, 5, 7};
  int i = 0, j = arr.size() - 1;
  mergeSort(arr, i, j);
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}