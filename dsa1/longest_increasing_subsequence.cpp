#include <iostream>
#include <vector>
using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing subsequence.
int lis(vector<int> arr){
  int n = arr.size();
  if(n == 0)
    return 0;
  
  vector<int> ans;
  ans.push_back(arr[0]);

  for(int i = 1; i<n; i++){
    if(arr[i] > ans.back())
      ans.push_back(arr[i]);
    else{
      int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();   // finding the exact location for arr[i] in ans vector
      ans[index] = arr[i];      // replacing the element
    }
  }
  return ans.size();
}

bool increasingTriplet(vector<int>& nums) {
  int n = nums.size();
  if(n == 0)
    return 0;
  
  vector<int> ans;
  ans.push_back(nums[0]);

  for(int i = 1; i<n; i++){
    if(nums[i] > ans.back() && ans.size() < 3)
      ans.push_back(nums[i]);
    else{
      int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();   // finding the exact location for arr[i] in ans vector
      ans[index] = nums[i];      // replacing the element
    }
  }
  return ans.size() == 3;
}


int main(){
  vector<int> arr = {10,9,2,5,3,7,101,18,19};
  cout<<lis(arr)<<endl;
  cout<<increasingTriplet(arr)<<endl;
  return 0;
}