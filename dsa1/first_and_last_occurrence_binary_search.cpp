#include <iostream>
#include <vector>
using namespace std;

// Find First and Last Position of Element in Sorted Array (multiples)
int firstOccurrence(vector<int> arr, int target){
  int s = 0;
  int e = arr.size() - 1;
  int ans = -1;
  while(s <= e){
    int mid = s + (e - s)/2;
    if(arr[mid] == target){
      ans = mid;
      e = mid - 1;
    }
    else if(arr[mid] > target)
      e = mid - 1;
    else  
      s = mid + 1;
  }
  return ans;
}

int lastOccurrence(vector<int> arr, int target){
  int s = 0;
  int e = arr.size() - 1;
  int ans = -1;
  while(s <= e){
    int mid = s + (e - s)/2;
    if(arr[mid] == target){
      ans = mid;
      s = mid + 1;
    }
    else if(arr[mid] > target)
      e = mid - 1;
    else  
      s = mid + 1;
  }
  return ans;
}

int main(){
  vector<int> arr = {5,7,7,8,8,8,10};
  int target = 8;
  vector<int> ans;
  int first = firstOccurrence(arr, target);
  ans.push_back(first);
  int last = lastOccurrence(arr, target);
  ans.push_back(last);

  cout<<endl;
  for(int i = 0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
  cout<<endl;

  // Find total number of occurrences of an Element in Sorted Array (multiples)
  int total = last - first;
  if(total == 0)
    cout<<total;           // Note - for(-1, -1) => total = 0; for(3, 3) => total = 0  // for element not present or for unique occurrence 
  else
    cout<<total+1;
  return 0;
}
