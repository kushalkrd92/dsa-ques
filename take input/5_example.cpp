#include <iostream>
#include <vector>
using namespace std;

// size, elements
int main(){
  string line;
  cin>>line;

  int n = line[0];
  vector<int> arr;
  line.erase(0, 2);      // one for n, one for comma
  for(char ch: line)
    arr.push_back(ch - '0');

  for(int i: arr)
    cout<<i<<" ";
  return 0;
}