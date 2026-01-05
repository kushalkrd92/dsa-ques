#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// return indices of the two numbers such that they add up to target, in case of a single ans, each element is considered only once
pair<int, int> twoSum(vector <int> arr, int target){
  unordered_map<int, int> mp;     // element, index
  for(int i = 0; i < arr.size(); i++){
    if(mp.count(target - arr[i]))
      return {mp[target - arr[i]], i};
    mp[arr[i]] = i;
  }
  return {-1, -1};
}
  
// If more than one such pair of indices exist, return the lexicographically smallest pair
pair<int,int> twoSum1(vector<int>& arr, int target) {
  unordered_map<int, int> mp;     // element, index
  pair<int, int> ans = {-1, -1};
  for(int i = 0; i < arr.size(); i++){
    auto it = mp.find(target - arr[i]);
    if(it != mp.end()){
      if(ans.first == -1 || it->second < ans.first){
        ans.first = it->second;
        ans.second = i;
      }
    }
    mp.insert({arr[i], i});
  }
  return ans;
}

// return indices of the two numbers such that they add up to target, in case of multiple pairs, each element is considered only once
vector<pair<int, int>> twoSum2(vector <int> arr, int target){
  unordered_map<int, int> mp;     // element, index
  vector<pair<int, int>> ans;
  for(int i = 0; i < arr.size(); i++){
    pair<int, int> p;
    if(mp.count(target - arr[i]))
      ans.push_back({mp[target - arr[i]], i});
    else 
      mp[arr[i]] = i;
  }
  return ans;
}

//Given an integer array nums, return all the duals [nums[i], nums[j]] such that i != j and nums[i] + nums[j] == 0
vector<vector<int>> twoSum3(vector<int> nums, int target){
  int n = nums.size();
  set<vector<int>> s;
  int i = 0;
  int j = n-1;
  while (i < j) {
      int sum = nums[i] + nums[j];
      if (sum == target) {
          s.insert({nums[i], nums[j]});
          i++;
          j--;
      } 
      else if (sum < target)
          i++;
      else
          j--;
  }
  vector<vector<int>> ans;
  for(auto i: s)
      ans.push_back(i);
  return ans;
}

// return the no of pairs  ans (1, 2) is same as (2, 1)
int pairSum(vector<int> &arr, int target){
	int left=0, right = arr.size() - 1;
  int cnt=0;
  while(left < right){
    int sum = arr[left]+arr[right];
    if(sum == target){
      cnt++;
      left++;
      right--;
    }
    else if(sum < target)
      left++;
    else
      right--;
  }
  return cnt;
}

int main(){
  vector<int> arr = {3, 2, 10, 1, 0};
  int target = 3;
  pair<int, int> p = twoSum(arr, target);
  pair<int, int> p1 = twoSum1(arr, target);
  cout<<p.first<<" "<<p.second<<endl;
  cout<<p1.first<<" "<<p1.second<<endl;

  vector<int> arr1 = {1, 2, 4, 6, 3, 2, -2};
  target = 4;
  vector<pair<int, int>> ans = twoSum2(arr1, target);
  for(int i = 0; i<ans.size(); i++)
    cout<<"["<<ans[i].first<<" "<<ans[i].second<<"] ";
  cout<<endl;

  vector<int> arr2 = {1, -2, 4, -4, 3, 2, -2};
  target = 0;
  sort(arr2.begin(), arr2.end());
  vector<vector<int>> ans2 = twoSum3(arr2, target);
  for(int i = 0; i<ans2.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans2[i].size(); j++)
      cout<<ans2[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;
  cout<<pairSum(arr2, 0);
  return 0;
}