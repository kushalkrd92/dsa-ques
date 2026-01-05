#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
vector<vector<int>> fourSum(vector<int> nums, int target){
  int n = nums.size();
  set<vector<int>> s;
  for (int i = 0; i < n; i++){
    for(int j = i+1; j<n; j++){
      int k = i + 1;
      int l = n - 1;
      while (k < l) {
          long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
          if (sum == target) {
              s.insert({nums[i], nums[j], nums[k], nums[l]});
              k++;
              l--;
          } 
          else if (sum < target)
              k++;
          else
              l--;
      }
    }
  }
  vector<vector<int>> ans;
  for(auto i: s)
      ans.push_back(i);
  return ans;
}

int main(){
  vector<int> arr = {1,0,-1,0,-2,2};
  sort(arr.begin(), arr.end());
  int target = 0;
  vector<vector<int>> ans = fourSum(arr, target);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[i].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;
  return 0;
}