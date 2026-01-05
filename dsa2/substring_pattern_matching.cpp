#include <iostream>
using namespace std;

bool hasMatch(string s, string p) {
  int x = p.find("*");     // find index of *

  string pre = p.substr(0, x);          // stores prefix
  string suf = p.substr(x + 1);           // stores suffix

  int pi = s.find(pre);        // finds the first index of prefix in s
  if(pi == string::npos)
    return false;            // if index = -1 (not present or npos) return false

  int si = s.find(suf, pi+pre.size());    // find the first index of suffix in s after the prefix end in s
  if(si == string::npos)
    return false;            // if there is no suffic string after the prefix string return false
  
  return true;                      //both are present prefix and suffix so return true
}

int main(){
  string s = "leetcode", p = "ee*de";
  cout<<hasMatch(s, p);
}