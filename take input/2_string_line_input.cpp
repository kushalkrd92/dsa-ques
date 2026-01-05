#include <iostream>
#include <vector>
using namespace std;


// only valid when elements lie from 0-9
int main(){
  vector<int> arr;
  string s;
  cout<<"Enter string: ";
  getline(cin, s);

  for(char ch: s){
    if(isdigit(ch)){
      int num = ch - '0';
      arr.push_back(num);
    }
  }

  for(int i: arr)
    cout<<i<<" ";
  return 0;
}