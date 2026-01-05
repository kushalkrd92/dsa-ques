#include <iostream>
#include <vector>
using namespace std;

// You are given an integer array height where height[i] represents the height of mountain i, and an integer threshold.
// A mountain is called stable if the mountain 'just before it' (if it exists) has a height strictly greater than threshold. Note that mountain 0 is not stable.
// Return an array containing the indices of all stable mountains in any order.
vector<int> stableMountains(vector<int>& height, int threshold) {
  int n = height.size();
  vector<int> ans;
  for(int i = 1; i<n; i++){
    if(height[i-1] > threshold)
      ans.push_back(i);
  }
  return ans;
}

int main(){
  vector<int> arr = {10,1,10,1,10};
  int threshold = 6;
  vector<int> ans = stableMountains(arr, threshold);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}