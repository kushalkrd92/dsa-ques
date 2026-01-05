#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
void combination(vector<int> arr, int target, int index, int total, vector<int> temp, vector<vector<int>> &ans){
  if(total == target){
    // sort(temp.begin(), temp.end());
    ans.push_back(temp);
    return;
  }
  if(total > target || index >= arr.size())
    return;

  combination(arr, target, index + 1, total, temp, ans);     // exclude
  temp.push_back(arr[index]);
  combination(arr, target, index, total + arr[index], temp, ans);      // include
  temp.pop_back();              // backtrack
}

// Given a collection of candidate numbers (arr) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in arr may only be used once in the combination
void combination1(vector<int> arr, int target, int index, vector<int> temp, vector<vector<int>> &ans){
  if(target == 0){
    sort(temp.begin(), temp.end());
    ans.push_back(temp);
    return;
  }
  if(target < 0)
    return;

  for(int i = index; i<arr.size(); i++){
    if(i > index && arr[i] == arr[i-1])
      continue;
    if(arr[i] > target)
      break;
    temp.push_back(arr[i]);
    combination1(arr, target - arr[i], i + 1, temp, ans);
    temp.pop_back();
  }
}

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true: Only numbers 1 through 9 are used ans Each number is used at most once.
void combination2(int k, int target, int index, vector<int> temp, vector<vector<int>> &ans){       // dfs
  if(k == 0 && target == 0){
    ans.push_back(temp);
    return;
  }
  for(int i = index; i <= 9; i++){
    if(i > target)
      break;
    temp.push_back(i);
    combination2(k - 1, target - i, i + 1, temp, ans);
    temp.pop_back();
  }
}

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target. using memoization
int combination3(vector<int>& nums, int target, vector<int> &dp){
  if(target < 0)
      return 0;
  if(target == 0)
      return 1;
  if(dp[target] != -1)
      return dp[target];

  int ans = 0;
  for(int i = 0; i<nums.size(); i++)
      ans += combination3(nums, target - nums[i], dp);
  return dp[target] = ans;
}

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target. using tabulation
int combination4(vector<int>& nums, int target){
  vector<unsigned int> dp(target+1, 0);        
  dp[0] = 1;

  for(int i = 1; i <= target; i++){
      for(int j = 0; j <nums.size(); j++){
          if(i-nums[j] >= 0)
              dp[i] += dp[i - nums[j]];
      }
  }
  return dp[target];
}

int main(){
  vector<int> arr = {2, 3, 6, 7};
  int target = 7;
  int index = 0;
  int total = 0;
  vector<int> temp;
  vector<vector<int>> ans;
  combination(arr, target, index, total, temp, ans);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[i].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;

  vector<int> arr1 = {10,1,2,7,6,1,5};
  target = 8;
  index = 0;
  vector<int> temp1;
  vector<vector<int>> ans1;
  sort(arr1.begin(), arr1.end());      // very important step (done in case of unique elements to consider)
  combination1(arr1, target, index, temp1, ans1);
  for(int i = 0; i<ans1.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans1[i].size(); j++)
      cout<<ans1[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;

  int k = 3;
  target = 9;
  index = 1;
  vector<int> temp2;
  vector<vector<int>> ans2;
  combination2(k, target, index, temp2, ans2);
  for(int i = 0; i<ans2.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans2[i].size(); j++)
      cout<<ans2[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;

  vector<int> arr3 = {1, 2, 3};
  target = 4;
  vector<int> dp(target+1, -1);
  cout<<combination3(arr3, target, dp)<<endl;

  cout<<combination4(arr3, target)<<endl;
  return 0;
}