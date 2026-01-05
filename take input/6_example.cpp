#include <iostream>
#include <vector>
using namespace std;

// comma separated elements then size
int main(){
  string line;
  getline(cin, line);
  line.erase(line.size()-1, line.size());
  // cout<<line;

  //
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