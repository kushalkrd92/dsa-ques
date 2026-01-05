#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. // clock-wise    // right rotation
void rotateArray(vector<int> &nums, int k){
  int n = nums.size();
  k = k%n;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin()+k);
  reverse(nums.begin()+k, nums.end());
}

// Function to rotate an array by d elements in counter-clockwise direction.    // left rotation
void rotateArray1(vector<int>& arr, int k) {
  int n = arr.size();
  k = k%n;
  reverse(arr.begin(), arr.begin()+k);
  reverse(arr.begin()+k, arr.end());
  reverse(arr.begin(), arr.end());
}

int main(){
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  int k = 3;
  rotateArray(arr, k);
  for(int i: arr)
    cout<<i<<' ';
  cout<<endl;

  vector<int> arr1 = {1, 2, 3, 4, 5, 6};
  k = 3;
  rotateArray1(arr1, k);
  for(int i: arr1)
    cout<<i<<' ';
  cout<<endl;
  return 0;
}

// both left and right rotation result in same ans if k is same