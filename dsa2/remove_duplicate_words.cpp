#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// remove duplicates from a sorted array in-place such that every element appears only once and relative order of the elements should be kept the same, return the resultant array
vector<string> removeDuplicate(vector<string> arr){
  sort(arr.begin(), arr.end());

  unordered_map<string, int> mp;
  vector<string> ans;
  for(int i = 0; i<arr.size(); i++){
    mp[arr[i]]++;
    if(mp[arr[i]] == 1)
      ans.push_back(arr[i]);
  }
  return ans;
}

int main(){
  vector<string> arr = {"apple", "mango", "apple", "papaya", "cherry", "mango", "guava", "guava"};
  vector<string> ans = removeDuplicate(arr);
  for(string s: ans)
    cout<<s<<" ";
  return 0;
}