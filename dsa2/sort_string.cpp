#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string str;
  cout<<"Enter string: ";
  cin>>str;
  sort(str.begin(), str.end());
  cout<<str;
  return 0;
}