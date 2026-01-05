// subarray with largest sum, return their sum
#include <bits/stdc++.h>
using namespace std;

int largestSubarraySum(vector<int> arr){
  int sum = INT_MIN;
  int temp = 0;
  for(int i = 0; i<arr.size(); i++){
    temp = max(arr[i], temp + arr[i]);
    sum = max(sum, temp);
  }
  return sum;
}

int smallestSubarraySum(vector<int> arr){
  int sum = INT_MAX;
  int temp = 0;
  for(int i = 0; i<arr.size(); i++){
    temp = min(arr[i], temp - arr[i]);
    sum = min(sum, temp);
  }
  return sum;
}

int main(){
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout<<largestSubarraySum(arr)<<endl;
  cout<<smallestSubarraySum(arr)<<endl;
  return 0;
}