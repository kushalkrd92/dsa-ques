#include <iostream>
#include <vector>
using namespace std;

int main(){
  int num;
  vector<int> arr;
  // Read integers until a non-integer is entered or EOF is reached    // End-Of-File
  while(cin >> num)
    arr.push_back(num);

  for(int i: arr)
    cout<<i<<" ";
  return 0;
}