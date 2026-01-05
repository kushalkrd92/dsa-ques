#include <iostream>
#include <algorithm>
using namespace std;

// Return a string of the words in reverse order concatenated by a single space
string reverseWords(string &str){
  string ans = "", temp = "";
  for(int i = str.length()-1; i >= 0; i--){          // this will automatically remove extra leading and trailing whitespaces
    if(str[i] != ' ')
      temp.push_back(str[i]);
    else if(str[i] == ' ' && temp.length() != 0){
      reverse(temp.begin(), temp.end());
      ans += " " + temp;
      temp = "";
    }
    if(temp.length() != 0 && i == 0){        // for first word of str     // has to make it 'if'
      reverse(temp.begin(), temp.end());
      ans += " " + temp;
    }
  }
  ans.erase(0, 1);       // removing the leading whitespace
  return ans;
}

// reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
string reverseWords2(string &str){
  string ans = "", temp = "";
  for(int i = 0; i < str.size(); i++){          // this will automatically remove extra leading and trailing whitespaces
    if(str[i] != ' ')
      temp.push_back(str[i]);
    else if(str[i] == ' ' && temp.length() != 0){
      reverse(temp.begin(), temp.end());
      ans += " " + temp;
      temp = "";
    }
    if(temp.length() != 0 && i == str.size()-1){        // for first word of str     // has to make it 'if'
      reverse(temp.begin(), temp.end());
      ans += " " + temp;
    }
  }
  ans.erase(0, 1);       // removing the leading whitespace
  return ans;
}

int main(){
  string str;
  cout<<"Enter string: ";
  getline(cin, str);         // for line input
  cout<<reverseWords(str)<<endl;
  cout<<reverseWords2(str);
  return 0;
}