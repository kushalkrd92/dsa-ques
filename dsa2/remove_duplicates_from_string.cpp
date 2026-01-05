#include <iostream>
#include <unordered_map>
#include <string.h>
#include <unordered_set>
using namespace std;

// remove repeated elements from the char array in place and return resultant char array, only valid when they are in sorted order
char* removeDuplicates(char* str){
  int i = 0;
  for(int j = 1; str[j] != '\0'; j++){
    if(str[i] != str[j]){
      i++;
      str[i] = str[j];
    }
  }
  str[i+1] = '\0';
  return str;
}

// remove all the duplicate occurrences of characters in the string consisting of only the lower case English alphabet, return the resultant string
string removeDuplicates2(string str){
  unordered_set<int> s;
  string ans;
  for(char ch: str){
    if(s.find(ch) == s.end()){
      s.insert(ch);
      ans.push_back(ch);
    }
  }
  return ans;
}

// remove all the duplicate occurrences of characters in the string consisting of only the lower case English alphabet, return the resultant string, in place
string removeDuplicates3(string str){
  int freq[26] = {0};    // freq for each char corresponding to their indexes
  string ans;
  for(int i = 0; i<str.length(); i++){
    char ch = str[i];
    if(freq[ch - 'a'] == 0){
      freq[ch - 'a']++;
      ans.push_back(ch);
    }
  }
  return ans;
}

int main(){
  char str[20];
  cout<<"Enter string: ";
  cin>>str;
  cout<<removeDuplicates(str)<<endl;
  cout<<removeDuplicates2(str)<<endl;
  cout<<removeDuplicates3(str)<<endl;
  return 0;
}