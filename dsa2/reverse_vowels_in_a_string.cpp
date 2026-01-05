#include <iostream>
using namespace std;

string reverseVowels(string &str){
  int i = 0, j = str.length() - 1;
  string vowels = "aeiouAEIOU";
  while(i<j){                     // Move the start pointer forward and move the end pointer backward until a vowel is found
    while(i<j && (vowels.find(str[i]) == string::npos))
      i++;
    while(i<j && (vowels.find(str[j]) == string::npos))
      j--;
    swap(str[i], str[j]);         // here both pointers point to vowels
    i++;
    j--;
  }
  return str;
}

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  cout<<reverseVowels(str);
  // cout<<str;
  return 0;
}