// subarray sum equals k
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> arr, int k){
  unordered_map<int, int> mp;
  mp[0] = 1;
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

int main(){
  vector<int> arr = {1, 2, 3, -3, 1, 1, 1};
  int k = 3;
  cout<<subarraySum(arr, k);
  return 0;
}