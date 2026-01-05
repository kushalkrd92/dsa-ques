#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeAdjDuplicates(string s){
  stack<int> st;
  for(int i = 0; i<s.length(); i++){
    if(st.empty() || st.top() != s[i])
      st.push(s[i]);
    else if (st.top() == s[i])
      st.pop();
  }

  string ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  string s;
  cout<<"Enter string: ";
  cin>>s;
  cout<<removeAdjDuplicates(s);
  return 0;
}