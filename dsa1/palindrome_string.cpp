#include <iostream>
#include <string.h>      // strlen()
using namespace std;

bool checkPalindrome(char ch[]){
  int i = 0;
  int j = strlen(ch) - 1;
  while(i < j){
    if(ch[i] != ch[j])
      return false;
    i++;
    j--;
  }
  return true;
}

bool checkPalindrome2(string str){
  int i = 0;
  int j = str.size() - 1;
  while(i < j){
    if(str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int main(){
  char ch[20];
  cout<<"Enter String: ";
  cin>>ch;

  string s;
  cout<<"Enter another string: ";
  cin >> s;
  cout<<checkPalindrome(ch)<<endl;
  cout<<checkPalindrome2(s)<<endl;
  return 0;
}