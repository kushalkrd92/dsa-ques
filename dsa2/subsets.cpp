#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Given an integer array nums that does not contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
void subsets(vector<int> arr, int index, vector<int> temp, vector<vector<int>> &ans){
  if(index >= arr.size()){
    ans.push_back(temp);
    return;
  }

  // exclude
  subsets(arr, index+1, temp, ans);

  // include
  temp.push_back(arr[index]);
  subsets(arr, index+1, temp, ans);
}

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
void subsets2(vector<int> arr, int index, vector<int> temp, vector<vector<int>> &ans){
  if(index >= arr.size()){
    if(find(ans.begin(), ans.end(), temp) == ans.end())    // check if the subset's already present
      ans.push_back(temp);
    return;
  }

  //exclude
  subsets2(arr, index+1, temp, ans);

  //include
  temp.push_back(arr[index]);
  subsets2(arr, index+1, temp, ans);
}

int main(){
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> ans;
  vector<int> temp;
  int index = 0;
  subsets(arr, index, temp, ans);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[i].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;

  vector<int> arr2 = {1, 3, 1};
  vector<vector<int>> ans2;
  vector<int> temp2;
  index = 0;
  sort(arr2.begin(), arr2.end());
  subsets2(arr2, index, temp2, ans2);
  for(int i = 0; i<ans2.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans2[i].size(); j++)
      cout<<ans2[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;
  return 0;
}