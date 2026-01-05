#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that:
// nums1.length == nums2.length == nums.length / 2.
// nums1 should contain distinct elements.
// nums2 should also contain distinct elements.
// Return true if it is possible to split the array, and false otherwise.
bool isPossibleToSplit(vector<int>& nums) {
  unordered_map<int, int> mp;
  for (int i: nums)
    mp[i]++;
  for (auto& i: mp) {
    if (i.second > 2)
      return false;
  }
  return true;        
}

int main(){
  vector<int> arr = {1,1,2,2,3,4};
  cout<<isPossibleToSplit(arr);
  return 0;
}