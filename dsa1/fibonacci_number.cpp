#include <iostream>
using namespace std;

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).
int fib(int n){
  int prev1 = 1;
  int prev2 = 0;
  for(int i = 2; i <= n; i++){
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}

bool checkFib(int n){
  if(n == 0 || n == 1 || n == 2)
    return true;
  int prev1 = 1;
  int prev2 = 0;
  for(int i = 2; i <= n; i++){
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
    if(prev1 == n)
      return true;
  }
  return false;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<fib(n)<<endl;
  cout<<checkFib(n)<<endl;
  return 0;
}
