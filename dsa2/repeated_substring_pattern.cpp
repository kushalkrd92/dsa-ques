#include <iostream>
using namespace std;

// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
bool repeatedSubstringPattern(string s) {
  string doubled = s + s;       // Concatenate string s with itself
  string sub = doubled.substr(1, doubled.size() - 2);   // Remove first & last char from concatenated string and check if the original string s still is present
  return sub.find(s) != string::npos;      // Return True if the string is present
}

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  cout<<repeatedSubstringPattern(str);
  return 0;
}