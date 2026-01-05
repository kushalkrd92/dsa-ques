#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int n){
  int ans = 0;

  while(n%10 == 0)      // handling the leading zeros ----> removing trailing zeros such that they don't become leading zeros
    n /= 10;

  while(n != 0){
    int digit = n%10;
    if(ans > (INT_MAX/10) || ans < (INT_MIN/10))
      return 0;
    ans = ans*10 + digit;
    n /= 10;
  }
  return ans;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<reverse(n);
  return 0;
}