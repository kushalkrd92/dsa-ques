#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0, no duplicates
vector<vector<int>> threeSum(vector<int> nums, int target){
  int n = nums.size();
  set<vector<int>> s;
  for (int i = 0; i < n; i++){
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == target) {
              s.insert({nums[i], nums[j], nums[k]});
              j++;
              k--;
          } 
          else if (sum < target)
              j++;
          else
              k--;
      }
  }
  vector<vector<int>> ans;
  for(auto i: s)
      ans.push_back(i);
  return ans;
}

int main(){
  vector<int> arr = {-1,0,1,2,-1,-4};
  sort(arr.begin(), arr.end());           //
  int target = 0;
  vector<vector<int>> ans = threeSum(arr, target);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[i].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;
  return 0;
}