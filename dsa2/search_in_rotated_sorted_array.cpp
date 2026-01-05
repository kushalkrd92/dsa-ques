#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int k){
  int s = 0, e = arr.size() - 1;
  while(s <= e){
    int mid = s + (e - s)/2;
    if(arr[mid] == k)
      return mid;
    else if (arr[s] <= arr[mid]){              // the left half is sorted
      if(arr[s] <= k && k <= arr[mid])  
        e = mid - 1;
      else 
        s = mid + 1;
    }
    else {                                       // the right half is sorted (arr[mid] <= arr[e])
      if(arr[mid] <= k && k <= arr[e])
        s = mid + 1;
      else
        e = mid - 1;
    }
  }
  return -1;
}

// may contain duplicate values, return true if target is in nums, or false if it is not in nums.
bool search2(vector<int> arr, int k){
  int s = 0, e = arr.size() - 1;
  while(s <= e){
    int mid = s + (e - s)/2;
    if(arr[mid] == k)
      return true;

    // it means we have duplicate values at the left and mid positions. Increment left by 1 to skip duplicates and continue to the next.
    if (arr[mid] == arr[s]) {     
        s++;
        continue;
    }

    else if (arr[s] <= arr[mid]){              // the left half is sorted
      if(arr[s] <= k && k <= arr[mid])  
        e = mid - 1;
      else 
        s = mid + 1;
    }
    else {                                       // the right half is sorted (arr[mid] <= arr[e])
      if(arr[mid] <= k && k <= arr[e])
        s = mid + 1;
      else
        e = mid - 1;
    }
  }
  return false;
}

// may contain duplicate values, return index.
int search3(vector<int> arr, int k){
  int s = 0, e = arr.size() - 1;
  while(s <= e){
    int mid = s + (e - s)/2;
    if(arr[mid] == k)
      return mid;

    // it means we have duplicate values at the left and mid positions. Increment left by 1 to skip duplicates and continue to the next.
    if (arr[mid] == arr[s]) {     
        s++;
        continue;
    }

    else if (arr[s] <= arr[mid]){              // the left half is sorted
      if(arr[s] <= k && k <= arr[mid])  
        e = mid - 1;
      else 
        s = mid + 1;
    }
    else {                                       // the right half is sorted (arr[mid] <= arr[e])
      if(arr[mid] <= k && k <= arr[e])
        s = mid + 1;
      else
        e = mid - 1;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {4,5,6,7,0,1,2,11};
  int k = 1;
  cout<<search(arr, k)<<endl;

  arr = {2,5,6,0,0,1,2};
  k = 1;
  cout<<search2(arr, k)<<endl;
  cout<<search3(arr, 0);
  return 0;
}