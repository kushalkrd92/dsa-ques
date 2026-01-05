#include <iostream>
#include <vector>
using namespace std;

string removeSubstring(string s, string part){
  while(s.length() != 0 && s.find(part) < s.length()){
    s.erase(s.find(part), part.length());
  }
  return s;
}

int main(){
  string s, part;
  cout<<"Enter string and substring: ";
  cin>>s>>part;
  cout<<removeSubstring(s, part);
}