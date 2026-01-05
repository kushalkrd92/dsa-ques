#include <iostream>
#include <vector>
using namespace std;

// move zeros to end of the array inplace
vector<int> moveZeroes(vector<int> nums) {
  int n = nums.size();
  int nonZero = 0;
  for(int i = 0; i<n; i++){
    if(nums[i] != 0){
      swap(nums[i], nums[nonZero]);
      nonZero++;
    }
  }
  return nums;
}

// move zeros to start of the array inplace
vector<int> moveZeroes2(vector<int> nums) {
  int n = nums.size();
  int zeroIndex = 0;
  for(int i = 0; i<n; i++){
    if(nums[i] == 0){
      swap(nums[i], nums[zeroIndex]);
      zeroIndex++;
    }
  }
  return nums;
}

int main(){
  vector<int> arr = {0,1,0,3,12};
  vector<int> ans = moveZeroes(arr);
  for(int i: ans)
    cout<<i<<" ";
  cout<<endl;
  ans = moveZeroes2(arr);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}