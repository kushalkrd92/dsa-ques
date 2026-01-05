#include <iostream>
using namespace std;

int clumsy(int n) {
  int sign = 1;
  long long ans = 0;
  for(int i = n; i > 0; i -= 4){
    long long temp = i;
    if(i-1 > 0)
      temp *= i-1;
    if(i-2 > 0)
      temp /= i-2;
    ans += sign*temp;
    if(i-3 > 0)
      ans += i-3;
    sign = -1;
  }
  return (int)ans;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<clumsy(n);
}