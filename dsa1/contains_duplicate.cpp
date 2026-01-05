#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// return true if any value appears at least twice in the array, and return false if every element is distinct.
bool containsDuplicate(vector<int> v){
  sort(v.begin(), v.end());
  for(int i = 0; i<v.size(); i++){
    if((i+1 < v.size()) && (v[i] == v[i+1]))
      return true;
  }
  return false;
}

// return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k
bool containsDuplicate2(vector<int> v, int k){
  unordered_map<int, int> mp;         // arr[i], j   or   element, index
  for(int i = 0; i<v.size(); i++){
    if((mp.count(v[i]) > 0) && (abs(i - mp[v[i]]) <= k))
      return true;
    mp[v[i]] = i;
  }
  return false;
}

// return true for a pair of indices (i, j) such that: i != j, abs(i - j) <= indexDiff, abs(nums[i] - nums[j]) <= valueDiff
bool containsDuplicate3(vector<int> v, int indexDiff, int valueDiff){
  unordered_map<int, int> mp;         // arr[i], j   or   element, index
  for(int i = 0; i<v.size(); i++){
    if((i != mp[v[i]]) && (abs(i - mp[v[i]]) <= indexDiff && (abs(v[i] - v[mp[v[i]]]) <= valueDiff)))
      return true;
    mp[v[i]] = i;
  }
  return false;
}


int main(){
  int n;
  cout<<"Enter size: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter "<<n<<" array elements: ";
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  cout<<containsDuplicate(arr)<<endl;
  cout<<containsDuplicate2(arr, 3)<<endl;
  cout<<containsDuplicate3(arr, 3, 0)<<endl;
  cout<<containsDuplicate3(arr, 3, 1)<<endl;
  return 0;
}