#include <iostream>
using namespace std;

// return trailing zeros in factorial of a number
// 10 = 2*5
// so count the number of 5 factors of n 
int trailingZeroes(int n) {
  int count = 0;
  while(n>0){
    count += n/5;
    n /= 5;
  }
  return count;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<trailingZeroes(n);
}