#include <iostream>
#include <vector>
using namespace std;

vector<int> generateFibonacciNumbers(int n) {
  if(n == 1)
    return {0};
  if(n == 0)
    return {};
  vector<int> ans;
  int prev1 = 1;
  int prev2 = 0;
  ans.push_back(prev2);
  ans.push_back(prev1);
  for(int i = 2; i <= n; i++){
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
    ans.push_back(prev1);
  }
  return ans;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  vector<int> ans = generateFibonacciNumbers(n);
  for(int i: ans)
    cout<<i<<" ";
  return 0;
}