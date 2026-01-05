#include <iostream>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
string sortChars(string s){
  unordered_map<char, int> mp;         // char, freq
  for(char ch: s)
    mp[ch]++;

  priority_queue<pair<int, char>> pq;       // max heap // freq, char
  for(char ch: s)
    pq.push({mp[ch], ch});

  string ans = "";
  while(!pq.empty()){
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}

int main(){
  string s = "treeaapa";
  cout<<sortChars(s)<<endl;
  return 0;
}