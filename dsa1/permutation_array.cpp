// A permutation is a mathematical operation that defines the number of possible ordered arrangements of a set of objects
// For example: {1, 2} and {2, 1} are two different permutations of the numbers 1 and 2.  
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permutation(vector<int> arr, vector<vector<int>>& ans, int index){
  if(index >= arr.size()){
    ans.push_back(arr);
    return;
  }
  for(int i = index; i < arr.size(); i++){
    swap(arr[i], arr[index]);
    permutation(arr, ans, index+1);
  }
}

// nums might contain duplicates, return all possible unique permutations in any order.
void permutation2(vector<int> arr, vector<vector<int>>& ans, int index){
  if(index >= arr.size()){
    ans.push_back(arr);
    return;
  }
  for(int i = index; i < arr.size(); i++){
    if(index != i && arr[index] == arr[i])
      continue;
    swap(arr[i], arr[index]);
    permutation2(arr, ans, index+1);
  }
}

int main(){
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> ans;
  int index = 0;
  permutation(arr, ans, index);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[0].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;

  vector<int> arr1 = {1, 1, 2};
  vector<vector<int>> ans1;
  index = 0;
  sort(arr1.begin(), arr1.end());       // important
  permutation2(arr1, ans1, index);
  for(int i = 0; i<ans1.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans1[0].size(); j++)
      cout<<ans1[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;
}