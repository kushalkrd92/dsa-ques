#include <iostream>
using namespace std;

int permutationDiff(string s, string t){
  int freq[26] = {};
  int ans = 0;
  for(int i = 0; i<s.size(); i++)
    freq[s[i] - 'a'] = i;
  for(int i = 0; i<s.size(); i++)
    ans += abs(freq[t[i] - 'a'] - i);
  return ans;
}

int main(){
  string s, t;       // same length, same chars
  cout<<"Enter two permutations in lower cases: ";
  cin>>s>>t;
  cout<<permutationDiff(s, t);
  return 0;
}