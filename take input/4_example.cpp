#include <iostream>
#include <vector>
using namespace std;

// size elements
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }

  for(int i: arr)
    cout<<i<<" ";
  return 0;
}