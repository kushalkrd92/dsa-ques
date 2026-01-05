#include <iostream>
#include <vector>
using namespace std;

void combinations(string digits, int index, string temp, string mapping[], vector<string> &ans){
  if(index >= digits.size()){
    ans.push_back(temp);
    return;
  }
  int number = digits[index] - '0';
  string value = mapping[number];
  for(int i = 0; i<value.length(); i++){
  temp.push_back(value[i]);
  combinations(digits, index+1, temp, mapping, ans);
  temp.pop_back();
  }
}

int main(){
  string digits;
  cout<<"Enter digits: ";
  cin>>digits;
  if(digits.length() == 0){         // handle this case
    cout<<"Enter more than 0 digits.";
    return 1;
  }
  vector<string> ans;
  string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};    // 0 - 9
  int index = 0;
  string temp = "";
  combinations(digits, index, temp, mapping, ans);
  for(string s: ans)
    cout<<s<<" ";
  return 0;
}