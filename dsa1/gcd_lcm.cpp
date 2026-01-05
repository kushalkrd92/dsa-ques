#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int gcd(int a, int b){
  if(a == 0)
    return b;
  if(b == 0)
    return a;
  while(a != b){
    if(a > b)
      a = a - b;
    else  
      b = b - a;
  }
  return a;
}

int lcm(int a, int b){
  return (a / gcd(a, b)) * b;
}

int findGCD(vector<int> nums) {
  int mini = INT_MAX;
  int maxi = INT_MIN;
  for(int num: nums){
    mini = min(mini, num);
    maxi = max(maxi, num);
  }
  return gcd(mini, maxi);
}

int findLCM(vector<int> nums){
  int n = nums.size();
  int a = nums[0];
  for(int i = 1; i<n; i++){
    int b = nums[i];
    a = (a / gcd(a, b)) * b;
  }
  return a;
}

int main(){
  vector<int> arr = {2, 4, 6, 8, 4, 2};
  cout<<gcd(2, 4)<<endl;
  cout<<lcm(2, 4)<<endl;
  cout<<findGCD(arr)<<endl;
  cout<<findLCM(arr)<<endl;
  return 0;
}