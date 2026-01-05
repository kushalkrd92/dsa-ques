#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>      // __gcd(a,b)
using namespace std;

// Subarray Sum Equals K
int subarraySum(vector<int> &arr, int k){
  unordered_map<int, int> mp;     // element, freq
  mp[0] = 1;          // base case (when target == 0)
  int sum = 0;
  int count = 0;
  for(int i = 0; i<arr.size(); i++){
    sum += arr[i];
    int rem = abs(k - sum);
    count += mp[rem];
    mp[sum]++;
  }
  return count;
}

// Subarray Sums Divisible by K
int subarraySum2(vector<int>& nums, int k) {
  unordered_map<int, int> mp;   // to store the count of each subarray sum
  int sum = 0;
  int count = 0;
  mp[0] = 1;   
  for(int i = 0; i < nums.size(); i++){
      sum = (sum + nums[i]) % k;
      if (sum < 0)
          sum = sum + k;      // add k if sum negative to make it positive
      count += mp[sum];
      mp[sum]++;
  }
  return count;
}

// return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
// The greatest common divisor of an array is the largest integer that evenly divides all the array elements.
int subarrayGCD(vector<int> nums, int k){
  int count = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
      int curr_gcd = nums[i];
      if (curr_gcd % k != 0)          // Only proceed if the current element is a multiple of k
          continue;

      for (int j = i; j < n; j++) {
          curr_gcd = __gcd(curr_gcd, nums[j]);
          if (curr_gcd < k) 
              break; 
          if (curr_gcd == k) 
              count++;
      }
  }
  return count;
}

int lcm(int a, int b){
  return (a / __gcd(a, b)) * b;
}

// Number of Subarrays With LCM Equal to K
// The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
int subarrayLCM(vector<int> nums, int k){
  int count = 0;
  int n = nums.size();
  for(int i = 0; i<n; i++){
    int curr  = nums[i];
    for(int j = i; j<n; j++){
      curr = lcm(curr, nums[j]);
      if(curr == k)
          count++;
      if(curr > k)
          break;
    }
  }
  return count;
}

int main(){
  vector<int> arr = {1, 1, 1, 2};
  vector<int> arr1 = {4,5,0,-2,-3,1};
  vector<int> arr2 = {9,3,1,2,6,3};
  vector<int> arr3 = {3,6,2,7,1};
  int k = 2;
  cout<<subarraySum(arr, k)<<endl;
  cout<<subarraySum2(arr1, 5)<<endl;
  cout<<subarrayGCD(arr2, 3)<<endl;
  cout<<subarrayLCM(arr3, 6)<<endl;
  return 0;
}