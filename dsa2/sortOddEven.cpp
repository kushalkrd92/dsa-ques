#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Sort the array ‘NUMS’ in such a way that the first half of the array contains only odd numbers sorted in non-increasing order and the second half contains only even numbers sorted in non-decreasing order.
void sortOddEven(vector<int>& nums){
  int oddIndex = 0;
  for(int i = 0; i<nums.size(); i++){
      if(nums[i]%2 == 1){     // odd
          swap(nums[i], nums[oddIndex]);
          oddIndex++;
      }      
  }
  sort(nums.begin(), nums.begin() + oddIndex, greater<int>());   // dec
  sort(nums.begin() + oddIndex, nums.end());       // inc
}

int main(){
  vector<int> arr = {2, 5, 3, 6};
  sortOddEven(arr);
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}