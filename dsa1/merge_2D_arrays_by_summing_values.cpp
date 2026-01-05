#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> nums1, vector<vector<int>> nums2){
  nums1.insert(nums1.end(), nums2.begin(), nums2.end());    // adding nums2 to nums1
  sort(nums1.begin(), nums1.end());

  vector<vector<int>> result;
  for (auto& pair : nums1) {
      if (!result.empty() && result.back()[0] == pair[0])
          result.back()[1] += pair[1];
      else
          result.push_back(pair);
  }
  return result;
}

int main(){
  vector<vector<int>> arr1 = {{1,2},{2,3},{4,5}};        
  vector<vector<int>> arr2 = {{2,2},{3,4},{4,1},{6,1}};
  vector<vector<int>> ans = merge(arr1, arr2);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[";
    for(int j = 0; j<ans[i].size(); j++)
      cout<<" "<<ans[i][j]<<" ";
    cout<<"]";
  }
  return 0;
}