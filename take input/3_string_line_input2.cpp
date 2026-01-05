#include <iostream>
#include <vector>
using namespace std;

int main(){
  string line;
  cout<<"Enter string: ";
  getline(cin, line);

  vector<int> arr;
  string numStr = "";
  for(char ch: line){
    if(isdigit(ch))
      numStr.push_back(ch);
    else if(!isdigit(ch) && !numStr.empty()){
      arr.push_back(stoi(numStr));
      numStr = "";
    }
  }
  if(!numStr.empty())       // to handle last digit
    arr.push_back(stoi(numStr));
  
  for(int i: arr)
    cout<<i<<" ";
  return 0;
}