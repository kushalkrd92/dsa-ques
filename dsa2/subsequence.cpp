#include <iostream>
using namespace std;

// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
bool isSubsequence(string s, string t){
  int i = 0, j = 0;
  while(i < s.length() && j < t.length()){
    if(s[i] == t[j])
      i++;
    j++;
  }
  return i == s.length();
}

int main(){
  string s = "abs", t = "acbrts";
  cout<<isSubsequence(s, t);
  return 0;
}