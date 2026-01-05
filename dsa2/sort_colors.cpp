#include <iostream>
#include <vector>
using namespace std;

// use sort 012 code

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// Dutch National Flag problem.
void sortColors(vector<int> &nums){
  int low = 0, high = nums.size() - 1; 
  int curr = 0;
  while (curr <= high) {
    if (nums[curr] == 0)                // If the current element is 0, swap with low and move both forward.
      swap(nums[low++], nums[curr++]);
    else if (nums[curr] == 2)           // If it's 2, swap with high and move high backward.
      swap(nums[curr], nums[high--]);
    else                               // if it's 1, just move curr ahead.
      curr++;
  }
}

int main(){
  vector<int> arr = {2,0,2,1,1,0};
  sortColors(arr);
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}