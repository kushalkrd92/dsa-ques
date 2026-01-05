#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// remove duplicates from a sorted array in-place such that every element appears only once and relative order of the elements should be kept the same, return the size of the resultant array
int removeDuplicates(vector<int> v){
  sort(v.begin(), v.end());

  int i = 0;        // index of the resultant array
  for(int j = 1; j<v.size(); j++){
    if(v[i] != v[j]){
      i++;
      v[i] = v[j];
    }
  }
  return i+1;
}

// remove duplicates from a sorted array in-place such that every element appears only once and relative order of the elements should be kept the same, return the resultant array
vector<int> removeDuplicates2(vector<int> v){
  sort(v.begin(), v.end());

  unordered_map<int, int> mp;      // element, freq
  vector<int> ans;
  for(int i = 0; i<v.size(); i++){
    mp[v[i]]++;
    if(mp[v[i]] == 1)
      ans.push_back(v[i]);
  }
  return ans;
}

// remove duplicates from a sorted array in-place such that every element appears atmost twice and relative order of the elements should be kept the same, return the size of the resultant array
int removeDuplicates3(vector<int> v){
  sort(v.begin(), v.end());

  if(v.size() <= 2)
    return v.size();

  int i = 1;
  for(int j = 2; j<v.size(); j++){
    if(v[j] != v[i-1])
      i++;
      v[i] = v[j];
  }
  return i+1;
}

int main(){
  int n;
  cout<<"Enter size: ";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter "<<n<<" array elements: ";
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  cout<<removeDuplicates(arr)<<endl;
  vector<int> ans = removeDuplicates2(arr);
  for(int i: ans)
    cout<<i<<" ";
  cout<<endl;
  cout<<removeDuplicates3(arr)<<endl;
  return 0;
}