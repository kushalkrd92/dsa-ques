#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permutation(string str, int index, vector<string> &ans){
  if(index >= str.size()){
    ans.push_back(str);
    return;
  }
  for(int i = index; i<str.size(); i++){
    swap(str[i], str[index]);
    permutation(str, index+1, ans);
  }
}

// return all possible unique permutations in any order.
void permutation2(string str, int index, vector<string> &ans){
  if(index >= str.size()){
    ans.push_back(str);
    return;
  }
  for(int i = index; i<str.size(); i++){
    if(index != i && str[i] == str[index])
      continue;
    swap(str[i], str[index]);
    permutation2(str, index+1, ans);
  }
}

int main(){
  string str;
  cout<<"Enter word: ";
  cin>>str;
  vector<string> ans;
  int index = 0;
  permutation(str, index, ans);  
  for(string s: ans)                    // for lexographically increasing we can sort the ans array
    cout<<s<<" "; 
  cout<<endl;

  index = 0;
  vector<string> ans1;
  sort(str.begin(), str.end());    // imp
  permutation2(str, index, ans1);
  for(string s: ans1)
    cout<<s<<" ";
  return 0;
}