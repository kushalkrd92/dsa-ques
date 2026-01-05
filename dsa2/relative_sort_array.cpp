#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
vector<int> relativeSort(vector<int>& arr1, vector<int>& arr2) {
  unordered_map<int, int> mp;     // element, freq
  for(int i = 0; i<arr1.size(); i++)
    mp[arr1[i]]++;
  
  vector<int> ans;
  for(int i = 0; i<arr2.size(); i++){
    while(mp[arr2[i]] != 0){
      ans.push_back(arr2[i]);
      mp[arr2[i]]--;
    }
  }
  vector<int> rest;
  for(auto i: mp){
    while(i.second != 0){
      rest.push_back(i.first);
      i.second--;
    }
  }
  sort(rest.begin(), rest.end());
  ans.insert(ans.end(), rest.begin(), rest.end());
  return ans;
}

int main(){
  vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
  vector<int> arr2 = {2,1,4,3,9,6};
  vector<int> ans = relativeSort(arr1, arr2);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}