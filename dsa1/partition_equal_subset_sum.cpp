#include <iostream>
#include <vector>
using namespace std;

bool solveMem(int index, vector<int>& arr, int n, int target, vector<vector<int>> &dp){
  if(index >= n)
    return 0;
  if(target < 0)
    return 0;
  if(target == 0)
    return 1;
  
  if(dp[index][target] != -1)
    return dp[index][target];
  
  bool include = solveMem(index+1, arr, n, target-arr[index], dp);
  bool exclude = solveMem(index+1, arr, n, target, dp);
  return dp[index][target] = include or exclude;
}

int main(){
  vector<int> arr = {1,5,11,5};
  int n = arr.size();
  int total = 0;
  for(int i: arr)
      total += i;

  if(total & 1)    // odd    // no partition possible
      cout<<0;

  int target = total/2;

  vector<vector<int>> dp(n, vector<int>(target+1, -1));
  cout<<solveMem(0, arr, n, target, dp);
  return 0;
}