#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// find three integers in nums such that the sum is closest to target.
int threeSumClosest(vector<int>& nums, int target) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  set<vector<int>> s;
  int sum = nums[0]+nums[1]+nums[2];

  for (int i = 0; i < n-2; i++){
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
          int temp = nums[i] + nums[j] + nums[k];
          if(abs(target-temp) < abs(target-sum))
              sum = temp;
          if(temp < target)
              j++;
          else if(temp > target)
              k--;
          else
              return target;
      }
  }
  return sum;
}

int main(){
  vector<int> arr = {-1,1,2,-4};
  sort(arr.begin(), arr.end());
  int target = 1;
  cout<<threeSumClosest(arr, target);
  return 0;
}