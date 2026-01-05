#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int binarySubarraySum(vector<int> nums, int k){
  int count = 0, sum = 0;
  unordered_map<int, int> mp;      // element, freq
  mp.insert({0, 1});      
  for(int num: nums){
    sum += num;
    count += mp[sum - k];
    mp[sum]++;
  }
  return count;
}

int main(){
  vector<int> arr = {1,0,1,0,1};
  int k = 2;
  cout<<binarySubarraySum(arr, k);
  return 0;
}