#include <iostream>
#include <vector>
using namespace std;

// here first and last elements could be peak element
int peakIndex(vector<int> arr){
  int i = 0;
  int j = arr.size() - 1;
  while(i < j){
    int mid = i + (j - i)/2;
    if(arr[mid] < arr[mid+1])
      i = mid + 1;
    else  
      j = mid;
  }
  return i;      // i or j both are same
}

// find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// here first and last elements could be peak element
int peakIndex2(vector<int> arr){
  int n = arr.size();
  if(n == 1) 
      return 0;
  if(arr[0] > arr[1]) 
      return 0;
  if(arr[n-1] > arr[n-2]) 
      return n-1;

  int i = 0;
  int j = n - 1;
  while(i < j){
    int mid = i + (j - i)/2;
    if(arr[mid] < arr[mid+1])
      i = mid + 1;
    else  
      j = mid;
  }
  return i;      // i or j both are same
}

// Return an array that consists of indices of peaks in the given array in any order.
// A peak is defined as an element that is strictly greater than its neighboring elements.
// The first and last elements of the array are not a peak.
vector<int> findPeaks(vector<int>& mountain) {
  int n = mountain.size();
  vector<int> ans;
  for(int i = 1; i < n-1; i++){
    if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1])
      ans.push_back(i);
  }
  return ans;
}

int main(){
  vector<int> arr = {0,10,5,2};
  vector<int> arr2 = {1,2,1,3,5,6,4,11};     // here two peaks are present at index 1 and 5. either is correct 

  cout<<peakIndex(arr)<<endl;
  cout<<peakIndex2(arr2)<<endl;
  vector<int> ans = findPeaks(arr2);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}