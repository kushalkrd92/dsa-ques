#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target){
  int s = 0;
  int e = arr.size() - 1;
  while(s <= e){
    int mid = s + (e - s)/2;
    if(arr[mid] == target)
      return mid;
    else if(arr[mid] > target)
      e = mid -1;
    else  
      s = mid + 1;
  }
  return -1;
}

int main(){
  vector<int> arr = {-1,0,3,5,9,12};
  int target = 11;
  cout<<binarySearch(arr, target);
  return 0;
}