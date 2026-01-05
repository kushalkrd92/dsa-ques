// remove duplicates from string array
#include <bits/stdc++.h>
using namespace std;

vector<string> removeDuplicates(vector<string> arr){
  set<string> s;
  for(string i: arr)
    s.insert(i);

  vector<string> ans;
  for(string i: s)
    ans.push_back(i);
  return ans;
}

int main(){
  vector<string> arr = {"watermelon", "apple", "orange", "banana", "orange", "lemon", "apple"};
  vector<string> ans = removeDuplicates(arr);
  for(string i: ans)
    cout<<i<<" ";
  cout<<endl;
  reverse(ans.begin(), ans.end());
  for(string i: ans)
    cout<<i<<" ";
  return 0;
}