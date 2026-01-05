// In mathematics, a combination is a selection of items from a set that has distinct members, such that the order of selection does not matter. For ex: Forming a Committee - You have 10 people, and you need to choose 4 to form a committee. 
// here order does not matter. So [1, 2] is same as [2, 1]
#include <iostream>
#include <vector>
using namespace std;

// return all possible combinations of k numbers chosen from the range [1, n], in any order (k length)
void combinations(int n, int k, int start, vector<int> temp, vector<vector<int>> &ans){
  if(temp.size() == k){
    ans.push_back(temp);
    return;
  }
  for(int i = start; i <= n; i++){
    temp.push_back(i);
    combinations(n, k, i+1, temp, ans);
    temp.pop_back();
  }
}

int main(){
  int n, k;
  cout<<"Enter n followed by k: ";
  cin>>n>>k;
  int start = 1;
  vector<vector<int>> ans;
  vector<int> temp;
  combinations(n, k, start, temp, ans);
  for(int i = 0; i<ans.size(); i++){
    cout<<"[ ";
    for(int j = 0; j<ans[0].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<']';
  }
  cout<<endl;
  return 0;
}