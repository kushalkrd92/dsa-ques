#include <iostream>
using namespace std;

string toUpper(string str){
  string temp;
  for(char ch: str)
    temp.push_back((char)toupper(ch));
  return temp;
}

string toLower(string str){
  string temp;
  for(char ch: str)
    temp.push_back((char)tolower(ch));
  return temp;
}

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  
  // cout<<(char)toupper('a');
  // char ch = toupper('b');
  // cout<<ch;
  // cout<<tolower('A');

  cout<<toUpper(str)<<endl;
  cout<<toLower(str)<<endl;
  return 0;
}