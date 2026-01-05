#include <iostream>
#include <vector>
#include <set>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2){
  int n = arr1.size();
  int m = arr2.size();
  vector<int> ans;
  int i = 0, j = 0, k = 0;
  while(i < n && j < m){
    if(arr1[i] < arr2[j]){
      ans.push_back(arr1[i]);
      i++;
    }
    else{
      ans.push_back(arr2[j]);
      j++;
    }
  }
  while(i < n){
    ans.push_back(arr1[i]);
    i++;
  }
  while(j < m){
    ans.push_back(arr2[j]);
    j++;
  }

  arr1.clear();
  for(int i = 0; i < (m+n); i++)
    arr1.push_back(ans[i]);
}

// union: means result must only contain unique elements
vector<int> unionMerge(vector < int > a, vector < int > b) {
  int n = a.size();
  int m = b.size();
  set<int> ans;
  int i = 0, j = 0;
  while(i < n && j < m){
    if(a[i] < b[j]){
      ans.insert(a[i]);
      i++;
    }
    else{
      ans.insert(b[j]);
      j++;
    }
  }
  while(i < n){
    ans.insert(a[i]);
    i++;
  }
  while(j < m){
    ans.insert(b[j]);
    j++;
  }

  vector<int> result;
  for(int i: ans){
    result.push_back(i);
  }
  return result;
}

// intersection, two arrays are sorted
vector<int> intersectionMerge(vector < int > &a, vector < int > &b) {
  int n = a.size();
  int m = b.size();
  vector<int> ans;
  int i = 0, j = 0;
  while(i < n && j < m){
    if(a[i] == b[j]){
      ans.push_back(a[i]);
      i++;
      j++;
    }
    else if(a[i] < a[j])
      i++;
    else  
      j++;
  }
  return ans;
}


int main(){
  vector<int> arr1 = {1,2,3};
  vector<int> arr2 = {2,3,5,6};
  merge(arr1, arr2);
  for(int i: arr1)
    cout<<i<<" ";
  cout<<endl;

  vector<int> arr3 = {1,2,3};
  vector<int> arr4 = {2,3,5,6};
  
  vector<int> ans = unionMerge(arr3, arr4);
  for(int i: ans)
    cout<<i<<" ";
  cout<<endl;

  vector<int> arr5 = {1,2,3};
  vector<int> arr6 = {2,3,5,6};
  vector<int> ans1 = intersectionMerge(arr5, arr6);
  for(int i: ans1)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}