#include <iostream>
using namespace std;

int main(){
  string str;
  cout<<"Enter a number: ";
  cin>>str;
  cout<<str<<endl;

  // removing leading zeros
  int i = 0;
  while(str[i] == '0')
    i++;
  str.erase(0, i);
  cout<<str<<endl;

  // removing trailing zeros
  i = str.length() - 1;
  while(str[i] == '0' && i >= 0)
    i--;
  // str.erase(i+1, str.length());
  str = str.substr(0, i+1);
  cout<<str;
  
  return 0;
}