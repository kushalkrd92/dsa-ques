#include <iostream>
#include <unordered_map>
using namespace std;

// finds the first non-repeating character and return its index. If it does not exist, return -1
int uniqueChar(string str){
  unordered_map<char, int> mp;
  for(char ch: str)
    mp[ch]++;
  for(int i = 0; i <= str.size(); i++){
    if(mp[str[i]] == 1)
      return i;
  }
  return -1;
}

// finds the first non-repeating character and returns it. If it does not exist, return #.
char uniqueChar2(string str){
  unordered_map<char, int> mp;
  for(char ch: str)
    mp[ch]++;
  for(int i = 0; i <= str.size(); i++){
    if(mp[str[i]] == 1)
      return str[i];
  }
  return '#';
}

// finds the first non-repeating character and return its index. If it does not exist, return -1, use 1 index format.
int uniqueChar3(string str){
  unordered_map<char, int> mp;
  for(char ch: str)
    mp[ch]++;
  for(int i = 0; i <= str.size(); i++){
    if(mp[str[i]] == 1)
      return i+1;
  }
  return -1;
}

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  cout<<"Index: "<<uniqueChar(str)<<endl;
  cout<<"Char: "<<uniqueChar2(str)<<endl;
  cout<<"Index for 1: "<<uniqueChar3(str)<<endl;
  return 0;
}